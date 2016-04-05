#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <QMap>
#include "geometry.h"
#include "engineresource.h"

class WorldObject;
class ObjectData
{
    //for setParent() function only which called from setModuleData();
    friend class WorldObject;
public:
    ObjectData(){}
    virtual ~ObjectData(){}
    virtual void process(){}

    WorldObject * parent(){return _parent;}
private:
    void setParent(WorldObject* parent) {_parent = parent;}
    WorldObject *_parent;
};



class IModule;
class WorldObject
{
public:
    WorldObject();
    ~WorldObject();
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

    const EngineResource * getEngineResource(EngineResource::Type resourceType);
    void setEngineResource(EngineResource::Type resourceType, EngineResource *res);
    void destroyEngineResource(EngineResource::Type resourceType);

    void setModuleData(IModule*, ObjectData*);
    ObjectData *moduleData(IModule*);

private:
    QMap<EngineResource::Type, EngineResource *> _resources;
    QMap<IModule*, ObjectData*> _moduleData;
    Geometry _geometry;
};

#endif // WORLDOBJECT_H
