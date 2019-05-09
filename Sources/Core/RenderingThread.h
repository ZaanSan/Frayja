#pragma once

#include "FrayjaThread.h"

class FrayjaThread;

class RenderingThread  : public QThread
{
	Q_OBJECT

public:
	RenderingThread(QObject* parent, FrayjaThread* mainThread, int lineBegin, int lineEnd);
	~RenderingThread();

	void startRendering();

protected:
	void run();

private:
	FrayjaThread*	mMainThread;
	int				mBegin;
	int				mEnd;
};