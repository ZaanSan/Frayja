#pragma once

#include <random>
#include "Vec3.h"

class Random
{
	class xorshift_128_plus
	{
	private:
		uint64_t state0;
		uint64_t state1;

	public:
		xorshift_128_plus() = default;
		xorshift_128_plus(uint64_t state0, uint64_t state1) : state0(state0), state1(state1) {}

		uint64_t next64()
		{
			uint64_t x = state0;
			uint64_t y = state1;
			uint64_t r = x + y;
			state0 = y;
			x ^= x << 23;
			state1 = x ^ y ^ (x >> 18) ^ (y >> 5);
			return r;
		}

		uint32_t next32()
		{
			uint64_t x = state0;
			uint64_t y = state1;
			uint64_t r = x + y;
			state0 = y;
			x ^= x << 23;
			state1 = x ^ y ^ (x >> 18) ^ (y >> 5);
			return static_cast<uint32_t>(r);
		}
	};

private:
	xorshift_128_plus rEngine;

public:
	Random(float min, float max);
	inline float generateNumber() 
	{
			return as_float(0x3F800000U | (rEngine.next32() >> 9)) - 1.0f;
	};
	Vec3 randomInUnitSphere();
	Vec3 randomInUnitDisk();

private:
	float as_float(uint32_t i);
};