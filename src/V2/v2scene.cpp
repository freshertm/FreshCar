#include "v2scene.h"

V2Scene::V2Scene()
{

}

V2Scene::~V2Scene()
{

}

void V2Scene::addObject(WorldObject *object)
{
    _objects.push_back(object);
}

const QList<WorldObject *> V2Scene::objects()
{
    return _objects;
}

