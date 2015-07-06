#ifndef WORLD_H
#define WORLD_H

#include <QElapsedTimer>
#include "Box2D.h"
#include "car.h"
#include <QVariant>
#include <QHash>
#include "worldproperties.h"
#include <QObject>

class World: public QObject
{
    Q_OBJECT
public:

    enum WheelGenomeIndexes{
        WheelVertice =0,
        WheelRadius  =1,
        WheelSpeed   =2,
        WheelTorqueCoeff = 3
    };

    World(long seed);

    typedef QVector<Car*> CarList;
    void step();

    CarList carList();
    b2World * b2world();

    const WorldProperties *worldProperties() const;
    WorldProperties * worldPropertiesForChange();

    double currentTopCarPosition();
    double absoluteMaxDistance();
    quint16 fullGenomeLength();

    quint16 currentPopulation();

    quint32 generationNumber();
    quint32 generationNumberTopRecord();

    double averageTrianglesInCar();
    double averageWheelsInCar();

    CarGenome topGenome();

    typedef QPair<double , CarGenome> GenomeTopListRecord;
    typedef QList< GenomeTopListRecord > GenomeTopList;
    const GenomeTopList topList() const;

public slots:
    void addRandomCar();

    void saveState(const QString & filename);
    void loadState(const QString & filename);

signals:
    void newGeneration();

private:
    void addToTopList(double result, const CarGenome &genome);
    void createRandomGround();
    void sex();
    void addCarFromGenome(const CarGenome &genome);

    double createRandomDouble(double min, double max);
    double validateDouble(double value, double min, double max);
    double mutateDouble(double value, double min, double max, double rate);


    b2World * world;
    CarList _carList;
    QElapsedTimer timer;
    WorldProperties properties;
    CarGenome createRandomGenome();
    CarGenome validateGenome(const CarGenome&);
    void mixGenome(const CarGenome &parentA, const CarGenome &parentB, CarGenome &childA, CarGenome &childB);
    CarGenome makeChild(const CarGenome &parentA, const CarGenome &parentB);

    void mutateGenome(CarGenome & genome);

    static bool topListRecordLessThan(const GenomeTopListRecord &,const GenomeTopListRecord &);
    GenomeTopList _topList;

    quint32 _generationNumber;
    quint32 _generationNumberTopRecord;
    double  _topRecord;

};

#endif // WORLD_H
