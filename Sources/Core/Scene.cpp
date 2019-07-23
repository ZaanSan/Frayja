#include "Scene.h"

#include <QDebug>
#include "../Hitable/Bvh.h"
#include "../Texture/ConstantTexture.h"
#include "../Texture/CheckerTexture.h"
#include "../Texture/NoiseTexture.h"

Scene::Scene()
	: mCameraConf(),
	mHitables(),
	mMaterials(),
	mWorld(nullptr),
	mMatsMap(),
	mReader(),
	mIsScene(false),
	mHasCamConf(false)
{
}

Scene::~Scene()
{
	resetData();
}

bool Scene::loadScene(const std::string& path)
{
	if (mIsScene)
		resetData();
	mIsScene = true;
	QFile file(path.c_str());
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;
	mFile = path;
	mReader.setDevice(&file);
	
	if (mReader.readNextStartElement())
	{
		if (mReader.name() == "scene")
		{
			while (mReader.readNextStartElement())
			{
				if (mReader.name() == "camera")
				{
					parseCamera();
				}
				else if (mReader.name() == "materials")
				{
					parseMaterials();
				}
				else if (mReader.name() == "objects")
				{
					parseObject();
				}
				else
					mReader.skipCurrentElement();
			}
		}
		else
			return false;
	}
	generateHitableList();
	return true;
}

const Hitable*		Scene::getObjects() const
{
	return mWorld;
}

const std::vector<Material*> Scene::getMaterials() const
{
	return mMaterials;
}

int Scene::getNbObjects() const
{
	return mHitables.size();
}

int Scene::getNbMaterials() const
{
	return mMaterials.size();
}

std::string		Scene::getFileName() const
{
	return mFile;
}

bool Scene::hasCameraConfiguration() const
{
	return mHasCamConf;
}

const CameraConfiguration& Scene::getCameraConfiguration() const
{
	return mCameraConf;
}

void Scene::resetData()
{
	mHasCamConf = false;
	mIsScene = false;
	for (auto it = mHitables.begin(); it != mHitables.end(); ++it)
	{
		delete (*it);
	}	
	for (auto it = mMaterials.begin(); it != mMaterials.end(); ++it)
	{
		delete (*it);
	}
	delete mWorld;
	mHitables.clear();
	mMaterials.clear();
	mMatsMap.clear();
}

void Scene::generateHitableList()
{
	//mWorld = new HitableList(&mHitables[0], mHitables.size());
	qDebug() << mHitables.size();
	mWorld = new BvhNode(&mHitables[0], mHitables.size(), 0.0f, 1.0f);
}

#pragma region Camera

void Scene::parseCamera()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "camera");

	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "position")
		{
			parseVec3(mCameraConf.position);
		}
		else if (mReader.name() == "direction")
		{
			parseVec3(mCameraConf.direction);
		}
		else if (mReader.name() == "fov")
		{
			parseFloat(mCameraConf.fov);
		}
		else if (mReader.name() == "aperture")
		{
			parseFloat(mCameraConf.aperture);
		}
		else if (mReader.name() == "focusdist")
		{
			parseFloat(mCameraConf.distToFocus);
		}
		else
			mReader.skipCurrentElement();
	}
	mHasCamConf = true;
}

#pragma endregion

#pragma region Materials

void Scene::parseMaterials()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "materials");

	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "lambertian")
		{
			parseLambertian();
		}
		else if (mReader.name() == "metal")
		{
			parseMetal();
		}
		else if (mReader.name() == "dielectric")
		{
			parseDielectric();
		}
		else
			mReader.skipCurrentElement();
	}
}

void Scene::parseLambertian()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "lambertian");
	
	Texture* texture = nullptr;
	std::string name;

	parseAttrString("name", name);
	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "albedo")
		{
			Vec3 albedo;
			parseVec3(albedo);
			if (texture == nullptr)
				texture = new ConstantTexture(albedo);
		}
		else if (mReader.name() == "checker")
		{
			if (texture == nullptr)
				texture = parseChecker();
		}
		else if (mReader.name() == "noise")
		{
			//TODO : Fix this (don't need to parse float)
			float scale;
			parseFloat(scale);
			if (texture == nullptr)
				texture = new NoiseTexture(scale);
		}
		else
			mReader.skipCurrentElement();
	}
	addMaterial(name, new Lambertian(texture));
}

Texture* Scene::parseChecker()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "checker");

	Vec3 even, odd;

	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "even")
		{
			parseVec3(even);
		}
		else if (mReader.name() == "odd")
		{
			parseVec3(odd);
		}
		else
			mReader.skipCurrentElement();
	}
	return new CheckerTexture(new ConstantTexture(even), new ConstantTexture(odd));
}

void Scene::parseMetal()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "metal");
	
	std::string name;
	Vec3 albedo;
	float fuzz = 0.0f;

	parseAttrString("name", name);
	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "albedo")
		{
			parseVec3(albedo);
		}
		else if (mReader.name() == "fuzz")
		{
			parseFloat(fuzz);
		}
		else
			mReader.skipCurrentElement();
	}
	addMaterial(name, new Metal(albedo, fuzz));
}
 
void Scene::parseDielectric()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "dielectric");

	std::string name;
	float indice = 0.0f;

	parseAttrString("name", name);
	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "indice")
		{
			parseFloat(indice);
		}
		else
			mReader.skipCurrentElement();
	}
	addMaterial(name, new Dielectric(indice));
}

void Scene::addMaterial(const std::string& name, Material* mat)
{
	mMatsMap[name] = mat;
	mMaterials.emplace_back(mat);
}

#pragma endregion

#pragma region Objects

void Scene::parseObject()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "objects");
	
	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "sphere")
		{
			parseSphere();
		}
		else if (mReader.name() == "movingsphere")
		{
			parseMovingSphere();
		}
		else
			mReader.skipCurrentElement();
	}
}

void Scene::parseSphere()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "sphere");
	
	std::string material;
	Vec3 center;
	float radius = 0.0f;

	parseAttrString("material", material);
	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "center")
		{
			parseVec3(center);
		}
		else if (mReader.name() == "radius")
		{
			parseFloat(radius);
		}
		else
			mReader.skipCurrentElement();
	}
	if (mMatsMap[material])
	{
		mHitables.push_back(new Sphere(center, radius, mMatsMap[material]));
	}
	else
	{
		qDebug() << "Material not found";
	}
}

void Scene::parseMovingSphere()
{
	Q_ASSERT(mReader.isStartElement() && mReader.name() == "movingsphere");

	std::string material;
	Vec3 center0, center1;
	float t0, t1;
	float radius = 0.0f;

	parseAttrString("material", material);
	while (mReader.readNextStartElement())
	{
		if (mReader.name() == "center0")
		{
			parseVec3(center0);
		}
		else if (mReader.name() == "center1")
		{
			parseVec3(center1);
		}
		else if (mReader.name() == "t0")
		{
			parseFloat(t0);
		}
		else if (mReader.name() == "t1")
		{
			parseFloat(t1);
		}
		else if (mReader.name() == "radius")
		{
			parseFloat(radius);
		}
		else
			mReader.skipCurrentElement();
	}
	if (mMatsMap[material])
	{
		mHitables.push_back(new MovingSphere(center0, center1, t0, t1, radius, mMatsMap[material]));
	}
	else
	{
		qDebug() << "Material not found";
	}
}

#pragma endregion

#pragma region Primitive

void Scene::parseVec3(Vec3& v)
{
	QString str = mReader.readElementText();
	QStringList list = str.split(",");
	if (list.size() == 3)
	{
		v.e[0] = std::stof(list[0].toStdString());
		v.e[1] = std::stof(list[1].toStdString());
		v.e[2] = std::stof(list[2].toStdString());
	}
}

void Scene::parseFloat(float& v)
{
	v = std::stof(mReader.readElementText().toStdString());
}

void Scene::parseAttrString(const QString& attr, std::string& v)
{
	if (mReader.attributes().hasAttribute(attr))
	{
		v = mReader.attributes().value(attr).toString().toStdString();
	}
	else
		qDebug() << attr << " doesn't exist";
}

#pragma endregion