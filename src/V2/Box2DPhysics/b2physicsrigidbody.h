#ifndef B2PHYSICSRIGIDBODY_H
#define B2PHYSICSRIGIDBODY_H

#include "v2resource.h"

#include "Box2D/Box2D.h"
#include <memory>
#include "glm/glm.hpp"

class Box2DPhysicsRigidBody: public V2Resource
{
public:
    Box2DPhysicsRigidBody(std::shared_ptr<b2World> &, glm::vec2 & position, float angle);
    virtual ~Box2DPhysicsRigidBody();

    glm::vec2 position();
    float angle();
private:
    b2Body *_body;
    std::shared_ptr<b2World> _world;
};

#endif // B2PHYSICSRIGIDBODY_H
