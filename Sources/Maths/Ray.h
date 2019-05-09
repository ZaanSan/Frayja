#pragma once

#include "Vec3.h"

class Ray
{
public:
	Ray() {}
	Ray(const Vec3& a, const Vec3& b) { this->a = a; this->b = b; }
	const Vec3& origin() const { return a; }
	const Vec3& direction() const { return b; }
	Vec3 pointAtParameter(float t) const { return a + t * b; }

	Vec3 a;
	Vec3 b;
};
