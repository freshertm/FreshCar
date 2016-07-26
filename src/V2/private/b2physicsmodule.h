#ifndef B2PHYSICSMODULE_H
#define B2PHYSICSMODULE_H

#include "v2physicsmodule.h"
#include "Box2D.h"

class V2Engine;
class B2PhysicsModule: public V2PhysicsModule
{
public:
    B2PhysicsModule();
    virtual ~B2PhysicsModule();
    virtual bool init(V2Engine*);
    virtual bool stop(V2Engine*);

private:

};

#endif // B2PHYSICSMODULE_H
