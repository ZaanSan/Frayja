#include "Sphere.h"

Sphere::Sphere()
	: center(0.0f),
	radius(0.0f),
	mat(nullptr)
{
}

Sphere::Sphere(const Vec3& cen, float r, Material* m)
	: center(cen),
	radius(r),
	mat(m)
{
}

bool Sphere::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const
{
	Vec3 oc = r.origin() - center;
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
			rec.normal = (rec.p - center) / radius;
			rec.matPtr = mat;
			return true;
		}
		tmp = (-b + sqrtDisc) / a;
		if (tmp < tMax && tmp > tMin)
		{
			rec.t = tmp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.matPtr = mat;
			return true;
		}
	}
	return false;
}

bool Sphere::boundingBox(float t0, float t1, AABB& box) const
{
	box = AABB(center - Vec3(radius), center + Vec3(radius));
	return true;
}
