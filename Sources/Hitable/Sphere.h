#pragma once

#include "Hitable.h"

class Sphere : public Hitable
{
public:
	Sphere();
	Sphere(const Vec3& cen, float r, Material* m);
	bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
	bool boundingBox(float t0, float t1, AABB& box) const override;

	Vec3 center;
	float radius;
	Material* mat;
};