#pragma once

#include "Hitable.h"

class HitableList : public Hitable {
public:
	HitableList();
	HitableList(Hitable** l, int n);
	bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;

	Hitable** list;
	int listSize;
};