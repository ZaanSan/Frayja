#include "ConstantTexture.h"

ConstantTexture::ConstantTexture() = default;

ConstantTexture::ConstantTexture(const Vec3& c)
	: color(c)
{
}

Vec3 ConstantTexture::value(float u, float v, const Vec3& p) const
{
	return color;
}
