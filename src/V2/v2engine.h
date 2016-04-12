#ifndef ENGINE_H
#define ENGINE_H


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
};

#endif // ENGINE_H
