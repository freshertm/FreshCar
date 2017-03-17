#include "v2engine.h"
#include "v2module.h"
#include "v2scene.h"
#include "private/renderer.h"

V2Engine::V2Engine()
{
    setScene(QSharedPointer<V2Scene>::create());
    auto qwe = QSharedPointer<Renderer>::create();
    addModule(qwe);
}

V2Engine::~V2Engine()
{
}

QSharedPointer<V2Module>V2Engine::moduleByType(const std::type_index &ti)
{
    if (_modulesMap.contains(ti))
        return _modulesMap[ti];
    return QSharedPointer<V2Module>();
}

bool V2Engine::initModule(QSharedPointer<V2Module> &module)
{
    if (module.isNull()) {
        return false;
    }
    /*foreach(auto & type, module->dependencies())
    {
        auto &subModule = moduleByType(type);
        if (!subModule) {
            qDebug() << "Cannot find module \"" << type.name() << "\"";
            return false;
        }
        if (!initModule(subModule)){
            return false;
        }
    }*/
    if (module->init(sharedFromThis())) {
        emit moduleInitialized(module);
        return true;
    }
    return false;
}

QSharedPointer<V2Scene> V2Engine::scene()
{
    return _scene;
}

bool V2Engine::unregisterModule(std::type_index & t)
{
    auto module = moduleByType(t);
    if (module.isNull()) {
        return false;
    }
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

void V2Engine::setScene(QSharedPointer<V2Scene> & scene)
{
    if (scene.isNull()){
        scene = QSharedPointer<V2Scene>::create();
    }
    _scene = scene;
    emit sceneChanged(_scene);
}

