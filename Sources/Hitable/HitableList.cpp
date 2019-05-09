#include "HitableList.h"

HitableList::HitableList()
	: list(nullptr),
	listSize(0)
{
}

HitableList::HitableList(Hitable** l, int n)
	: list(l),
	listSize(n)
{
}

bool HitableList::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const
{
	HitRecord tmpRec;
	bool hitAnything = false;
	double closestSoFar = tMax;
	for (int i = 0; i < listSize; i++)
	{
		if (list[i]->hit(r, tMin, closestSoFar, tmpRec))
		{
			hitAnything = true;
			closestSoFar = tmpRec.t;
			rec = tmpRec;
		}
	}
	return hitAnything;
}
