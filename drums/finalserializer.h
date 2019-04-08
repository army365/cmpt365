#ifndef FINALSERIALIZER_H
#define FINALSERIALIZER_H

#include "serializer.h"

class FinalSerializer : public Serializer
{
public:
    FinalSerializer();

    void save(const CanSerialize& canserialize, const QString& filepath, const QString& rootName) override;
    void load(CanSerialize& canserialize, const QString& filepath) override;
};


#endif // FINALSERIALIZER_H
