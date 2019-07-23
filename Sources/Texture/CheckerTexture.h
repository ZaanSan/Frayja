#pragma once

#include "Texture.h"

class CheckerTexture : public Texture 
{
public:
	CheckerTexture();
	CheckerTexture(Texture* t0, Texture* t1);
	~CheckerTexture();
	Vec3 value(float u, float v, const Vec3& p) const override;

public:
	Texture* odd;
	Texture* even;
};