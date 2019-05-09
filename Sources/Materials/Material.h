#pragma once

#include "../Maths/Ray.h"
#include "../Maths/Vec3.h"
#include "../Hitable/Hitable.h"

class Material {
public:
	virtual bool scatter(const Ray& rIn, const HitRecord& rec, Vec3& attenuation, Ray& scattered) = 0;
};