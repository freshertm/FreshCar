#include "worldobject.h"
#include "imodule.h"

WorldObject::WorldObject(): _scale(1,1,1)
{
}

WorldObject::~WorldObject()
{   
}

const Geometry *WorldObject::geometry()
{
    return resource<Geometry>();
}

void WorldObject::setPosition(const Vector3 &newPosition)
{
    _position = newPosition;
    emit positionChanged(_position);
}

void WorldObject::setRotation(const Vector3 &newRotation)
{
    _rotation = newRotation;
    emit rotationChanged(newRotation);
}

void WorldObject::setScale(const Vector3 &newScale)
{
    _scale = newScale;
    emit scaleChanged(_scale);
}

const Vector3 &WorldObject::position()
{
    return _position;
}

const Vector3 &WorldObject::rotation()
{
    return _rotation;
}

const Vector3 &WorldObject::scale()
{
    return _scale;
}
