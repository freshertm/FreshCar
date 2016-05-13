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

void WorldObject::setPosition(const glm::vec3 &newPosition)
{
    _position = newPosition;
    emit positionChanged(_position);
}

void WorldObject::setRotation(const glm::vec3 &newRotation)
{
    _rotation = newRotation;
    emit rotationChanged(newRotation);
}

void WorldObject::setScale(const glm::vec3 &newScale)
{
    _scale = newScale;
    emit scaleChanged(_scale);
}

const glm::vec3 &WorldObject::position()
{
    return _position;
}

const glm::vec3 &WorldObject::rotation()
{
    return _rotation;
}

const glm::vec3 &WorldObject::scale()
{
    return _scale;
}
