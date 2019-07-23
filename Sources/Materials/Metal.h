#pragma once

#include "Material.h"
#include "../Maths/Random.h"

class Metal : public Material
{
public:
	Metal(const Vec3& a, float f) : albedo(a), mRandom(0.0f, 1.0f)
	{
		if (f < 1)
			fuzz = f;
		else
			fuzz = 1;
	}

	bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) override
	{
		Vec3 reflected = Vec3::reflect(Vec3::unitVector(rIn.direction()), rec.normal);
		scattered = Ray(rec.p, reflected + fuzz * mRandom.randomInUnitSphere(), rIn.time());
		attenuation = albedo;
		return (Vec3::dot(scattered.direction(), rec.normal) > 0);
	}

	Vec3 albedo;
	float fuzz;

private:
	Random mRandom;
};