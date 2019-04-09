#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow> // remove
#include <QVector>
#include <QThread>
#include <QTimer>
#include <QObject>

#include "track.h"
#include "serializer.h"

class SoundEffectWidget;
class playback;

namespace Ui {
class MainWindow; // remove
}

class MainWindow : public QMainWindow // modify
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool eventFilter(QObject* watched, QEvent* event) override;
    void initSoundEffectWidgets();

private slots:
    void playSoundEffect(int soundId);
    void clearPlayback();
    void stopPlayback();

    void saveProject();
    void loadProject();

private:
    void updateState(const Track::State& state);
    void startDisplayTimer();
    void updateDisplayTime();
    void stopDisplayTimer();
    void startPlayback();

    QString formatTime(long ms);

private:
    Ui::MainWindow *ui; // remove
    Track mTrack;
    QVector<SoundEffectWidget*> mSoundEffectWidgets;
    playback* mplayback;
    QThread* mPlaybackThread;
    QTimer mDisplayTimer;
    std::unique_ptr<Serializer> mSerializer;
};

#endif // MAINWINDOW_H
