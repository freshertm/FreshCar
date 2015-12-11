#ifndef CAR_H
#define CAR_H

#include "cargenome.h"
#include "Box2D.h"
#include <QList>
#include <QObject>
class World;
struct Edge;

class Car: public QObject
{
    Q_OBJECT
public:
    Car(const CarGenome&,World * world, const b2Vec2 &position, double angle, quint32 generation);
    ~Car();
    const CarGenome&  genome() const;

    bool shouldKillMe(double time);
    double currentDistance();
    double topDistance();
    quint32 generation();
    quint16 triangles();
    quint16 wheels();

    quint16 vertices();

    b2Vec2 position();

    double mass();

private:
    bool hasMoveForward();
    double waitTime;
    World *world;
    b2Body * body;
    CarGenome carGenome;
    //b2Vec2 lastPosition;
    QList<b2Body*> bodyList;
    QList<b2Joint*> jointList;
    double maxPosition;
    quint32 _generation;
    quint16 _wheels;
    quint16 _triangles;
    quint16 _vertices;
};

#endif // CAR_H
