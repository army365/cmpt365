#include "finalserializer.h"

#include <QFile>
#include <QDataStream>

FinalSerializer::FinalSerializer() :
    Serializer()
{
}

void FinalSerializer::save(const CanSerialize& CanSerialize, const QString& filepath, const QString& /*rootName*/)
{
    QFile file(filepath);
    file.open(QFile::WriteOnly);
    QDataStream dataStream(&file);
    dataStream << CanSerialize.toVariant();
    file.close();
}

void FinalSerializer::load(CanSerialize& CanSerialize, const QString& filepath)
{
    QFile file(filepath);
    file.open(QFile::ReadOnly);
    QDataStream dataStream(&file);
    QVariant variant;
    dataStream >> variant;
    CanSerialize.fromVariant(variant);
    file.close();
}
