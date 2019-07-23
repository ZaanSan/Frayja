#include "MovingSphere.h"

MovingSphere::MovingSphere() = default;

MovingSphere::MovingSphere(const Vec3& cen0, const Vec3& cen1, float t0, float t1, float r, Material* m)
	: center0(cen0),
	center1(cen1),
	time0(t0),
	time1(t1),
	radius(r),
	mat(m)
{
}

bool MovingSphere::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const
{
	Vec3 oc = r.origin() - center(r.time());
	const Vec3& dir = r.direction();
	float a = Vec3::dot(dir, dir);
	float b = Vec3::dot(dir, oc);
	float c = Vec3::dot(oc, oc) - radius * radius;
	float discriminant = b * b - a * c;
	if (discriminant > 0)
	{
		float sqrtDisc = std::sqrt(discriminant);
		float tmp = (-b - sqrtDisc) / a;
		if (tmp < tMax && tmp > tMin)
		{
			rec.t = tmp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center(r.time())) / radius;
			rec.matPtr = mat;
			return true;
		}
		tmp = (-b + sqrtDisc) / a;
		if (tmp < tMax && tmp > tMin)
		{
			rec.t = tmp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center(r.time())) / radius;
			rec.matPtr = mat;
			return true;
		}
	}
	return false;
}

bool MovingSphere::boundingBox(float t0, float t1, AABB& box) const
{
	box = AABB::surroundingBox(
		AABB(center0 - Vec3(radius), center0 + Vec3(radius)),
		AABB(center1 - Vec3(radius), center1 + Vec3(radius))
	);
	return true;
}

Vec3 MovingSphere::center(float time) const
{
	return center0 + ((time - time0) / (time1 - time0)) * (center1 - center0);
}
