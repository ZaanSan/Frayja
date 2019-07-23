#pragma once

#include "Texture.h"
#include "Perlin.h"

class NoiseTexture : public Texture
{
public:
	NoiseTexture();
	NoiseTexture(float sc);
	Vec3 value(float u, float v, const Vec3& p) const override;

public:
	Perlin noise;
	float scale;
};