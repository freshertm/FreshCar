#include "gameobject.h"


GameObject::GameObject()
{

}

void GameObject::setPosition(const QVector3D &newPosition)
{
    _position = newPosition;
    emit positionChanged(newPosition);
}

void GameObject::setRotation(const QQuaternion &rotation)
{
    _rotation = rotation;
    emit rotationChanged(rotation);
}

QVector3D GameObject::position()
{
    return _position;
}

QQuaternion GameObject::rotation()
{
    return _rotation;
}
