#ifndef B2PHYSICSRIGIDBODY_H
#define B2PHYSICSRIGIDBODY_H

#include "Box2D/Box2D.h"
#include "glm/glm.hpp"
#include <QObject>
#include "v2rigidbody2d.h"

class Box2DPhysicsRigidBody: public QObject
{
    Q_OBJECT
public:
    Box2DPhysicsRigidBody(QSharedPointer<b2World> &, QSharedPointer<V2RigidBody2D> &rigidBody,  glm::vec2 & position, float angle);
    virtual ~Box2DPhysicsRigidBody();

    glm::vec2 position();
    float angle();
private slots:
    void onRigidBodyChanged();
private:
    b2Body *_body;
    QSharedPointer<b2World> _world;
};

#endif // B2PHYSICSRIGIDBODY_H
