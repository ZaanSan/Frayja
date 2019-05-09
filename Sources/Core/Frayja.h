#pragma once

#include <cfloat>

#include "FrayjaEventEmitter.h"
#include "FrayjaConfiguration.h"
#include "Scene.h"

#include "../Maths/Vec3.h"
#include "../Maths/Ray.h"
#include "../Maths/Random.h"
#include "../Hitable/Hitable.h"

class Frayja
{
private:
	FrayjaEventEmitter& mEmitter;
	FrayjaConfiguration mConfiguration;
	Scene* mScene;
	Random mRandom;
	Camera* mCamera;
	Hitable* mWorld;
	
public:
	explicit Frayja(FrayjaEventEmitter& emitter);
	~Frayja();

	void setConfiguration(FrayjaConfiguration conf);
	void setScene(Scene* scene);
	void initRendering();
	void render(int x, int y) const;
	void endRendering();

private:
	Vec3 color(const Ray& r, const Hitable* world, int depth) const;
};

