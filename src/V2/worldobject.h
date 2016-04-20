#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <QMap>
#include <QList>
#include "geometry.h"
#include "engineresource.h"
#include "imodule.h"

class WorldObject;
class ObjectData
{
    //for setParent() function only which called from setModuleData();
    friend class WorldObject;
public:
    ObjectData(){}
    virtual ~ObjectData(){}
    virtual void process(){}
    QList<ModuleClass> moduleClasses();

    WorldObject * parent(){return _parent;}
protected:
    void setModuleClasses(const QList<ModuleClass> & classes);
private:
    void setParent(WorldObject* parent) {_parent = parent;}
    WorldObject *_parent;
    QList<ModuleClass> _moduleClasses;
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

    const Geometry * geometry();

private:
    QMap<EngineResource::Type, EngineResource *> _resources;
    QMap<IModule*, ObjectData*> _moduleData;
    Geometry _geometry;
};

#endif // WORLDOBJECT_H
