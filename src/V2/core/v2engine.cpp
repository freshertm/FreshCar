#include "v2engine.h"
#include "v2module.h"
#include "v2scene.h"
#include "private/renderer.h"

V2Engine::V2Engine()
{
    setScene(0);   
    addModule(new Renderer);
}

V2Engine::~V2Engine()
{
}

V2Module *V2Engine::moduleByType(const std::type_index &ti)
{
    foreach(V2Module *module, _modules)
    {
        if (std::type_index(typeid(module)) == ti) {
            return module;
        }
    }
    return nullptr;
}

bool V2Engine::initModule(V2Module *module)
{
    if (!module) {
        return false;
    }
    foreach(auto & type, module->dependencies())
    {
        auto * subModule = moduleByType(type);
        if (!subModule) {
            qDebug() << "Cannot find module \"" << type.name() << "\"";
            return false;
        }
        if (!initModule(subModule)){
            return false;
        }
    }
    if (module->init(this)) {
        emit moduleInitialized(module);
        return true;
    }
    return false;
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
