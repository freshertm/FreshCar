#include "b2physicsmodule.h"
#include "v2engine.h"
#include "QApplication"

#include "b2physicsrigidbody.h"
#include "v2object.h"

#include <QTimer>

Box2DPhysicsModule::Box2DPhysicsModule():
    _world(std::make_shared<b2World>(b2Vec2(0,-10))),
    isRunning(false)
{
    connect(&_thread, &QThread::started, this, &Box2DPhysicsModule::onThreadRun);
    connect(&_thread, &QThread::finished, this, &Box2DPhysicsModule::onThreadStop);
}

Box2DPhysicsModule::~Box2DPhysicsModule()
{
    stopThread();
}

bool Box2DPhysicsModule::enableModule(V2Engine *engine)
{
    onSceneChanged(engine->scene());
    connect(engine->scene(), &V2Scene::objectAdded, this, &Box2DPhysicsModule::onObjectAddedToScene);
    return runThread();
}

bool Box2DPhysicsModule::disableModule(V2Engine *)
{
    return stopThread();
}

bool Box2DPhysicsModule::initModule(V2Engine * engine)
{
    connect(engine, &V2Engine::sceneChanged, this, &Box2DPhysicsModule::onSceneChanged);
    return true;
}

bool Box2DPhysicsModule::stopModule(V2Engine * engine)
{
    disconnect(engine, &V2Engine::sceneChanged, this, &Box2DPhysicsModule::onSceneChanged);
    return true;
}

void Box2DPhysicsModule::onSceneChanged(V2Scene * scene)
{
    _cachedObjectData.clear();
    foreach(V2Object *obj, scene->objects())
    {
        onObjectAddedToScene(obj);
    }
}

void Box2DPhysicsModule::onObjectAddedToScene(V2Object * object)
{
    //V2RigidBody * rb = object->resource<V2RigidBody>();

   /* if (nullptr == rb){
        return;
    }*/

   // auto ptr = std::make_shared<Box2DPhysicsRigidBody>(_world, glm::vec2(object->position()), object->rotation().z);
    //_cachedObjectData[object] = ptr;
}

bool Box2DPhysicsModule::runThread()
{
    if (isRunning) {
        return false;
    }

    isRunning = true;
    _thread.start();
    this->moveToThread(&_thread);
    return true;
}

bool Box2DPhysicsModule::stopThread()
{
    if (isRunning){
        this->moveToThread(QApplication::instance()->thread());
        _thread.quit();
        _thread.wait();
    }
    return true;
}

void Box2DPhysicsModule::onThreadRun()
{
    _timer.start();
    performCalcs();
}

void Box2DPhysicsModule::onThreadStop()
{
    isRunning = false;
}

void Box2DPhysicsModule::performCalcs()
{
    const int32 velocityIterations = 50;
    const int32 positionIterations = 50;
    _world->Step((double)_timer.elapsed() / 1000.0, velocityIterations, positionIterations);
    _timer.start();

    foreach(V2Object * obj, _cachedObjectData.keys()){
        auto body = _cachedObjectData[obj];
        obj->setPosition(glm::vec3(body->position(), 0));
        glm::vec3 rotation = obj->rotation();
        rotation.z = body->angle();
        obj->setRotation(rotation);
    }

    if (isRunning){
        QTimer::singleShot(1, this, &Box2DPhysicsModule::performCalcs);
    }
}
