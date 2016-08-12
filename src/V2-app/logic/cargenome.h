#ifndef CARGENOME_H
#define CARGENOME_H

#include <QVariant>
#include <QVector>

#include "v2resource.h"

//typedef QVector<QVariant> CarGenome;

class CarGenome: public QVector<QVariant>, V2Resource
{
    virtual ~CarGenome(){}
};

/*
struct CarGenome
{
    float width;
    float height;
    QVariantList serialize();
    void deserialize(QVariantList genome);
};*/

#endif // CARGENOME_H
