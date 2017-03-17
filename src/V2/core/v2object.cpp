#include "v2object.h"
#include "v2module.h"

V2Object::V2Object(): _scale(1,1,1)
{
}

V2Object::~V2Object()
{   
}

void V2Object::setPosition(const glm::vec3 &newPosition)
{
    _position = newPosition;
    emit positionChanged(_position);
}

void V2Object::setRotation(const glm::vec3 &newRotation)
{
    _rotation = newRotation;
    emit rotationChanged(newRotation);
}

void V2Object::setScale(const glm::vec3 &newScale)
{
    _scale = newScale;
    emit scaleChanged(_scale);
}

const glm::vec3 &V2Object::position() const
{
    return _position;
}

const glm::vec3 &V2Object::rotation() const
{
    return _rotation;
}

const glm::vec3 &V2Object::scale() const
{
    return _scale;
}
