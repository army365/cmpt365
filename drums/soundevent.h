#ifndef SOUNDEVENT_H
#define SOUNDEVENT_H

#include <QtGlobal>
#include "canserialize.h"

class SoundEvent : public CanSerialize
{
public:
    SoundEvent(qint64 timestamp = 0, int soundId = 0);
    ~SoundEvent();

    QVariant toVariant() const override;
    void fromVariant(const QVariant& variant) override;

    qint64 timestamp;
    int soundId;
};

#endif // SOUNDEVENT_H
