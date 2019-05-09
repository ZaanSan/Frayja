#pragma once

#include <string>
#include <vector>
#include <map>

#include <QXmlStreamReader>
#include <QFile>

#include "FrayjaConfiguration.h"

#include "../Camera/Camera.h"

#include "../Materials/Lambertian.h"
#include "../Materials/Metal.h"
#include "../Materials/Dielectric.h"

#include "../Hitable/Sphere.h"
#include "../Hitable/HitableList.h"

class Scene
{
public:
	Scene();
	~Scene();

	bool							loadScene(const std::string& path);
	const Hitable*					getObjects() const;
	const std::vector<Material*>	getMaterials() const;
	int								getNbObjects() const;
	int								getNbMaterials() const;
	std::string						getFileName() const;

	// Functions used for GUI, the camera will be built by the engine
	// The engine will get camera configuration from the UI.
	bool							hasCameraConfiguration() const;
	const CameraConfiguration&		getCameraConfiguration() const;

private:
	CameraConfiguration		mCameraConf;
	std::vector<Hitable*>	mHitables;
	std::vector<Material*>	mMaterials;
	HitableList*			mWorld;
	std::string				mFile;

	// Internal use
	QXmlStreamReader				 mReader;
	std::map<std::string, Material*> mMatsMap;

	bool mIsScene;
	bool mHasCamConf;

private:
	void	resetData();

	void	parseCamera();
	void	parseMaterials();
	void	parseObject();

	void	parseSphere();
	void	parseLambertian();
	void	parseMetal();
	void	parseDielectric();

	void	parseVec3(Vec3& v);
	void	parseFloat(float& v);
	void	parseAttrString(const QString& attr, std::string& v);

	void	addMaterial(const std::string& name, Material* mat);
	void	generateHitableList();

};