#pragma once

#include "../Maths/Vec3.h"
#include "../Maths/Random.h"

inline float perlinInterp(Vec3 c[2][2][2], float u, float v, float w)
{
	float uu = u * u * (3 - 2 * u);
	float vv = v * v * (3 - 2 * v);
	float ww = w * w * (3 - 2 * w);
	float accum = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				Vec3 weightV(u - i, v - j, w - k);
				accum += (i * uu + (1 - i) * (1 - uu)) *
					     (j * vv + (1 - j) * (1 - vv)) *
					     (k * ww + (1 - k) * (1 - ww)) * Vec3::dot(c[i][j][k], weightV);
			}
		}
	}
	return accum;
}

class Perlin
{
public:
	float noise(const Vec3& p) const 
	{
		float u = p.x() - floor(p.x());
		float v = p.y() - floor(p.y());
		float w = p.z() - floor(p.z());
		int i = floor(p.x());
		int j = floor(p.y());
		int k = floor(p.z());
		Vec3 c[2][2][2];
		for (int di = 0; di < 2; di++)
			for (int dj = 0; dj < 2; dj++)
				for (int dk = 0; dk < 2; dk++)
					c[di][dj][dk] = ranvec[permX[(i + di) & 255] ^ permY[(j + dj) & 255] ^ permZ[(k + dk) & 255]];
		return perlinInterp(c, u, v, w);
	}

	float turb(const Vec3& p, int depth = 7) const
	{
		float accum = 0;
		Vec3 tmpP = p;
		float weight = 1.0f;
		for (int i = 0; i < depth; i++)
		{
			accum += weight * noise(tmpP);
			weight *= 0.5;
			tmpP *= 2;
		}
		return fabs(accum);
	}

	static Vec3* ranvec;
	static int* permX;
	static int* permY;
	static int* permZ;
};
