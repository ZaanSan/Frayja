#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QFileDialog>
#include <QTranslator>
#include <QPainter>
#include <QDebug>
#include "ui_Frayja.h"

#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include "GuiApi.h"
#include "../Core/FrayjaThread.h"
#include "../Core/Scene.h"

class FrayjaGUI : public QMainWindow
{
	Q_OBJECT

public:
	FrayjaGUI(QWidget *parent = Q_NULLPTR);
	~FrayjaGUI();

public slots:
	void startRender();
	void endRender();
	void loadScene();
	void displayPixel(int x, int y, Vec3 color);
	void logConsole(LogType type, std::string msg);
	void redrawWindow();
	void saveFile();

protected:
	void paintEvent(QPaintEvent*) override;
	void closeEvent(QCloseEvent* event) override;

private:
	void updateLog();
	void clearLog();
	void setConfigurationCameraUI(const CameraConfiguration& camConf);
	void setConfigurationData();

private:
	Ui::FrayjaGUIClass ui;
	FrayjaThread mEngineThread;
	FrayjaConfiguration mConfiguration;
	Scene* mScene;
	
	QImage *mImage;
	QPixmap* mPixmap;
	QTimer* mTimer;

	std::string mLog;
	bool mIsRendering;
};
