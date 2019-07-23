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

bool HitableList::boundingBox(float t0, float t1, AABB& box) const
{
	if (listSize < 1) return false;
	AABB tmpBox;
	bool firstTrue = list[0]->boundingBox(t0, t1, tmpBox);
	if (!firstTrue)
		return false;
	else
		box = tmpBox;
	for (int i = 1; i < listSize; i++) 
	{
		if (list[i]->boundingBox(t0, t1, tmpBox))
		{
			box = AABB::surroundingBox(box, tmpBox);
		}
		else
			return false;
	}
	return true;
}
