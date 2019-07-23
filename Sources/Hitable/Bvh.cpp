#include "Bvh.h"

#include <QDebug>

BvhNode::BvhNode()
	: mRandom(0.0f, 1.0f)
{

}

int boxXCompare(const void* a, const void* b)
{
	AABB boxLeft, boxRight;
	Hitable* ah = *(Hitable * *)a;
	Hitable* bh = *(Hitable * *)b;
	if(!ah->boundingBox(0, 0, boxLeft) || !bh->boundingBox(0, 0, boxRight))
		qDebug() << "No bounding box in BvhNode constructor";
	if (boxLeft.min().x() - boxRight.min().x() < 0.0f)
		return -1;
	else
		return 1;
}

int boxYCompare(const void* a, const void* b)
{
	AABB boxLeft, boxRight;
	Hitable* ah = *(Hitable * *)a;
	Hitable* bh = *(Hitable * *)b;
	if (!ah->boundingBox(0, 0, boxLeft) || !bh->boundingBox(0, 0, boxRight))
		qDebug() << "No bounding box in BvhNode constructor";
	if (boxLeft.min().y() - boxRight.min().y() < 0.0f)
		return -1;
	else
		return 1;
}

int boxZCompare(const void* a, const void* b)
{
	AABB boxLeft, boxRight;
	Hitable* ah = *(Hitable * *)a;
	Hitable* bh = *(Hitable * *)b;
	if (!ah->boundingBox(0, 0, boxLeft) || !bh->boundingBox(0, 0, boxRight))
		qDebug() << "No bounding box in BvhNode constructor";
	if (boxLeft.min().z() - boxRight.min().z() < 0.0f)
		return -1;
	else
		return 1;
}

BvhNode::BvhNode(Hitable** l, int n, float time0, float time1)
	: mRandom(0.0f, 1.0f)
{
	int axis = int(3 * mRandom.generateNumber());
	if (axis == 0)
		qsort(l, n, sizeof(Hitable*), boxXCompare);
	else if (axis == 1)
		qsort(l, n, sizeof(Hitable*), boxYCompare);
	else
		qsort(l, n, sizeof(Hitable*), boxZCompare);
	if (n == 1)
	{
		left = right = l[0];
	}
	else if (n == 2)
	{
		left = l[0];
		right = l[1];
	}
	else
	{
		left = new BvhNode(l, n / 2, time0, time1);
		right = new BvhNode(l + n / 2, n - n / 2, time0, time1);
	}
	AABB boxLeft, boxRight;
	if (!left->boundingBox(time0, time1, boxLeft) || !right->boundingBox(time0, time1, boxRight))
		qDebug() << "No bounding box in BvhNode constructor";
	box = AABB::surroundingBox(boxLeft, boxRight);
}

bool BvhNode::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const
{
	if (box.hit(r, tMin, tMax))
	{
		HitRecord leftRec, rightRec;
		bool hitLeft = left->hit(r, tMin, tMax, leftRec);
		bool hitRight = right->hit(r, tMin, tMax, rightRec);
		if (hitLeft && hitRight)
		{
			if (leftRec.t < rightRec.t)
				rec = leftRec;
			else
				rec = rightRec;
			return true;
		}
		else if (hitLeft)
		{
			rec = leftRec;
			return true;
		}
		else if (hitRight)
		{
			rec = rightRec;
			return true;
		}
		else
			return false;
	}
	return false;
}

bool BvhNode::boundingBox(float t0, float t1, AABB& b) const
{
	b = box;
	return true;
}

