#ifndef ENGINE_H
#define ENGINE_H

#include <QList>

class IModule;
class WorldObject;
class Engine
{
public:
    Engine();
    ~Engine();
    void registerModule(IModule *);
    void unregisterModule(IModule *);

    void addObject(WorldObject *);
    void removeObject(WorldObject *);

private:
    QList<IModule*> _modules;

};

#endif // ENGINE_H
