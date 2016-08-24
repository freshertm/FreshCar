#include "b2physicsmodule.h"
#include "v2engine.h"
#include "QApplication"

#include "b2physicsrigidbody.h"
#include "v2object.h"

#include <QTimer>

B2PhysicsModule::B2PhysicsModule():
    _world(std::make_shared<b2World>(b2Vec2(0,-10))),
    isRunning(false)
{
    connect(&_thread, &QThread::started, this, &B2PhysicsModule::onThreadRun);
    connect(&_thread, &QThread::finished, this, &B2PhysicsModule::onThreadStop);
}

B2PhysicsModule::~B2PhysicsModule()
{
    stopThread();
}

bool B2PhysicsModule::enableModule(V2Engine *engine)
{
    onSceneChanged(engine->scene());
    connect(engine->scene(), &V2Scene::objectAdded, this, &B2PhysicsModule::onObjectAddedToScene);
    return runThread();
}

bool B2PhysicsModule::disableModule(V2Engine *)
{
    return stopThread();
}

bool B2PhysicsModule::initModule(V2Engine * engine)
{
    connect(engine, &V2Engine::sceneChanged, this, &B2PhysicsModule::onSceneChanged);
    return true;
}

bool B2PhysicsModule::stopModule(V2Engine * engine)
{
    disconnect(engine, &V2Engine::sceneChanged, this, &B2PhysicsModule::onSceneChanged);
    return true;
}

void B2PhysicsModule::onSceneChanged(V2Scene * scene)
{
    _cachedObjectData.clear();
    foreach(V2Object *obj, scene->objects())
    {
        onObjectAddedToScene(obj);
    }
}

void B2PhysicsModule::onObjectAddedToScene(V2Object * object)
{
    V2RigidBody * rb = object->resource<V2RigidBody>();

    if (nullptr == rb){
        return;
    }

    auto ptr = std::make_shared<B2PhysicsRigidBody>(_world, glm::vec2(object->position()), object->rotation().z);
    _cachedObjectData[object] = ptr;
}

bool B2PhysicsModule::runThread()
{
    if (isRunning) {
        return false;
    }

    isRunning = true;
    _thread.start();
    this->moveToThread(&_thread);
    return true;
}

bool B2PhysicsModule::stopThread()
{
    if (isRunning){
        this->moveToThread(QApplication::instance()->thread());
        _thread.quit();
        _thread.wait();
    }
    return true;
}

void B2PhysicsModule::onThreadRun()
{
    _timer.start();
    performCalcs();
}

void B2PhysicsModule::onThreadStop()
{
    isRunning = false;
}

void B2PhysicsModule::performCalcs()
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
        QTimer::singleShot(1, this, &B2PhysicsModule::performCalcs);
    }
}
