#ifndef CARGENOME_H
#define CARGENOME_H

#include <QVariant>
#include <QVector>


typedef QVector<QVariant> CarGenome;

/*
struct CarGenome
{
    float width;
    float height;
    QVariantList serialize();
    void deserialize(QVariantList genome);
};*/

#endif // CARGENOME_H
