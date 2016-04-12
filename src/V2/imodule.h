#ifndef IMODULE_H
#define IMODULE_H

#include <QList>

class ObjectData;
class WorldObject;

class ModuleData{};

enum ModuleClass {
    ModuleClassUnknown = 0,
    ModuleClassRenderer,
    ModuleClassPhysics,

    ModuleClassCustom = 1000
};

class IModule
{
public:
    IModule(){}
    virtual ~IModule(){}

    void addObject(WorldObject*);
    void removeObject(WorldObject*);

    virtual void processing();

    virtual ModuleClass moduleClass(){return ModuleClassUnknown;}

private:
    virtual void initObjectData(WorldObject *)=0;
    virtual void processObject(WorldObject*)=0;

protected:
    QList<WorldObject*> _objects;
};

#endif // IMODULE_H

