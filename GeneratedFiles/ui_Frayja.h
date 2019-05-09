/********************************************************************************
** Form generated from reading UI file 'Frayja.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAYJA_H
#define UI_FRAYJA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FrayjaGUIClass
{
public:
    QAction *actionRun;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionLoad;
    QAction *actionSave;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_7;
    QLabel *mImage;
    QGroupBox *mConsoleGroup;
    QVBoxLayout *verticalLayout;
    QTextEdit *mConsole;
    QProgressBar *mProgress;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QToolBox *toolBox;
    QWidget *page_1;
    QGridLayout *gridLayout_3;
    QSpinBox *mDepth;
    QSpinBox *mSamples;
    QLabel *label;
    QLabel *label_9;
    QSpacerItem *verticalSpacer;
    QSpinBox *mWidth;
    QLabel *label_2;
    QLabel *label_10;
    QSpinBox *mHeight;
    QLabel *label_13;
    QSpinBox *mThreads;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QDoubleSpinBox *mCamPosY;
    QDoubleSpinBox *mCamPosX;
    QLabel *label_4;
    QLabel *label_5;
    QDoubleSpinBox *mCamPosZ;
    QLabel *label_14;
    QSpacerItem *verticalSpacer_3;
    QDoubleSpinBox *mAperture;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_6;
    QDoubleSpinBox *mCamDirX;
    QLabel *label_6;
    QDoubleSpinBox *mCamDirY;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *mCamDirZ;
    QLabel *label_11;
    QDoubleSpinBox *mDistToFocus;
    QLabel *label_12;
    QDoubleSpinBox *mFov;
    QToolBar *toolBar;

    void setupUi(QMainWindow *FrayjaGUIClass)
    {
        if (FrayjaGUIClass->objectName().isEmpty())
            FrayjaGUIClass->setObjectName(QString::fromUtf8("FrayjaGUIClass"));
        FrayjaGUIClass->resize(790, 554);
        actionRun = new QAction(FrayjaGUIClass);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionPause = new QAction(FrayjaGUIClass);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionStop = new QAction(FrayjaGUIClass);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionLoad = new QAction(FrayjaGUIClass);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(FrayjaGUIClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralwidget = new QWidget(FrayjaGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 621, 337));
        gridLayout_7 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        mImage = new QLabel(scrollAreaWidgetContents);
        mImage->setObjectName(QString::fromUtf8("mImage"));

        gridLayout_7->addWidget(mImage, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        mConsoleGroup = new QGroupBox(centralwidget);
        mConsoleGroup->setObjectName(QString::fromUtf8("mConsoleGroup"));
        verticalLayout = new QVBoxLayout(mConsoleGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mConsole = new QTextEdit(mConsoleGroup);
        mConsole->setObjectName(QString::fromUtf8("mConsole"));
        mConsole->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout->addWidget(mConsole);


        gridLayout->addWidget(mConsoleGroup, 2, 0, 1, 1);

        mProgress = new QProgressBar(centralwidget);
        mProgress->setObjectName(QString::fromUtf8("mProgress"));
        mProgress->setEnabled(true);
        mProgress->setValue(24);

        gridLayout->addWidget(mProgress, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 15);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 2);
        gridLayout->setRowStretch(3, 1);
        FrayjaGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FrayjaGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 790, 20));
        FrayjaGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(FrayjaGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FrayjaGUIClass->setStatusBar(statusbar);
        dockWidget = new QDockWidget(FrayjaGUIClass);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(150, 166));
        dockWidget->setStyleSheet(QString::fromUtf8("::title {\n"
"	text-align: center\n"
"}"));
        dockWidget->setFeatures(QDockWidget::DockWidgetMovable);
        dockWidget->setWindowTitle(QString::fromUtf8("Configuration"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        toolBox = new QToolBox(dockWidgetContents);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setLayoutDirection(Qt::LeftToRight);
        toolBox->setAutoFillBackground(false);
        toolBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(108, 108, 108);"));
        toolBox->setFrameShape(QFrame::NoFrame);
        toolBox->setFrameShadow(QFrame::Plain);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setGeometry(QRect(0, 0, 136, 416));
        gridLayout_3 = new QGridLayout(page_1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        mDepth = new QSpinBox(page_1);
        mDepth->setObjectName(QString::fromUtf8("mDepth"));
        mDepth->setMinimum(1);
        mDepth->setMaximum(100000);
        mDepth->setValue(50);

        gridLayout_3->addWidget(mDepth, 3, 1, 1, 2);

        mSamples = new QSpinBox(page_1);
        mSamples->setObjectName(QString::fromUtf8("mSamples"));
        mSamples->setMinimum(1);
        mSamples->setMaximum(10000);
        mSamples->setValue(20);

        gridLayout_3->addWidget(mSamples, 2, 1, 1, 2);

        label = new QLabel(page_1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        label_9 = new QLabel(page_1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 5, 1, 1, 1);

        mWidth = new QSpinBox(page_1);
        mWidth->setObjectName(QString::fromUtf8("mWidth"));
        mWidth->setMaximum(1920);
        mWidth->setValue(600);

        gridLayout_3->addWidget(mWidth, 0, 1, 1, 2);

        label_2 = new QLabel(page_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label_10 = new QLabel(page_1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 3, 0, 1, 1);

        mHeight = new QSpinBox(page_1);
        mHeight->setObjectName(QString::fromUtf8("mHeight"));
        mHeight->setMaximum(1080);
        mHeight->setValue(400);

        gridLayout_3->addWidget(mHeight, 1, 1, 1, 2);

        label_13 = new QLabel(page_1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 4, 0, 1, 1);

        mThreads = new QSpinBox(page_1);
        mThreads->setObjectName(QString::fromUtf8("mThreads"));
        mThreads->setMinimum(1);
        mThreads->setMaximum(100);
        mThreads->setValue(1);

        gridLayout_3->addWidget(mThreads, 4, 1, 1, 2);

        toolBox->addItem(page_1, QString::fromUtf8("General"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 153, 416));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        mCamPosY = new QDoubleSpinBox(groupBox);
        mCamPosY->setObjectName(QString::fromUtf8("mCamPosY"));
        mCamPosY->setMinimum(-1000.000000000000000);
        mCamPosY->setMaximum(1000.000000000000000);

        gridLayout_5->addWidget(mCamPosY, 4, 1, 1, 1);

        mCamPosX = new QDoubleSpinBox(groupBox);
        mCamPosX->setObjectName(QString::fromUtf8("mCamPosX"));
        mCamPosX->setMinimum(-1000.000000000000000);
        mCamPosX->setMaximum(1000.000000000000000);

        gridLayout_5->addWidget(mCamPosX, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 5, 0, 1, 1);

        mCamPosZ = new QDoubleSpinBox(groupBox);
        mCamPosZ->setObjectName(QString::fromUtf8("mCamPosZ"));
        mCamPosZ->setMinimum(-1000.000000000000000);
        mCamPosZ->setMaximum(1000.000000000000000);

        gridLayout_5->addWidget(mCamPosZ, 5, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 2);

        label_14 = new QLabel(page_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_4->addWidget(label_14, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 271, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_3, 7, 0, 1, 1);

        mAperture = new QDoubleSpinBox(page_2);
        mAperture->setObjectName(QString::fromUtf8("mAperture"));
        mAperture->setDecimals(5);
        mAperture->setMaximum(10000.000000000000000);
        mAperture->setValue(0.010000000000000);

        gridLayout_4->addWidget(mAperture, 3, 1, 1, 1);

        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_6 = new QGridLayout(groupBox_2);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        mCamDirX = new QDoubleSpinBox(groupBox_2);
        mCamDirX->setObjectName(QString::fromUtf8("mCamDirX"));
        mCamDirX->setMinimum(-1000.000000000000000);
        mCamDirX->setMaximum(1000.000000000000000);

        gridLayout_6->addWidget(mCamDirX, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_6->addWidget(label_6, 0, 0, 1, 1);

        mCamDirY = new QDoubleSpinBox(groupBox_2);
        mCamDirY->setObjectName(QString::fromUtf8("mCamDirY"));
        mCamDirY->setMinimum(-1000.000000000000000);
        mCamDirY->setMaximum(1000.000000000000000);

        gridLayout_6->addWidget(mCamDirY, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_6->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_6->addWidget(label_8, 2, 0, 1, 1);

        mCamDirZ = new QDoubleSpinBox(groupBox_2);
        mCamDirZ->setObjectName(QString::fromUtf8("mCamDirZ"));
        mCamDirZ->setMinimum(-1000.000000000000000);
        mCamDirZ->setMaximum(1000.000000000000000);
        mCamDirZ->setValue(-1.000000000000000);

        gridLayout_6->addWidget(mCamDirZ, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 2);

        label_11 = new QLabel(page_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 4, 0, 1, 1);

        mDistToFocus = new QDoubleSpinBox(page_2);
        mDistToFocus->setObjectName(QString::fromUtf8("mDistToFocus"));
        mDistToFocus->setMaximum(10000.000000000000000);
        mDistToFocus->setValue(1.000000000000000);

        gridLayout_4->addWidget(mDistToFocus, 4, 1, 1, 1);

        label_12 = new QLabel(page_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 2, 0, 1, 1);

        mFov = new QDoubleSpinBox(page_2);
        mFov->setObjectName(QString::fromUtf8("mFov"));
        mFov->setMaximum(180.000000000000000);
        mFov->setValue(90.000000000000000);

        gridLayout_4->addWidget(mFov, 2, 1, 1, 1);

        toolBox->addItem(page_2, QString::fromUtf8("Camera"));

        gridLayout_2->addWidget(toolBox, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        FrayjaGUIClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        toolBar = new QToolBar(FrayjaGUIClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        FrayjaGUIClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionLoad);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionRun);
        toolBar->addAction(actionPause);
        toolBar->addAction(actionStop);
        toolBar->addSeparator();

        retranslateUi(FrayjaGUIClass);

        QMetaObject::connectSlotsByName(FrayjaGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *FrayjaGUIClass)
    {
        FrayjaGUIClass->setWindowTitle(QApplication::translate("FrayjaGUIClass", "Frayja", nullptr));
        actionRun->setText(QApplication::translate("FrayjaGUIClass", "Run", nullptr));
        actionPause->setText(QApplication::translate("FrayjaGUIClass", "Pause", nullptr));
        actionStop->setText(QApplication::translate("FrayjaGUIClass", "Stop", nullptr));
        actionLoad->setText(QApplication::translate("FrayjaGUIClass", "Load scene", nullptr));
        actionSave->setText(QApplication::translate("FrayjaGUIClass", "Save image", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("FrayjaGUIClass", "Save image", nullptr));
#endif // QT_NO_TOOLTIP
        mImage->setText(QString());
        mConsoleGroup->setTitle(QApplication::translate("FrayjaGUIClass", "Console", nullptr));
        label->setText(QApplication::translate("FrayjaGUIClass", "Width", nullptr));
        label_9->setText(QApplication::translate("FrayjaGUIClass", "AA (samples)", nullptr));
        label_2->setText(QApplication::translate("FrayjaGUIClass", "Height", nullptr));
        label_10->setText(QApplication::translate("FrayjaGUIClass", "Depth", nullptr));
        label_13->setText(QApplication::translate("FrayjaGUIClass", "Threads", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_1), QApplication::translate("FrayjaGUIClass", "General", nullptr));
        groupBox->setTitle(QApplication::translate("FrayjaGUIClass", "Position", nullptr));
        label_3->setText(QApplication::translate("FrayjaGUIClass", "X", nullptr));
        label_4->setText(QApplication::translate("FrayjaGUIClass", "Y", nullptr));
        label_5->setText(QApplication::translate("FrayjaGUIClass", "Z", nullptr));
        label_14->setText(QApplication::translate("FrayjaGUIClass", "Aperture", nullptr));
        groupBox_2->setTitle(QApplication::translate("FrayjaGUIClass", "Direction", nullptr));
        label_6->setText(QApplication::translate("FrayjaGUIClass", "X", nullptr));
        label_7->setText(QApplication::translate("FrayjaGUIClass", "Y", nullptr));
        label_8->setText(QApplication::translate("FrayjaGUIClass", "Z", nullptr));
        label_11->setText(QApplication::translate("FrayjaGUIClass", "Focus distance", nullptr));
        label_12->setText(QApplication::translate("FrayjaGUIClass", "FOV", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("FrayjaGUIClass", "Camera", nullptr));
        toolBar->setWindowTitle(QApplication::translate("FrayjaGUIClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrayjaGUIClass: public Ui_FrayjaGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAYJA_H
