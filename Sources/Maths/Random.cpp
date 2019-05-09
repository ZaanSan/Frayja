#include "Random.h"

Random::Random(float min, float max)
	: rEngine(0xA6E9377DAF75BDFEULL, 0x863F5CB508510D95ULL)
{
}

float Random::as_float(uint32_t i)
{
	union
	{
		uint32_t i;
		float f;
	} pun = { i };
	return pun.f;
}

Vec3 Random::randomInUnitSphere()
{
	Vec3 p;
	do {
		p = 2.0 * Vec3(generateNumber(), generateNumber(), generateNumber()) - Vec3(1, 1, 1);
	} while (p.length2() >= 1.0);
	return p;
}

Vec3 Random::randomInUnitDisk()
{
	Vec3 p;
	do {
		p = 2.0f * Vec3(generateNumber(), generateNumber(), 0) - Vec3(1, 1, 0);
	} while (Vec3::dot(p, p) >= 1.0);
	return p;
}
