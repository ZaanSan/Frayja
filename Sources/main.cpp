#include "GUI/FrayjaGUI.h"
#include <QtWidgets/QApplication>
#include <QtWidgets\QLabel>
#include <QStyleFactory>
#include <QDebug>
#include "Core/Frayja.h"

int main(int argc, char *argv[])
{
	//QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QApplication a(argc, argv);
	a.setStyle(QStyleFactory::create("Fusion"));
	FrayjaGUI app;
	app.show();
	return a.exec();
}
