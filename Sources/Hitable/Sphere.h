#pragma once

#include "Hitable.h"

class Sphere : public Hitable
{
public:
	Sphere();
	Sphere(const Vec3& cen, float r, Material* m);
	bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;

	Vec3 center;
	float radius;
	Material* mat;
};