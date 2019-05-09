#include "FrayjaThread.h"


FrayjaThread::FrayjaThread(QObject* parent)
	: QThread(parent),
	mEmitter(),
	mEngine(mEmitter),
	mRenderThreads(),
	mMutex(),
	mCondition(),
	mRun(false),
	mPause(false),
	mStop(false)
{
}

FrayjaThread::~FrayjaThread()
{
	mMutex.lock();
	mStop = true;
	mCondition.wakeOne();
	mMutex.unlock();
	wait();
}

const FrayjaEventEmitter& FrayjaThread::getEmitter() const
{
	return mEmitter;
}

const Frayja& FrayjaThread::getEngine() const
{
	return mEngine;
}

const FrayjaConfiguration& FrayjaThread::getConfiguration() const
{
	return mConfiguration;
}

void FrayjaThread::startRender(const FrayjaConfiguration& conf, Scene* scene)
{
	QMutexLocker locker(&mMutex);

	mConfiguration = conf;
	mScene = scene;
	if (!isRunning())
		start(LowPriority);
	else
		mCondition.wakeOne();
}

void FrayjaThread::createRenderThreads()
{
	if (!mRenderThreads.empty())
	{
		for (auto it = mRenderThreads.begin(); it != mRenderThreads.end(); ++it)
		{
			delete (*it);
		}
		mRenderThreads.clear();
	}
	int height = mConfiguration.general.height;
	int nbThreads = mConfiguration.general.nbThreads;
	int chunkSize = (height + nbThreads - 1) / nbThreads;
	for (int i = 0; i < mConfiguration.general.nbThreads; ++i)
	{
		int start = i * chunkSize;
		int end = std::min(start + chunkSize, height);
		mRenderThreads.push_back(new RenderingThread(parent(), this, start, end));
	}
}

void FrayjaThread::launchRenderThreads()
{
	for (auto it = mRenderThreads.begin(); it != mRenderThreads.end(); ++it)
	{
		(*it)->startRendering();
	}
}

void FrayjaThread::waitRenderThreads()
{
	for (auto it = mRenderThreads.begin(); it != mRenderThreads.end(); ++it)
	{
		(*it)->wait();
	}
}


void FrayjaThread::run()
{
	forever
	{
		if (mStop)
			return;
		createRenderThreads();
		mEngine.setConfiguration(mConfiguration);
		mEngine.setScene(mScene);
		mEngine.initRendering();
		launchRenderThreads();
		waitRenderThreads();
		//mEngine.render();
		mEngine.endRendering();
		mEmitter.renderedImageEvent();
		mMutex.lock();
		mCondition.wait(&mMutex);
		mMutex.unlock();
	}
}
