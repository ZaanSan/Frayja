#include "NoiseTexture.h"

NoiseTexture::NoiseTexture() = default;

NoiseTexture::NoiseTexture(float sc)
	: scale(sc)
{
}

Vec3 NoiseTexture::value(float u, float v, const Vec3& p) const
{
	//return Vec3(1.0f, 1.0f, 1.0f)* noise.noise(scale * p);
	//return Vec3(1.0f, 1.0f, 1.0f)* noise.turb(scale * p);
	return Vec3(1.0f, 1.0f, 1.0f) * 0.5f * (1 + sin(scale*p.z() + 10*noise.turb(p)));
}
