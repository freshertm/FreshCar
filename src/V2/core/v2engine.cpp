#include "v2engine.h"
#include "v2module.h"
#include "v2scene.h"
#include "private/renderer.h"

V2Engine::V2Engine()
{
    setScene(0);   
    addModule(std::make_shared<Renderer>());
}

V2Engine::~V2Engine()
{
}

std::shared_ptr<V2Module>V2Engine::moduleByType(const std::type_index &ti)
{
    if (_modulesMap.contains(ti))
        return _modulesMap[ti];
    return std::shared_ptr<V2Module>();
}

bool V2Engine::initModule(std::shared_ptr<V2Module> module)
{
    if (!module) {
        return false;
    }
    foreach(auto & type, module->dependencies())
    {
        auto &subModule = moduleByType(type);
        if (!subModule) {
            qDebug() << "Cannot find module \"" << type.name() << "\"";
            return false;
        }
        if (!initModule(subModule)){
            return false;
        }
    }
    if (module->init(this)) {
        emit moduleInitialized(module.get());
        return true;
    }
    return false;
}

V2Scene *V2Engine::scene()
{
    return _scene;
}

bool V2Engine::unregisterModule(V2Module *modulePtr)
{
    /*if (0 != modulePtr->refs())
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
    }*/
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

