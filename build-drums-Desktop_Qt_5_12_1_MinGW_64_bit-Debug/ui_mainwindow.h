/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SoundEffectWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *saveProjectAsAction;
    QAction *loadProjectAction;
    QAction *exitAction;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    SoundEffectWidget *snareWidget;
    SoundEffectWidget *kickWidget;
    SoundEffectWidget *hihatWidget;
    SoundEffectWidget *crashWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *playButton;
    QPushButton *recordButton;
    QPushButton *stopButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *currentTimeLabel;
    QLabel *timeSeparatorLabel;
    QLabel *totalTimeLabel;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFIle;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        saveProjectAsAction = new QAction(MainWindow);
        saveProjectAsAction->setObjectName(QString::fromUtf8("saveProjectAsAction"));
        loadProjectAction = new QAction(MainWindow);
        loadProjectAction->setObjectName(QString::fromUtf8("loadProjectAction"));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        snareWidget = new SoundEffectWidget(centralWidget);
        snareWidget->setObjectName(QString::fromUtf8("snareWidget"));

        gridLayout->addWidget(snareWidget, 0, 1, 1, 1);

        kickWidget = new SoundEffectWidget(centralWidget);
        kickWidget->setObjectName(QString::fromUtf8("kickWidget"));

        gridLayout->addWidget(kickWidget, 0, 0, 1, 1);

        hihatWidget = new SoundEffectWidget(centralWidget);
        hihatWidget->setObjectName(QString::fromUtf8("hihatWidget"));

        gridLayout->addWidget(hihatWidget, 1, 0, 1, 1);

        crashWidget = new SoundEffectWidget(centralWidget);
        crashWidget->setObjectName(QString::fromUtf8("crashWidget"));

        gridLayout->addWidget(crashWidget, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        QFont font;
        font.setPointSize(10);
        playButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon);

        horizontalLayout->addWidget(playButton);

        recordButton = new QPushButton(centralWidget);
        recordButton->setObjectName(QString::fromUtf8("recordButton"));
        recordButton->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/record.png"), QSize(), QIcon::Normal, QIcon::Off);
        recordButton->setIcon(icon1);

        horizontalLayout->addWidget(recordButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon2);

        horizontalLayout->addWidget(stopButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        currentTimeLabel = new QLabel(centralWidget);
        currentTimeLabel->setObjectName(QString::fromUtf8("currentTimeLabel"));
        QFont font1;
        font1.setPointSize(14);
        currentTimeLabel->setFont(font1);

        horizontalLayout_2->addWidget(currentTimeLabel);

        timeSeparatorLabel = new QLabel(centralWidget);
        timeSeparatorLabel->setObjectName(QString::fromUtf8("timeSeparatorLabel"));
        timeSeparatorLabel->setFont(font1);

        horizontalLayout_2->addWidget(timeSeparatorLabel);

        totalTimeLabel = new QLabel(centralWidget);
        totalTimeLabel->setObjectName(QString::fromUtf8("totalTimeLabel"));
        totalTimeLabel->setFont(font1);

        horizontalLayout_2->addWidget(totalTimeLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 20));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QString::fromUtf8("menuFIle"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFIle->menuAction());
        menuFIle->addAction(saveProjectAsAction);
        menuFIle->addAction(loadProjectAction);
        menuFIle->addAction(exitAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        saveProjectAsAction->setText(QApplication::translate("MainWindow", "Save project as...", nullptr));
#ifndef QT_NO_SHORTCUT
        saveProjectAsAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        loadProjectAction->setText(QApplication::translate("MainWindow", "Load project...", nullptr));
#ifndef QT_NO_SHORTCUT
        loadProjectAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        exitAction->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        exitAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        playButton->setText(QApplication::translate("MainWindow", "Play", nullptr));
        recordButton->setText(QApplication::translate("MainWindow", "Record", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        currentTimeLabel->setText(QApplication::translate("MainWindow", "01:49", nullptr));
        timeSeparatorLabel->setText(QApplication::translate("MainWindow", "/", nullptr));
        totalTimeLabel->setText(QApplication::translate("MainWindow", "02:05", nullptr));
        menuFIle->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
