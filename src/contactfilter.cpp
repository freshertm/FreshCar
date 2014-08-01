#include "contactfilter.h"

ContactFilter::ContactFilter(b2Body *ground): ground(ground)
{

}

bool ContactFilter::ShouldCollide(b2Fixture *fixtureA, b2Fixture *fixtureB)
{
    if ((!isGround(fixtureA)) && (!isGround(fixtureB))) return false;

    const b2Filter& filterA = fixtureA->GetFilterData();
    const b2Filter& filterB = fixtureB->GetFilterData();
    if (filterA.groupIndex == filterB.groupIndex && filterA.groupIndex != 0)
    {
      return filterA.groupIndex > 0;
    }
    bool collide = (filterA.maskBits & filterB.categoryBits) != 0 &&
                   (filterA.categoryBits & filterB.maskBits) != 0;
    return collide;
}

bool ContactFilter::isGround(b2Fixture * fixture)
{
    for (b2Fixture* f = ground->GetFixtureList(); f; f = f->GetNext())
    {
        if (fixture == f) return true;
    }
    return false;

}
