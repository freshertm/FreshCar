#include "b2physicsmodule.h"
#include "v2engine.h"

B2PhysicsModule::B2PhysicsModule():
    _world(std::make_shared<b2World>(b2Vec2(0,-10)))
{

}

B2PhysicsModule::~B2PhysicsModule()
{

}

bool B2PhysicsModule::init(V2Engine * engine)
{
    //engine->scene();
    return false;
}

bool B2PhysicsModule::stop(V2Engine *)
{
    return false;
}

void B2PhysicsModule::onSceneChanged(V2Scene *)
{

}

void B2PhysicsModule::onObjectAddedToScene(V2Object * object)
{
    //_cachedObjectData[object] =
}
