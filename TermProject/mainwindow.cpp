#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSound>
#include <QFile>
#include <iostream>
#include <cmath>
#include <vector>
#include <QString>
#include "sndfile.h"
#include "sndfile.hh"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        //player possibly contains layered audio channels
        player = new QMediaPlayer(this);
        snare = new QMediaPlayer(this);
        //snare->setMedia(QUrl("qrc:/sourceres/track/Snares1.wav"));

        //should be connected to final file created
        connect(snare, &QMediaPlayer::positionChanged, this, &MainWindow::on_positionChanged);
        connect(snare, &QMediaPlayer::durationChanged, this, &MainWindow::on_durationChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------- Global variables -----------//

const int kcoef = 1024;
float buffer[1024];

QString input_file = "";
QString temp_file = "";
QString interval_file =  "";

std::vector<float> audio_vec;
std::vector<float> temp_vec;
std::vector<float> interval_vec;

double start_time = 0;
double end_time = 0;

std::vector<std::vector<float>> audio_stack;

//Sampling rate
const int SR = 44100;
const int T = 1/SR;


// ---------- ui functionalities -----------//
void MainWindow::on_playButton_clicked()
{
    //play
    //player->setMedia(QUrl("qrc:/sourceres/track/Snares1.wav"));
    //player->setMedia(QUrl::fromLocalFile("/Users/Izyl/Desktop/cmpt365/TermProject/Snares1.wav"));

    //player->play();
    //qDebug() << player->errorString();
}

void MainWindow::on_stopButton_clicked()
{
   // player->stop();
}

void MainWindow::on_pauseButton_clicked(int position)
{
    //player->pause();
    //bool paused = true;
}

void MainWindow::on_sliderProgress_sliderMoved(int position)
{
    //player->setPosition(position);
    snare->setPosition(position);
}

void MainWindow::on_sliderVolume_sliderMoved(int position)
{
    //player->setVolume(position);
    snare->setVolume(position);
}

void MainWindow::on_positionChanged(qint64 position){
    ui -> sliderProgress->setValue(position);
}

void MainWindow::on_durationChanged(qint64 position){
     ui -> sliderProgress->setMaximum(position);
}

//replace with button,triggered from instrument graphic
void MainWindow::on_Snare_clicked()
{
    //snare = new QMediaPlayer;
    //Play snare sound
    //snare->setMedia(QUrl("qrc:/sourceres/track/Snares1.wav"));
    snare->setMedia(QUrl::fromLocalFile("/Users/Izyl/Desktop/cmpt365/TermProject/Snares1.wav"));

    if(snare->state() == QMediaPlayer::PlayingState){snare->setPosition(0);}
    else if(snare->state() == QMediaPlayer::StoppedState){snare->play();}
}




