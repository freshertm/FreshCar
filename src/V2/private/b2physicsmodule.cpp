#include "b2physicsmodule.h"

B2PhysicsModule::B2PhysicsModule():
    _world(std::make_shared<b2World>(b2Vec2(0,-10)))
{

}

B2PhysicsModule::~B2PhysicsModule()
{

}
