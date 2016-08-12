#ifndef B2PHYSICSMODULE_H
#define B2PHYSICSMODULE_H

#include "v2physicsmodule.h"
#include <memory>
#include "Box2D.h"
#include <QThread>
#include "b2physicsrigidbody.h"
#include <QHash>

class V2Engine;
class V2Object;
class V2Scene;
class B2PhysicsModule: public V2Physics
{
    Q_OBJECT
public:
    B2PhysicsModule();
    virtual ~B2PhysicsModule();

    virtual bool enableModule(V2Engine*);
    virtual bool disableModule(V2Engine*);

private slots:
    void onSceneChanged(V2Scene *);
    void onObjectAddedToScene(V2Object *);

    bool runThread();
    bool stopThread();

    void onThreadRun();
    void onThreadStop();

private:
    std::shared_ptr<b2World> _world;
    QHash<V2Object*, std::shared_ptr<B2PhysicsRigidBody> > _cachedObjectData;
    QThread _thread;
    bool isRunning;
};

#endif // B2PHYSICSMODULE_H
