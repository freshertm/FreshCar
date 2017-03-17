#include "v2scene.h"

V2Scene::V2Scene()
{

}

V2Scene::~V2Scene()
{

}

void V2Scene::addObject(QSharedPointer<V2Object>& object)
{
    _objects.push_back(object);
    emit objectAdded(object);
}

const QList<QSharedPointer<V2Object> > V2Scene::objects()
{
    return _objects;
}

