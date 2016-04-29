#ifndef IMODULE_H
#define IMODULE_H

#include <QList>

class ObjectData;
class WorldObject;

class ModuleData{};
class V2Engine;
class IModule
{
public:
    IModule(){}
    virtual ~IModule(){}

    virtual void init(V2Engine*){}

    void addObject(WorldObject*);
    void removeObject(WorldObject*);

    virtual void processing();
private:
    virtual void initObjectData(WorldObject *){}
    virtual void processObject(WorldObject*){}

protected:
    QList<WorldObject*> _objects;
};

#endif // IMODULE_H

