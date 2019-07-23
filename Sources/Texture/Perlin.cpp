#include "Perlin.h"

static Vec3* perlinGenerate()
{
	Random ran(0.0f, 1.0f);

	Vec3* p = new Vec3[256];
	for (int i = 0; i < 256; ++i)
		p[i] = Vec3::unitVector(Vec3(-1 + 2 * ran.generateNumber(), -1 + 2 * ran.generateNumber(), -1 + 2 * ran.generateNumber()));
	return p;
}

void permute(int* p, int n)
{
	Random ran(0.0f, 1.0f);

	for (int i = n - 1; i > 0; i--)
	{
		int target = int(ran.generateNumber() * (i + 1));
		int tmp = p[i];
		p[i] = p[target];
		p[target] = tmp;
	}
}

static int* perlinGeneratePerm()
{
	int* p = new int[256];
	for (int i = 0; i < 256; i++)
		p[i] = i;
	permute(p, 256);
	return p;
}

Vec3* Perlin::ranvec = perlinGenerate();
int* Perlin::permX = perlinGeneratePerm();
int* Perlin::permY = perlinGeneratePerm();
int* Perlin::permZ = perlinGeneratePerm();