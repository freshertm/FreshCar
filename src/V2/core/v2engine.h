#ifndef ENGINE_H
#define ENGINE_H

#include <QList>
#include "v2resource.h"
#include <QObject>
#include "v2scene.h"
#include <typeindex>
#include <memory>
#include <QMap>

class V2Module;
class V2Object;

class V2Engine: public QObject
{
    Q_OBJECT
public:
    V2Engine();
    ~V2Engine();
    template <class T> std::shared_ptr<T> module();
    std::shared_ptr<V2Module> moduleByType(const std::type_index & ti);

    template <class T> bool initModule();

    bool initModule(std::shared_ptr<V2Module> module);

    template <class T> bool stopModule(){}

    template <class T> bool enableModule();
    template <class T> bool disableModule();

    V2Scene * scene();

    template <class T>void addModule(std::shared_ptr<T>);

public slots:
    void setScene(V2Scene *scene);
    //void addModule(V2Module*);

    bool unregisterModule(V2Module *);
signals:
    void sceneChanged(V2Scene *scene);
    void moduleAdded(V2Module *);
    void moduleInitialized(V2Module*);

private:
    QMap<std::type_index, std::shared_ptr<V2Module> > _modulesMap;
    //QList<V2Module*> _modules;
    V2Scene *_scene;
};

template <class T>
std::shared_ptr<T> V2Engine::module()
{
    return std::dynamic_pointer_cast<T>(moduleByType(typeid(T)));
}


template <class T> bool V2Engine::initModule()
{
    auto m = this->module<T>();
    return initModule(m);
}


template <class T> bool V2Engine::enableModule()
{
    auto m = this->module<T>();
    if (m) {
        return m->enable(this);
    }
    return false;
}

template <class T> bool V2Engine::disableModule()
{
    auto m = this->module<T>();
    if (m) {
        return m->disable(this);
    }
    return false;
}

template <class T> void V2Engine::addModule(std::shared_ptr<T> module)
{
    if (!module) {
        return;
    }

    std::shared_ptr<V2Module> genericModule = std::dynamic_pointer_cast<V2Module>(module);

    _modulesMap[typeid(T)] = genericModule;
    emit moduleAdded(genericModule.get());
}

#endif // ENGINE_H
