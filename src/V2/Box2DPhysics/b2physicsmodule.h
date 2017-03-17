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
    virtual bool enableModule(QSharedPointer<V2Engine>&);
    virtual bool disableModule(QSharedPointer<V2Engine>&);
    virtual bool initModule(QSharedPointer<V2Engine>&);
    virtual bool stopModule(QSharedPointer<V2Engine>&);

private slots:
    void onSceneChanged(QSharedPointer<V2Scene> &scene);
    void onObjectAddedToScene(const QSharedPointer<V2Object> object);

    bool runThread();
    bool stopThread();

    void onThreadRun();
    void onThreadStop();

    void performCalcs();

private:
    QSharedPointer<b2World> _world;
    QMap<QSharedPointer<V2Object> , QSharedPointer<Box2DPhysicsRigidBody>> _cachedObjectData;
    //QThread _thread;
    bool isRunning;

    QElapsedTimer _timer;
};

#endif // B2PHYSICSMODULE_H
