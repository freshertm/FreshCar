#ifndef B2PHYSICSRIGIDBODY_H
#define B2PHYSICSRIGIDBODY_H

#include "v2rigidbody.h"

#include "Box2D.h"
#include <memory>
#include "glm/glm.hpp"

class B2PhysicsRigidBody: public V2RigidBody
{
public:
    B2PhysicsRigidBody(std::shared_ptr<b2World> &, glm::vec2 & position, float angle);
    virtual ~B2PhysicsRigidBody();

    glm::vec2 position();
    float angle();
private:
    b2Body *_body;
    std::shared_ptr<b2World> _world;
};

#endif // B2PHYSICSRIGIDBODY_H
