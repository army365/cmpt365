#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <QString>

#include "canserialize.h"

class Serializer
{
public:
    virtual ~Serializer() {}

    virtual void save(const CanSerialize& CanSerialize, const QString& filepath, const QString& rootName = "") = 0;
    virtual void load(CanSerialize& CanSerialize, const QString& filepath) = 0;
};

#endif // SERIALIZER_H
