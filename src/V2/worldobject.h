#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <QMap>
#include <QList>
#include "geometry.h"
#include "imodule.h"
#include "v2resource.h"

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
class WorldObject: public V2ResourceContainer
{
public:
    WorldObject();
    ~WorldObject();
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

    void setModuleData(IModule*, ObjectData*);
    ObjectData *moduleData(IModule*);

    const Geometry * geometry();

private:   
    QMap<IModule*, ObjectData*> _moduleData;
};

#endif // WORLDOBJECT_H
