#ifndef ENGINE_H
#define ENGINE_H

#include <QList>
#include "v2resource.h"
#include <QObject>
#include "v2scene.h"

class IModule;
class WorldObject;

class V2Engine: public QObject/*,  public V2ResourceContainer*/
{
    Q_OBJECT
public:
    V2Engine();
    ~V2Engine();
    template <class T> T* module();

    V2Scene * scene();

public slots:
    void addObject(WorldObject * object);
    void setScene(V2Scene *scene);

    bool registerModule(IModule *);
    bool unregisterModule(IModule *);
signals:
    void sceneChanged(V2Scene *scene);

private:
    QList<IModule*> _modules;
    V2Scene *_scene;
};

template <class T>
T* V2Engine::module()
{
    foreach(IModule* module, _modules)
    {
        T* specificModule = dynamic_cast<T*>(module);
        if (specificModule)
        {
            return specificModule;
        }
    }
    return nullptr;
}

#endif // ENGINE_H
