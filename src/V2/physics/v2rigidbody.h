#ifndef V2RIGIDBODY_H
#define V2RIGIDBODY_H

#include "v2resource.h"
#include "Box2D.h"
class V2RigidBody : public V2Resource
{
public:
    V2RigidBody(float mass=1.0f);
    virtual ~V2RigidBody(){}

    float getMass(){return _mass;}
    void setMass(float mass){_mass = mass;}

protected:
    float _mass;
};

#endif // V2RIGIDBODY_H
