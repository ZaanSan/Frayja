#pragma once

#include "Material.h"
#include "../Maths/Random.h"
#include "../Texture/Texture.h"

class Lambertian : public Material
{
public:
	Lambertian(Texture* a) : albedo(a), mRandom(0.0f, 1.0f) {}
	
	~Lambertian() { delete albedo; }

	bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) override
	{
		Vec3 target = rec.normal + mRandom.randomInUnitSphere();
		scattered = Ray(rec.p, target, rIn.time());
		attenuation = albedo->value(0, 0, rec.p);
		return true;
	}

	Texture* albedo;

private:
	Random mRandom;
};