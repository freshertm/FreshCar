#include "v2engine.h"
#include "imodule.h"

V2Engine::V2Engine()
{
}

V2Engine::~V2Engine()
{

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
            return;
        }
    }
}

void V2Engine::addObject(WorldObject *object)
{
    _scene.append(object);
}

