#pragma once

#include <QObject>

#include "../GUI/GuiApi.h"
#include "../Maths/Vec3.h"

class FrayjaEventEmitter : public QObject
{
	Q_OBJECT

public:
	FrayjaEventEmitter();
	~FrayjaEventEmitter();

	void logEvent(LogType type, std::string msg) const;
	void renderedImageEvent() const;
	void pixelRenderedEvent(int x, int y, const Vec3& color) const;

signals:
	void log(LogType type, std::string msg) const;
	void renderedImage() const;
	void pixelRendered(int x, int y, Vec3 color) const;
};