#ifndef B2PHYSICSMODULE_H
#define B2PHYSICSMODULE_H

#include "v2module.h"
#include <memory>
#include "Box2D/Box2D.h"
#include <QThread>
#include "b2physicsrigidbody.h"
#include <QMap>
#include <QElapsedTimer>

class V2Engine;
class V2Object;
class V2Scene;
class Box2DPhysicsModule: public V2Module
{
    Q_OBJECT
public:
    Box2DPhysicsModule();
    virtual ~Box2DPhysicsModule();

protected:
    virtual bool enableModule(V2Engine*);
    virtual bool disableModule(V2Engine*);
    virtual bool initModule(V2Engine *engine);
    virtual bool stopModule(V2Engine *);

private slots:
    void onSceneChanged(V2Scene *scene);
    void onObjectAddedToScene(V2Object *);

    bool runThread();
    bool stopThread();

    void onThreadRun();
    void onThreadStop();

    void performCalcs();

private:
    std::shared_ptr<b2World> _world;
    QMap<V2Object*, std::shared_ptr<Box2DPhysicsRigidBody> > _cachedObjectData;
    QThread _thread;
    bool isRunning;

    QElapsedTimer _timer;
};

#endif // B2PHYSICSMODULE_H
