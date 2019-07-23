#include "AABB.h"

AABB::AABB() = default;

AABB::AABB(const Vec3& a, const Vec3& b)
	: mMin(a),
	mMax(b)
{}

Vec3 AABB::min() const
{
	return mMin;
}

Vec3 AABB::max() const
{
	return mMax;
}

bool AABB::hit(const Ray& r, float tmin, float tmax) const
{
	for (int a = 0; a < 3; a++)
	{
		float invD = 1.0f / r.direction()[a];
		float t0 = (min()[a] - r.origin()[a]) * invD;
		float t1 = (max()[a] - r.origin()[a]) * invD;
		if (invD < 0.0f)
			std::swap(t0, t1);
		tmin = t0 > tmin ? t0 : tmin;
		tmax = t1 < tmax ? t1 : tmax;
		if (tmax <= tmin)
			return false;
	}
	return true;
}

AABB AABB::surroundingBox(const AABB& box0, const AABB& box1)
{
	Vec3 small(fmin(box0.min().x(), box1.min().x()),
		fmin(box0.min().y(), box1.min().y()),
		fmin(box0.min().z(), box1.min().z()));
	Vec3 big(fmax(box0.max().x(), box1.max().x()),
		fmax(box0.max().y(), box1.max().y()),
		fmax(box0.max().z(), box1.max().z()));
	return AABB(small, big);
}
