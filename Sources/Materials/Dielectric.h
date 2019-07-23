#pragma once

#include "Material.h"

class Dielectric : public Material
{
public:
	Dielectric(float ri) : refNdx(ri), mRandom(0.0f, 1.0f) {}

	bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) override
	{
		Vec3 outwardNormal;
		Vec3 reflected = Vec3::reflect(rIn.direction(), rec.normal);
		float niOverNt;
		attenuation = Vec3(1.0f, 1.0f, 1.0f);
		Vec3 refracted;
		float reflectProb;
		float cosine;
		if (Vec3::dot(rIn.direction(), rec.normal) > 0)
		{
			outwardNormal = -rec.normal;
			niOverNt = refNdx;
			cosine = refNdx * Vec3::dot(rIn.direction(), rec.normal) / rIn.direction().length();
		}
		else
		{
			outwardNormal = rec.normal;
			niOverNt = 1.0f / refNdx;
			cosine = -Vec3::dot(rIn.direction(), rec.normal) / rIn.direction().length();
		}
		if (refract(rIn.direction(), outwardNormal, niOverNt, refracted))
		{
			reflectProb = schlick(cosine, refNdx);
		}
		else
		{
			reflectProb = 1.0f;
		}
		if (mRandom.generateNumber() < reflectProb)
		{
			scattered = Ray(rec.p, reflected, rIn.time());
		}
		else
		{
			scattered = Ray(rec.p, refracted, rIn.time());
		}
		return true;
	}

	float refNdx;

private:
	Random mRandom;

	// Snell's law
	bool	refract(const Vec3& v, const Vec3& n, float niOverNt, Vec3& refracted)
	{
		Vec3 uv = Vec3::unitVector(v);
		float dt = Vec3::dot(uv, n);
		float discriminant = 1.0f - niOverNt * niOverNt * (1.0f - dt * dt);
		if (discriminant > 0)
		{
			refracted = niOverNt * (uv - n * dt) - n * std::sqrt(discriminant);
			return true;
		}
		else
			return false;
	}

	// Varies reflectivity with angles (like real life => look at a window at a steep angle and it becomes a mirror)
	// Cristophe Schlick approximation
	float schlick(float cosine, float refNdx)
	{
		float r0 = (1.0f - refNdx) / (1 + refNdx);
		r0 *= r0;
		return r0 + (1.0f - r0) * std::pow((1 - cosine), 5);
	}
};