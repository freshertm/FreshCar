#include "b2physicsmodule.h"
#include "v2engine.h"
#include <QApplication>

#include "b2physicsrigidbody.h"
#include "v2object.h"
#include "v2rigidbody2d.h"

#include <QTimer>

Q_DECLARE_METATYPE(QSharedPointer<V2Engine>);

Box2DPhysicsModule::Box2DPhysicsModule():
    _world(QSharedPointer<b2World>::create(b2Vec2(0,-10))),
    isRunning(false)
{
    qRegisterMetaType<QSharedPointer<V2Engine>>("QSharedPointer<V2Engine>");
    //connect(&_thread, &QThread::started, this, &Box2DPhysicsModule::onThreadRun);
    //connect(&_thread, &QThread::finished, this, &Box2DPhysicsModule::onThreadStop);
}

Box2DPhysicsModule::~Box2DPhysicsModule()
{
    stopThread();
}

bool Box2DPhysicsModule::enableModule(QSharedPointer<V2Engine>& engine)
{
    onSceneChanged(engine->scene());
    connect(engine->scene().data(), &V2Scene::objectAdded, this, &Box2DPhysicsModule::onObjectAddedToScene);
    return runThread();
}

bool Box2DPhysicsModule::disableModule(QSharedPointer<V2Engine>& engine)
{
    return stopThread();
}

bool Box2DPhysicsModule::initModule(QSharedPointer<V2Engine>& engine)
{
    connect(engine.data(), &V2Engine::sceneChanged, this, &Box2DPhysicsModule::onSceneChanged);
    return true;
}

bool Box2DPhysicsModule::stopModule(QSharedPointer<V2Engine> &engine)
{
    disconnect(engine.data(), &V2Engine::sceneChanged, this, &Box2DPhysicsModule::onSceneChanged);
    return true;
}

void Box2DPhysicsModule::onSceneChanged(QSharedPointer<V2Scene>& scene)
{
    _cachedObjectData.clear();
    foreach(auto &obj, scene->objects())
    {
        onObjectAddedToScene(obj);
    }
}

void Box2DPhysicsModule::onObjectAddedToScene(const QSharedPointer<V2Object> object)
{
    auto rb = object->agent<V2RigidBody2D>();
    if (rb.isNull()){
        return;
    }
    auto ptr = QSharedPointer<Box2DPhysicsRigidBody>::create(_world, rb, glm::vec2(object->position()), object->rotation().z);
    _cachedObjectData[object] = ptr;
}

bool Box2DPhysicsModule::runThread()
{
    if (isRunning) {
        return false;
    }

    isRunning = true;
    //_thread.start();
    //this->moveToThread(&_thread);
    onThreadRun();
    return true;
}

bool Box2DPhysicsModule::stopThread()
{
    onThreadStop();
    if (isRunning){
        //this->moveToThread(QApplication::instance()->thread());
       // _thread.quit();
       // _thread.wait();
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

    foreach(auto &object, _cachedObjectData.keys()){
        auto body = _cachedObjectData[object];
        object->setPosition(glm::vec3(body->position(), 0));
        glm::vec3 rotation = object->rotation();
        rotation.z = body->angle();
        object->setRotation(rotation);
    }

    if (isRunning){
        QTimer::singleShot(1, this, &Box2DPhysicsModule::performCalcs);
    }
}
