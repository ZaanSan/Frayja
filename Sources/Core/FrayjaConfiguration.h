#pragma once

#include "../Maths/Vec3.h"

struct GeneralConfiguration
{
	float width;
	float height;
	int aaSamples;
	int depth;
	int nbThreads;
};

struct CameraConfiguration
{
	Vec3 position;
	Vec3 direction;
	float fov;
	float aperture;
	float distToFocus;
};

struct FrayjaConfiguration
{
	GeneralConfiguration general;
	CameraConfiguration camera;
};