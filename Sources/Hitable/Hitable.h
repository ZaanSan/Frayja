#pragma once

#include "AABB.h"

class Material;

struct HitRecord {
	float t;
	Vec3 p;
	Vec3 normal;
	Material* matPtr;
};

class Hitable {
public:
	virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;
	virtual bool boundingBox(float t0, float t1, AABB& box) const = 0;
};