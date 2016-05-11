#include "v2engine.h"
#include "imodule.h"
#include "v2scene.h"

V2Engine::V2Engine()
{
    setScene(0);
}

V2Engine::~V2Engine()
{

}

V2Scene *V2Engine::scene()
{
    return _scene;
}

bool V2Engine::registerModule(IModule * module)
{
    if (!module->init(this))
    {
        return false;
    }

    _modules.append(module);
    return true;
}

bool V2Engine::unregisterModule(IModule *modulePtr)
{
    if (0 != modulePtr->refs())
    {
        return false;
    }

    QMutableListIterator<IModule*> i(_modules);
    while (i.hasNext())
    {
        if (i.next() == modulePtr) {
            i.remove();
            return true;
        }
    }
    return false;
}

void V2Engine::addObject(WorldObject *object)
{
    //_scene.append(object);
}

void V2Engine::setScene(V2Scene *scene)
{
    if (scene == nullptr){
        scene = new V2Scene();
    }
    _scene = scene;
    emit sceneChanged(_scene);
}

