#pragma once

#include "Vec3.h"

class Ray
{
public:
	Ray() {}
	Ray(const Vec3& a, const Vec3& b, float ti = 0.0f) { this->a = a; this->b = b; this->mTime = ti; }
	const Vec3& origin() const { return a; }
	const Vec3& direction() const { return b; }
	float		time() const { return mTime; }
	Vec3 pointAtParameter(float t) const { return a + t * b; }

	Vec3 a;
	Vec3 b;

private:
	float mTime;
};
