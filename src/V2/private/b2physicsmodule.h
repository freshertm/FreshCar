#ifndef B2PHYSICSMODULE_H
#define B2PHYSICSMODULE_H

#include "v2physicsmodule.h"
#include <memory>
#include "Box2D.h"
#include <QThread>

class V2Engine;
class B2PhysicsModule: public V2PhysicsModule
{
    Q_OBJECT
public:
    B2PhysicsModule();
    virtual ~B2PhysicsModule();
    virtual bool init(V2Engine*);
    virtual bool stop(V2Engine*);

private:
    std::shared_ptr<b2World> _world;
    QThread _thread;
};

#endif // B2PHYSICSMODULE_H
