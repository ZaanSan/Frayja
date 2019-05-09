#include "FrayjaGUI.h"
#include <QtWidgets\QLabel>

FrayjaGUI::FrayjaGUI(QWidget* parent)
	: QMainWindow(parent),
	mEngineThread(parent),
	mScene(new Scene()),
	mImage(nullptr),
	mPixmap(new QPixmap()),
	mTimer(new QTimer()),
	mIsRendering(false)
{
	ui.setupUi(this);

	ui.mProgress->hide();
	ui.actionPause->setVisible(false);
	ui.actionStop->setVisible(false);

	ui.actionRun->setEnabled(false);
	ui.actionSave->setEnabled(false);

	qRegisterMetaType<std::string>("std::string");
	qRegisterMetaType<LogType>("LogType");
	qRegisterMetaType<Vec3>("Vec3");

	mTimer->setInterval(100);
	mTimer->start();

	QObject::connect(mTimer, SIGNAL(timeout()), this, SLOT(redrawWindow()));

	connect(ui.actionLoad, SIGNAL(triggered()), this, SLOT(loadScene()));
	connect(ui.actionRun, SIGNAL(triggered()), this, SLOT(startRender()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));

	const auto& emitter = mEngineThread.getEmitter();
	connect(&emitter, SIGNAL(renderedImage()), this, SLOT(endRender()));
	connect(&emitter, SIGNAL(pixelRendered(int, int, Vec3)), this, SLOT(displayPixel(int, int, Vec3)));
	connect(&emitter, SIGNAL(log(LogType, std::string)), this, SLOT(logConsole(LogType, std::string)));

	logConsole(LogType::SUCCESS, "GUI is setup!");
}

FrayjaGUI::~FrayjaGUI()
{
	mTimer->stop();
	
	delete mPixmap;
	delete mTimer;
	delete mScene;
	if (mImage)
		delete mImage;
}

void FrayjaGUI::displayPixel(int x, int y, Vec3 color)
{
	*((QRgb*)mImage->scanLine(y) + x) = qRgb(color.r(), color.g(), color.b());
}

void FrayjaGUI::startRender()
{
	if (!mIsRendering)
	{
		setConfigurationData();
		if (mImage)
			delete mImage;
		mImage = new QImage(mConfiguration.general.width, mConfiguration.general.height, QImage::Format::Format_ARGB32);
		mImage->fill(Qt::GlobalColor::lightGray);
		ui.actionRun->setEnabled(false);
		ui.actionLoad->setEnabled(false);
		ui.actionSave->setEnabled(false);
		mIsRendering = true;
		logConsole(LogType::MESSAGE, "Start rendering");
		mEngineThread.startRender(mConfiguration, mScene);
	}
}

void FrayjaGUI::endRender()
{
	logConsole(LogType::SUCCESS, "Rendering finished");
	mIsRendering = false;
	ui.actionRun->setEnabled(true);
	ui.actionLoad->setEnabled(true);
	ui.actionSave->setEnabled(true);
}

void FrayjaGUI::loadScene()
{
	std::string filename = QFileDialog::getOpenFileName(this, tr("Load scene"), "./", tr("XML files (*.xml)")).toStdString();

	if (!filename.empty())
	{
		logConsole(LogType::MESSAGE, "Selected scene: " + filename);
		if (mScene->loadScene(filename))
		{
			if (mScene->hasCameraConfiguration())
				setConfigurationCameraUI(mScene->getCameraConfiguration());
			ui.actionRun->setEnabled(true);
			logConsole(LogType::SUCCESS, "File successfully parsed");
		}
		else
		{
			logConsole(LogType::ERROR, "Wrong scene file");
		}
	}
}

void FrayjaGUI::redrawWindow()
{
	updateLog();
	repaint();
}

void FrayjaGUI::saveFile()
{
	std::string dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		"./", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks).toStdString();
	
	if (!dir.empty())
	{
		std::string path = mScene->getFileName();
		path = path.substr(path.find_last_of("/\\"));
		path = std::regex_replace(path, std::regex(".xml"), ".ppm");
		path = dir + path;

		std::ofstream file;
		file.open(path, std::ostream::out | std::ostream::trunc);
		int width = mConfiguration.general.width;
		int height = mConfiguration.general.height;

		const QRgb * data = (const QRgb*)mImage->constBits();
		file << "P3\n" << width << " " << height << "\n255\n";
		for (int i = 0; i < width * height; i++)
		{
			file << qRed(data[i]) << " " << qGreen(data[i]) << " " << qBlue(data[i]) << "\n";
		}
		file.close();
		logConsole(LogType::SUCCESS, "File saved: " + path);
	}
}

#pragma region Configuration

void FrayjaGUI::setConfigurationCameraUI(const CameraConfiguration& camConf)
{
	ui.mCamPosX->setValue(camConf.position.x());
	ui.mCamPosY->setValue(camConf.position.y());
	ui.mCamPosZ->setValue(camConf.position.z());
	ui.mCamDirX->setValue(camConf.direction.x());
	ui.mCamDirY->setValue(camConf.direction.y());
	ui.mCamDirZ->setValue(camConf.direction.z());
	ui.mFov->setValue(camConf.fov);
	ui.mAperture->setValue(camConf.aperture);
	ui.mDistToFocus->setValue(camConf.distToFocus);
}

void FrayjaGUI::setConfigurationData()
{
	mConfiguration.general.width = ui.mWidth->value();
	mConfiguration.general.height = ui.mHeight->value();
	mConfiguration.general.aaSamples = ui.mSamples->value();
	mConfiguration.general.depth = ui.mDepth->value();
	mConfiguration.general.nbThreads = ui.mThreads->value();

	mConfiguration.camera.position = Vec3(ui.mCamPosX->value(), ui.mCamPosY->value(), ui.mCamPosZ->value());
	mConfiguration.camera.direction = Vec3(ui.mCamDirX->value(), ui.mCamDirY->value(), ui.mCamDirZ->value());
	mConfiguration.camera.fov = ui.mFov->value();
	mConfiguration.camera.aperture = ui.mAperture->value();
	mConfiguration.camera.distToFocus = ui.mDistToFocus->value();
}

#pragma endregion

#pragma region Window event

void FrayjaGUI::closeEvent(QCloseEvent* event)
{

}

void FrayjaGUI::paintEvent(QPaintEvent*)
{
	if (mImage)
	{
		*mPixmap = QPixmap::fromImage(*mImage);
		ui.mImage->setPixmap(*mPixmap);
	}
}

#pragma endregion

#pragma region Logging

void FrayjaGUI::logConsole(LogType type, std::string msg)
{
	QDateTime time = QDateTime::currentDateTime();
	bool isSpan = false;
	std::string msgInfo;
	if (mLog != "")
		mLog += "<br/>";
	switch (type)
	{
	case MESSAGE:
		msgInfo = "Information";
		break;
	case WARNING:
		mLog += "<span style=\"color:orange;\">";
		msgInfo = "Warning";
		isSpan = true;
		break;
	case SUCCESS:
		mLog += "<span style=\"color:green;\">";
		msgInfo = "Success";
		isSpan = true;
		break;
	case ERROR:
		mLog += "<span style=\"color:red;\">";
		msgInfo = "Error";
		isSpan = true;
		break;
	default:
		break;
	}
	mLog += time.toString("<b>[MM/dd/yy hh:mm:ss] ").toStdString();
	mLog += msgInfo + ": </b>" + msg;
	if (isSpan)
		mLog += " </span>";
}

void FrayjaGUI::clearLog()
{
	mLog = "";
}

void FrayjaGUI::updateLog()
{
	ui.mConsole->setHtml(mLog.c_str());
	ui.mConsole->moveCursor(QTextCursor::End);
}

#pragma endregion

