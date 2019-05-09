#pragma once

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

#include "Frayja.h"
#include "Scene.h"
#include "FrayjaEventEmitter.h"
#include "FrayjaConfiguration.h"
#include "RenderingThread.h"
#include "../Maths/Vec3.h"

class RenderingThread;

// Engine thread / oppose to GUI thread
class FrayjaThread : public QThread
{
	Q_OBJECT

public: 
	FrayjaThread(QObject* parent);
	~FrayjaThread();

	const FrayjaEventEmitter& getEmitter() const;
	const Frayja& getEngine() const;
	const FrayjaConfiguration& getConfiguration() const;

	void startRender(const FrayjaConfiguration& conf, Scene* scene);

protected:
	void run() override;

private:
	void createRenderThreads();
	void launchRenderThreads();
	void waitRenderThreads();

private:
	FrayjaEventEmitter			mEmitter;
	Frayja						mEngine;
	FrayjaConfiguration			mConfiguration;
	Scene*						mScene;
	std::vector<RenderingThread*> mRenderThreads;

	QMutex mMutex;
	QWaitCondition mCondition;
	bool mRun;
	bool mPause;
	bool mStop;
};

