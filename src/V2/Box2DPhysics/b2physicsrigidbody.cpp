#include "b2physicsrigidbody.h"
#include "Box2D.h"
using namespace std;

Box2DPhysicsRigidBody::Box2DPhysicsRigidBody(std::shared_ptr<b2World> & world, glm::vec2 & position, float angle):
    _world(world)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.angle = angle;

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
