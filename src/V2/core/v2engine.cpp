#include "v2engine.h"
#include "v2module.h"
#include "v2scene.h"
#include "private/renderer.h"
#include "private/b2physicsmodule.h"

V2Engine::V2Engine()
{
    setScene(0);   
    addModule(new Renderer);
    addModule(new B2PhysicsModule);
}

V2Engine::~V2Engine()
{
}

V2Scene *V2Engine::scene()
{
    return _scene;
}

bool V2Engine::addAndInitModule(V2Module * module)
{
    addModule(module);
    return module->init(this);
}

bool V2Engine::unregisterModule(V2Module *modulePtr)
{
    if (0 != modulePtr->refs())
    {
        return false;
    }

    QMutableListIterator<V2Module*> i(_modules);
    while (i.hasNext())
    {
        if (i.next() == modulePtr) {
            i.remove();
            return true;
        }
    }
    return false;
}

void V2Engine::setScene(V2Scene *scene)
{
    if (scene == nullptr){
        scene = new V2Scene();
    }
    _scene = scene;
    emit sceneChanged(_scene);
}

void V2Engine::addModule(V2Module *module)
{
    _modules.append(module);
    emit moduleAdded(module);
}
