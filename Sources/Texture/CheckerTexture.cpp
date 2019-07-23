#include "CheckerTexture.h"

CheckerTexture::CheckerTexture() = default;

CheckerTexture::CheckerTexture(Texture* t0, Texture* t1)
	: even(t0), odd(t1)
{
}

CheckerTexture::~CheckerTexture()
{
	if (even)
		delete even;
	if (odd)
		delete odd;
}

Vec3 CheckerTexture::value(float u, float v, const Vec3& p) const
{
	float sines = sin(10 * p.x()) * sin(10 * p.y()) * sin(10 * p.z());
	if (sines < 0)
		return odd->value(u, v, p);
	else
		return even->value(u, v, p);
}
