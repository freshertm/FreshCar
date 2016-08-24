#include "b2physicsrigidbody.h"
#include "Box2D.h"
using namespace std;

B2PhysicsRigidBody::B2PhysicsRigidBody(std::shared_ptr<b2World> & world, glm::vec2 & position, float angle):
    _world(world)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    bodyDef.angle = angle;

    _body = world->CreateBody(&bodyDef);
}

B2PhysicsRigidBody::~B2PhysicsRigidBody()
{
    _world->DestroyBody(_body);
}

glm::vec2 B2PhysicsRigidBody::position()
{
    b2Vec2 res = _body->GetPosition();
    return glm::vec2(res.x, res.y);
}

float B2PhysicsRigidBody::angle()
{
    return _body->GetAngle();
}
