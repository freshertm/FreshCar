#include "v2engine.h"

V2Engine::V2Engine()
{

}

V2Engine::~V2Engine()
{

}

void V2Engine::registerModule(IModule *)
{

}

void V2Engine::unregisterModule(IModule *)
{

}

void V2Engine::addObject(WorldObject *object)
{
    _scene.append(object);
}

