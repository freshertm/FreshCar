#include "v2scene.h"

V2Scene::V2Scene()
{

}

V2Scene::~V2Scene()
{

}

void V2Scene::addObject(V2Object *object)
{
    _objects.push_back(object);
    emit objectAdded(object);
}

const QList<V2Object *> V2Scene::objects()
{
    return _objects;
}

