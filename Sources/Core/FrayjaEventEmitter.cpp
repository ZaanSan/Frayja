#include "FrayjaEventEmitter.h"

FrayjaEventEmitter::FrayjaEventEmitter() = default;

FrayjaEventEmitter::~FrayjaEventEmitter() = default;

void FrayjaEventEmitter::logEvent(LogType type, std::string msg) const
{
	emit log(type, msg);
}  

void FrayjaEventEmitter::renderedImageEvent() const
{
	emit renderedImage();
}

void FrayjaEventEmitter::pixelRenderedEvent(int x, int y, const Vec3& color) const
{
	emit pixelRendered(x, y, color);
}
