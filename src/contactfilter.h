#ifndef CONTACTFILTER_H
#define CONTACTFILTER_H

#include "Box2D.h"

class ContactFilter : public b2ContactFilter
{
public:
    ContactFilter(b2Body * ground);

    virtual bool ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB);

private:
    b2Body *ground;
    bool isGround(b2Fixture *);
};

#endif // CONTACTFILTER_H
