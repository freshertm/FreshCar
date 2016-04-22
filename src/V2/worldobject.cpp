#include "worldobject.h"
#include "imodule.h"

WorldObject::WorldObject()
{
}

WorldObject::~WorldObject()
{
    QList<IModule*> keys = _moduleData.keys();
    foreach(IModule* m, keys)
    {
        m->removeObject(this);
        delete moduleData(m);
    }
}

void WorldObject::setModuleData(IModule *m, ObjectData *d)
{
    d->setParent(this);
    _moduleData.insert(m,d);
}

ObjectData *WorldObject::moduleData(IModule *m)
{
    return _moduleData[m];
}

const Geometry *WorldObject::geometry()
{
    //return static_cast<const Geometry*> (getEngineResource(EngineResource::GeometryData));
    return nullptr;
}



QList<ModuleClass> ObjectData::moduleClasses()
{
    return _moduleClasses;
}

void ObjectData::setModuleClasses(const QList<ModuleClass> &classes)
{
    _moduleClasses = classes;
}
