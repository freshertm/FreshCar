#ifndef IMODULE_H
#define IMODULE_H

#include <QList>

class ObjectData;
class WorldObject;
class IModule
{
public:
    IModule(){}
    virtual ~IModule(){}

    void addObject(WorldObject*);
    void removeObject(WorldObject*);

    void processing();

private:
    virtual ObjectData *createObjectData(WorldObject*)=0;
    virtual void processObject(WorldObject*)=0;

    QList<WorldObject*> _objects;
};

#endif // IMODULE_H

