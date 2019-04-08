#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QObject>
#include <QAtomicInteger>

class Track;

class playback : public QObject
{
    Q_OBJECT
public:
    explicit playback(const Track& track, QObject *parent = 0);

signals:
    void playSound(int soundId);
    void trackFinished();

public slots:
    void play();
    void stop();

private:
    const Track& mTrack;
    QAtomicInteger<bool> mIsPlaying;
};

#endif // PLAYBACK_H
