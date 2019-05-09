#include "Frayja.h"

#include "../Hitable/Sphere.h"
#include "../Hitable/HitableList.h"
#include "../Camera/Camera.h"
#include "../Materials/Lambertian.h"
#include "../Materials/Metal.h"
#include "../Materials/Dielectric.h"

#include <iostream>
#include <fstream>
#include <QDebug>

Frayja::Frayja(FrayjaEventEmitter& emitter)
	: mEmitter(emitter),
	mConfiguration(),
	mScene(nullptr),
	mRandom(0.0f, 1.0f),
	mCamera(nullptr),
	mWorld(nullptr)
{
}

Frayja::~Frayja()
{
}

Hitable* randomScene() {
	Random random(0.0f, 1.0f);

	int n = 500;
	Hitable** list = new Hitable*[n + 1.0];

	list[0] = new Sphere(Vec3(0, -1000, 0), 1000, new Lambertian(Vec3(0.5, 0.5, 0.5)));
	int i = 1;
	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			float chooseMat = random.generateNumber();
			Vec3 center(
				a + 0.9 * random.generateNumber(),
				0.2,
				b + 0.9 * random.generateNumber()
			);

			if ((center - Vec3(4, 0.2, 0)).length() > 0.9)
			{
				if (chooseMat < 0.8) // diffuse
				{
					list[i++] = new Sphere(center, 0.2, new Lambertian(Vec3(
						random.generateNumber() * random.generateNumber(),
						random.generateNumber() * random.generateNumber(),
						random.generateNumber() * random.generateNumber()
					)));
				}
				else if (chooseMat < 0.95) // metal
				{
					list[i++] = new Sphere(center, 0.2, new Metal(
						Vec3(
							0.5f * (1.0f + random.generateNumber()),
							0.5f * (1.0f + random.generateNumber()),
							0.5f * (1.0f + random.generateNumber())),
						0.5 * random.generateNumber()
					));
				}
				else // glass
				{
					list[i++] = new Sphere(center, 0.2, new Dielectric(1.5));
				}
			}
		}
	}

	list[i++] = new Sphere(Vec3(0, 1, 0), 1.0, new Dielectric(1.5));
	list[i++] = new Sphere(Vec3(-4, 1, 0), 1.0, new Lambertian(Vec3(0.4, 0.2, 0.1)));
	list[i++] = new Sphere(Vec3(4, 1, 0), 1.0, new Metal(Vec3(0.7, 0.6, 0.5), 0.0));

	return new HitableList(list, i);
}

void Frayja::setConfiguration(FrayjaConfiguration conf)
{
	mConfiguration = conf;
}

void Frayja::setScene(Scene* scene)
{
	mScene = scene;
}

void Frayja::initRendering()
{
	mCamera = new Camera(
		mConfiguration.camera.position,
		mConfiguration.camera.direction,
		Vec3(0.0f, 1.0f, 0.0f),
		mConfiguration.camera.fov,
		float(mConfiguration.general.width) / float(mConfiguration.general.height),
		mConfiguration.camera.aperture,
		mConfiguration.camera.distToFocus
	);

	mWorld = (Hitable*)mScene->getObjects();
}

void Frayja::endRendering()
{
	if (mCamera)
		delete mCamera;
	mWorld = nullptr;
}

void Frayja::render(int x, int y) const
{
	Random random(0.0f, 1.0f);
	int nx = mConfiguration.general.width;
	int ny = mConfiguration.general.height;
	int ns = mConfiguration.general.aaSamples;
	// Convention : (0, 0 is lowerLeft)
	int mirrorY = ny - y;
	Vec3 col;

	for (int s = 0; s < ns; s++)
	{
		float ran = random.generateNumber();
		float u = float(x + ran) / float(nx);
		ran = random.generateNumber();
		float v = float(mirrorY + ran) / float(ny);
		Ray r = mCamera->getRay(u, v);
		col += color(r, mWorld, 0);
	}
	col /= float(ns);
	// Pseudo gamma correction
	col = Vec3(std::sqrt(col[0]), std::sqrt(col[1]), std::sqrt(col[2]));
	int ir = int(255.99 * col[0]);
	int ig = int(255.99 * col[1]);
	int ib = int(255.99 * col[2]);
	mEmitter.pixelRenderedEvent(x, y, Vec3(ir, ig, ib));

}

Vec3 Frayja::color(const Ray& ray, const Hitable* world, int depth) const
{
	HitRecord rec;
	int maxDepth = mConfiguration.general.depth;
	if (world->hit(ray, 0.001, FLT_MAX, rec))
	{
		Ray scattered;
		Vec3 attenuation;
		if (depth < maxDepth && rec.matPtr->scatter(ray, rec, attenuation, scattered))
		{
			return attenuation * color(scattered, world, depth + 1);
		}
		else
		{
			return Vec3(0, 0, 0);
		}
	}
	else
	{
		Vec3 unitDirection = Vec3::unitVector(ray.direction());
		float t = 0.5 * (unitDirection.y() + 1.0);
		Vec3 le = Vec3::lerp(Vec3(1.0, 1.0, 1.0), Vec3(0.5, 0.7, 1.0), t);
		return le;
	}
}
