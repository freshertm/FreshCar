#ifndef ENGINE_H
#define ENGINE_H

#include <QList>
#include "v2resource.h"
#include "v2event.h"
#include "v2eventhandler.h"
//#include <QObject>

class IModule;
class WorldObject;

class V2Scene;
class V2Engine: public V2ResourceContainer
{
    //Q_OBJECT
public:
    V2Engine();
    ~V2Engine();
    bool registerModule(IModule *);
    bool unregisterModule(IModule *);

    template <class T>
    T* module();

    void addObject(WorldObject * object);
    //void setScene(const V2Scene &scene)
private:
    QList<IModule*> _modules;
    QList<WorldObject*> _scene;

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
