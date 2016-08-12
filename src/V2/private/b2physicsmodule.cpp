#include "b2physicsmodule.h"
#include "v2engine.h"

B2PhysicsModule::B2PhysicsModule():
    _world(std::make_shared<b2World>(b2Vec2(0,-10))),
    isRunning(false)
{
    connect(&_thread, &QThread::started, this, &B2PhysicsModule::onThreadRun);
    connect(&_thread, &QThread::finished, this, &B2PhysicsModule::onThreadStop);
    this->moveToThread(&_thread);
}

B2PhysicsModule::~B2PhysicsModule()
{
    stopThread();
}

bool B2PhysicsModule::init(V2Engine * engine)
{
    return runThread();
}

bool B2PhysicsModule::stop(V2Engine *)
{
    return stopThread();
}

void B2PhysicsModule::onSceneChanged(V2Scene *)
{

}

void B2PhysicsModule::onObjectAddedToScene(V2Object * object)
{
    //_cachedObjectData[object] =
}

bool B2PhysicsModule::runThread()
{
    if (isRunning) {
        return false;
    }

    isRunning = true;
    _thread.start();
    return true;
}

bool B2PhysicsModule::stopThread()
{
    if (isRunning){
        _thread.quit();
        _thread.wait();
    }
    return true;
}

void B2PhysicsModule::onThreadRun()
{
    while (isRunning){

    }
}

void B2PhysicsModule::onThreadStop()
{
    isRunning = false;
}
