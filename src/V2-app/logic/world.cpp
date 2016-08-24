#include "world.h"
#include "v2engine.h"
#include "v2object.h"
#include "objects/brick.h"

World::World(V2Engine *engine, QObject *parent) :
    QObject(parent),
    _engine(engine)
{

}
