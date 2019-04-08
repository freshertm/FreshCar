#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Box2D/Box2D.h"
#include <Qt3DRender>

class GameObject
{
public:
    GameObject();

    QVector3D position();
    QQuaternion rotation();

public slots:
    void setPosition(const QVector3D& newPosition);
    void setRotation(const QQuaternion& rotation);

signals:
    void positionChanged(const QVector3D& newPosition);
    void rotationChanged(const QQuaternion& rotation);

private:
    QVector3D _position;
    QQuaternion _rotation;
};

#endif // GAMEOBJECT_H
