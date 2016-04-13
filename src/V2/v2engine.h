#ifndef ENGINE_H
#define ENGINE_H

#include <QList>

class IModule;
class WorldObject;

class V2Scene;
class V2Engine
{
public:
    V2Engine();
    ~V2Engine();
    void registerModule(IModule *);
    void unregisterModule(IModule *);

    void addObject(WorldObject * object);
    //void setScene(const V2Scene &scene);

private:
    QList<IModule*> _modules;
    QList<WorldObject*> _scene;

};

#endif // ENGINE_H
