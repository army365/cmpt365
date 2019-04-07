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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave_As;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSlider *sliderVolume;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QSlider *sliderProgress;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *playButton;
    QPushButton *Snare;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuNew;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(657, 374);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 190, 352, 114));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        sliderVolume = new QSlider(layoutWidget);
        sliderVolume->setObjectName(QString::fromUtf8("sliderVolume"));
        sliderVolume->setValue(99);
        sliderVolume->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderVolume, 0, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sliderProgress = new QSlider(layoutWidget);
        sliderProgress->setObjectName(QString::fromUtf8("sliderProgress"));
        sliderProgress->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(sliderProgress);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pauseButton = new QPushButton(layoutWidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        horizontalLayout->addWidget(stopButton);

        playButton = new QPushButton(layoutWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));

        horizontalLayout->addWidget(playButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        formLayout->setLayout(2, QFormLayout::FieldRole, verticalLayout);

        Snare = new QPushButton(centralWidget);
        Snare->setObjectName(QString::fromUtf8("Snare"));
        Snare->setGeometry(QRect(20, 20, 80, 22));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 60, 621, 16));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 657, 21));
        menuNew = new QMenu(menuBar);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuNew->menuAction());
        menuNew->addAction(actionNew);
        menuNew->addAction(actionSave_As);
        menuNew->addAction(actionUndo);
        menuNew->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
        label->setText(QApplication::translate("MainWindow", "Volume", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Progress", nullptr));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        playButton->setText(QApplication::translate("MainWindow", "Play", nullptr));
        Snare->setText(QApplication::translate("MainWindow", "Snare", nullptr));
        menuNew->setTitle(QApplication::translate("MainWindow", "Kizyl Beatz", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
