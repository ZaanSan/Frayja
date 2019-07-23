#pragma once

#include "Texture.h"

class ConstantTexture : public Texture
{
public:
	ConstantTexture();
	ConstantTexture(const Vec3& c);
	Vec3 value(float u, float v, const Vec3& p) const override;

public:
	Vec3 color;
};