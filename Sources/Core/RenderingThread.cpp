#include "RenderingThread.h"

RenderingThread::RenderingThread(QObject* parent, FrayjaThread* mainThread, int lineBegin, int lineEnd)
	: QThread(parent),
	mMainThread(mainThread),
	mBegin(lineBegin),
	mEnd(lineEnd)
{
}

RenderingThread::~RenderingThread()
{
}

void RenderingThread::startRendering()
{
	start(LowPriority);
}

void RenderingThread::run()
{
	int x = 0;
	int y = mBegin;
	int width = mMainThread->getConfiguration().general.width;

	for (int y = mBegin; y < mEnd; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			mMainThread->getEngine().render(x, y);
		}
	}
}
