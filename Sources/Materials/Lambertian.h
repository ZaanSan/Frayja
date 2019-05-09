#pragma once

#include "Material.h"
#include "../Maths/Random.h"

class Lambertian : public Material
{
public:
	Lambertian(const Vec3& a) : albedo(a), mRandom(0.0f, 1.0f) {}
	
	bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) override
	{
		Vec3 target = rec.normal + mRandom.randomInUnitSphere();
		scattered = Ray(rec.p, target);
		attenuation = albedo;
		return true;
	}

	Vec3 albedo;

private:
	Random mRandom;
};