#pragma once

#include "Hitable.h"

class MovingSphere : public Hitable
{
public:
	MovingSphere();
	MovingSphere(const Vec3& cen0, const Vec3& cen1, float t0, float t1, float r, Material* m);
	bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
	bool boundingBox(float t0, float t1, AABB& box) const override;

private:
	Vec3 center(float time) const;

public:
	Vec3 center0, center1;
	float time0, time1;
	float radius;
	Material* mat;
};