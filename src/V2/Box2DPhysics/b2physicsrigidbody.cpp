#include "b2physicsrigidbody.h"
#include "Box2D/Box2D.h"
using namespace std;

Box2DPhysicsRigidBody::Box2DPhysicsRigidBody(QSharedPointer<b2World> & world,QSharedPointer<V2RigidBody2D> &rigidBody,  glm::vec2 & position, float angle):
    _world(world)
{
    b2BodyDef bodyDef;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.angle = angle;

    switch(rigidBody->bodyType()){
        case V2RigidBody2D::StaticBody: bodyDef.type = b2_staticBody; break;
        case V2RigidBody2D::KinematicBody: bodyDef.type = b2_kinematicBody; break;
        case V2RigidBody2D::DynamicBody: bodyDef.type = b2_dynamicBody; break;
    }

    _body = world->CreateBody(&bodyDef);
}

Box2DPhysicsRigidBody::~Box2DPhysicsRigidBody()
{
    _world->DestroyBody(_body);
}

glm::vec2 Box2DPhysicsRigidBody::position()
{
    b2Vec2 res = _body->GetPosition();
    return glm::vec2(res.x, res.y);
}

float Box2DPhysicsRigidBody::angle()
{
    return _body->GetAngle();
}

void Box2DPhysicsRigidBody::onRigidBodyChanged()
{
}
