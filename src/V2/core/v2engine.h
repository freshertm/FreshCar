#ifndef ENGINE_H
#define ENGINE_H

#include <QList>
#include "v2resource.h"
#include <QObject>
#include "v2scene.h"
#include <typeindex>

class V2Module;
class V2Object;

class V2Engine: public QObject
{
    Q_OBJECT
public:
    V2Engine();
    ~V2Engine();
    template <class T> T* module();
    V2Module * moduleByType(const std::type_index & ti);
    template <class T> bool initModule();
    bool initModule(V2Module *module);

    template <class T> bool stopModule(){}

    template <class T> bool enableModule();
    template <class T> bool disableModule();

    V2Scene * scene();

public slots:
    void setScene(V2Scene *scene);
    void addModule(V2Module*);
    bool addAndInitModule(V2Module *);
    bool unregisterModule(V2Module *);
signals:
    void sceneChanged(V2Scene *scene);
    void moduleAdded(V2Module *);
    void moduleInitialized(V2Module*);

private:
    QList<V2Module*> _modules;
    V2Scene *_scene;
};

template <class T>
T* V2Engine::module()
{
    foreach(V2Module* module, _modules)
    {
        T* specificModule = dynamic_cast<T*>(module);
        if (specificModule)
        {
            return specificModule;
        }
    }
    return nullptr;
}


template <class T> bool V2Engine::initModule()
{
    T* m = this->module<T>();
    return initModule(m);
}


template <class T> bool V2Engine::enableModule()
{
    T* m = this->module<T>();
    if (m) {
        return m->enable(this);
    }
    return false;
}

template <class T> bool V2Engine::disableModule()
{
    T* m = this->module<T>();
    if (m) {
        return m->disable(this);
    }
    return false;
}

#endif // ENGINE_H
