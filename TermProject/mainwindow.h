#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QPixmap>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <QMediaPlayer>
#include <QAudioFormat>
#include <QDebug>
#include <QString>
#include <QDialog>
#include <QUrl>

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //open


    //should play the tracks together
    void on_playButton_clicked();
    void on_stopButton_clicked();
    void on_pauseButton_clicked(int position);
    void on_sliderProgress_sliderMoved(int position);
    void on_sliderVolume_sliderMoved(int position);
    //position within recording
    void on_positionChanged(qint64 position);
    //duration of recording, set a max
    void on_durationChanged(qint64 position);
    void on_Snare_clicked();

    //Audio Format

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();


private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QMediaPlayer* snare;
};

#endif // MAINWINDOW_H
