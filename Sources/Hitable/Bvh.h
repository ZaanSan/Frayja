#pragma once

#include "Hitable.h"
#include "../Maths/Random.h"

class BvhNode : public Hitable {
public:
	BvhNode();
	BvhNode(Hitable** l, int n, float time0, float time1);
	bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;
	bool boundingBox(float t0, float t1, AABB& b) const override;

public:
	Hitable*	left;
	Hitable*	right;
	AABB		box;
	Random		mRandom;
};