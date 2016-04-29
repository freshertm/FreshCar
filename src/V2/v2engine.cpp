#include "v2engine.h"

V2Engine::V2Engine()
{
}

V2Engine::~V2Engine()
{

}

void V2Engine::registerModule(IModule * module)
{
    _modules.append(module);
}

void V2Engine::unregisterModule(IModule *modulePtr)
{
    QMutableListIterator<IModule*> i(_modules);
    while (i.hasNext())
    {
        if (i.next() == modulePtr) {
            i.remove();
            return;
        }
    }
}

void V2Engine::addObject(WorldObject *object)
{
    _scene.append(object);
}

