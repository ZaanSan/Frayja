#pragma once

#include "../Maths/Vec3.h"
#include "../Maths/Ray.h"

class AABB {
public:
	AABB();
	AABB(const Vec3& a, const Vec3& b);

	Vec3 min() const;
	Vec3 max() const;

	bool hit(const Ray& r, float tmin, float tmax) const;
	
	static AABB surroundingBox(const AABB& box0, const AABB& box1);

private:
	Vec3 mMin, mMax;
};