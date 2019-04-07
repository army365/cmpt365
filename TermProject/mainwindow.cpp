#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sndfile.h"
#include "sndfile.hh"
#include <QSound>
#include <QChar>
#include <QFile>
#include <iostream>
#include <cmath>
#include <vector>
#include <QString>
#include <QDebug>

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

// ---------- Global variables -----------//

const int kcoef = 1024;
float buffer[1024];

QString input_file = ""; //original file name
QString temp_file = "";
QString interval_file =  "";

std::vector<float> audio_vec; //wav_vec
std::vector<float> temp_vec;
std::vector<float> interval_vec;

double start_time = 0;
double end_time = 0;
int start_index = 0;
int end_index = 0;
int current_index = 0;

std::vector<std::vector<float>> audio_stack;

//Sampling rate
const int SR = 44100;
const int T = 1/SR;
int repeat_count = 0; //number of repeat
float time_constant = 5;
bool fade_in = true;
bool fade_out_checked = false;

float amplitude = 1;


// ---------- Audio Mod Function Declarations -----------//

void CreateInterval();
void CreateTempFile(QString qs);
void showMessage(QString qs);
void MakeFileNames(); 
//void CreateFile();
//void CreateSinWave(float amp, float freq);
//void ChangeSpeed();
//void Amplify();
//void Repeat();
//void repeat();

// ---------- Audio Mod Definitions -----------//

MainWindow::~MainWindow()
{
    delete ui;
}

void CreateInterval(){
    start_index = start_time*SR;
    end_index = end_time*SR;

    //Loop through temp .wav file
    while((temp_vec.at(start_index) != 0 )|| (temp_vec.at(start_index) != -0 )){
        if(start_index == 0){break;} //continue looping
        start_index--;
    }

     while(temp_vec.at(end_index) != 0 || (temp_vec.at(end_index) != -0 )){
        if(end_index == 0){break;} //continue looping
        end_index++;
    }

    for(int i = start_index; i <= end_index; ++i){
       int temp = temp_vec.at(i);
       interval_vec.push_back(temp);
    }
}

void showMessage(QString qs){
    QMessageBox mBox;
    mBox.setText(qs);
    mBox.exec();
}

void CreateTempFile(QString qs)
{
    SF_INFO sfinfo;
    SNDFILE* in_file;
    sf_count_t count;
    sf_count_t tempSize = sfinfo.frames; //# of samples

    int sz = 0; //actual size
    int vector_sz = 0;

    std::string str(qs.toStdString());
    char* in_file_name = const_cast<char*>(str.c_str());
    in_file = sf_open(in_file_name, SFM_READ, &sfinfo);
    if(in_file == NULL){
        sf_close(in_file);
        qDebug() << "Empty File" << in_file;
    }

    count = sf_read_float(in_file, buffer, kcoef);
    while(count>0){
        sz = sz + count;
        std::vector<float> tempVec;
        for(int i = 0; i < kcoef; i++){
            vector_sz++;
            if(vector_sz > sz){break;}
            tempVec.push_back(buffer[i]);
        }
      std::copy(tempVec.begin(), tempVec.end(), std::back_inserter(audio_vec));
    }

   sz = tempSize;
   sf_close(in_file);
   temp_vec.clear();
   std::copy(audio_vec.begin(), audio_vec.end(),std::back_inserter(temp_vec));
}

//void CreateFile(){
//    const int format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
//    const int channels = 1; //mono
//    char* outF_name;

//    outF_name = const_cast<char*>(temp_file.toStdString().c_str());
//    SndfileHandle outfile(outF_name, SFM_WRITE, format, channels, SR);
//    if(!(outfile)){return;}
//    outfile.write(&temp_vec[0], temp_vec.size());
//}

void MakeFileNames(){
    
}

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
    snare->setMedia(QUrl::fromLocalFile("/Users/Izyl/Desktop/cmpt365/TermProject/Snares1.wav"));

    if(snare->state() == QMediaPlayer::PlayingState){snare->setPosition(0);}
    else if(snare->state() == QMediaPlayer::StoppedState){snare->play();}
}

void MainWindow::on_actionUndo_triggered()
{
    current_index--;
    temp_vec = audio_stack.at(current_index);
}

void MainWindow::on_actionRedo_triggered()
{
    current_index++;
    temp_vec = audio_stack.at(current_index);
}

void MainWindow::on_reverse_clicked(bool checked)
{
    //changed_something();
    if(checked){reverseFlag = true;}
    else{reverseFlag = false;}
}

void reverse(){
    std::vector<float> tempVec;
    for(int i = interval_vec.size()-1; i> -1; --i){
       tempVec.push_back(interval_vec.at(i));
    }
    interval_vec = tempVec;
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    //changed_something();
    if(checked){repeatFlag = true;}
    else{repeatFlag = false;}
}

void MainWindow::changes_applicable()
{
    changed = true;
    tested = false;
}

void MainWindow::enableRedoUndo()
{
   //
}

void repeat(){
    std::vector<float> tempVec;
    //for testing, repeat 2
    repeat_count = 2;
    for(int i = 0; i < repeat_count; ++i){
        for(auto sample: interval_vec){ tempVec.push_back(sample);}
    }
    interval_vec = tempVec;
}
