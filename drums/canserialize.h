#ifndef CANSERIALIZE_H
#define CANSERIALIZE_H

#include <QVariant>

class CanSerialize {
public:
    virtual ~CanSerialize() {}
    virtual QVariant toVariant() const = 0;
    virtual void fromVariant(const QVariant& variant) = 0;
};

#endif // CANSERIALIZE_H
