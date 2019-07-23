#pragma once

#include "../Maths/Ray.h"
#include "../Maths/Random.h"

class Camera {
public:
	Camera(const Vec3& lookFrom,
		const Vec3& lookAt,
		const Vec3& vUp,
		float vFov,              // vFov is top to bottom in degrees
		float aspect,
		float aperture,
		float focusDist,
		float t0, float t1) 
		: mRandom(0.0f, 1.0f)
	{
		time0 = t0;
		time1 = t1;
		lensRadius = aperture / 2.0f;
		float theta = vFov * M_PI / 180.0f;
		float halfHeight = std::tan(theta / 2.0f);
		float halfWidth = aspect * halfHeight;
		origin = lookFrom;
		w = Vec3::unitVector(lookFrom - lookAt);
		u = Vec3::unitVector(vUp.cross(w));
		v = w.cross(u);
		lowerLeftCorner = origin - halfWidth * focusDist * u - halfHeight * focusDist * v - focusDist * w;
		horizontal = 2.0f * halfWidth * focusDist * u;
		vertical = 2.0f * halfHeight * focusDist * v;
	}

	Ray getRay(float u, float v)
	{
		Vec3 rd = lensRadius * mRandom.randomInUnitDisk();
		Vec3 offset = u * rd.x() + v * rd.y();
		float time = time0 + mRandom.generateNumber() * (time1 - time0);
		return Ray(origin + offset, lowerLeftCorner + u * horizontal + v * vertical - origin - offset, time);
	}

public:
	Vec3 origin;
	Vec3 lowerLeftCorner;
	Vec3 horizontal;
	Vec3 vertical;
	Vec3 u, v, w;
	float time0, time1;
	float lensRadius;
	Random mRandom;
};