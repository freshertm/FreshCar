#ifndef ENGINE_H
#define ENGINE_H

#include <QList>
#include "v2resource.h"
#include <QObject>
#include "v2scene.h"

class V2Module;
class V2Object;

class V2Engine: public QObject
{
    Q_OBJECT
public:
    V2Engine();
    ~V2Engine();
    template <class T> T* module();
    template <class T> bool initModule();

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
    if (m) {
        if (m->init(this)) {
            emit moduleInitialized(m);
            return true;
        }
    }
    return false;
}

#endif // ENGINE_H
