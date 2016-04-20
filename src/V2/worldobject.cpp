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

const EngineResource *WorldObject::getEngineResource(EngineResource::Type resourceType)
{
    return _resources[resourceType];
}

void WorldObject::setEngineResource(EngineResource::Type resourceType, EngineResource *res)
{
    _resources.insert(resourceType, res);
}

void WorldObject::destroyEngineResource(EngineResource::Type resourceType)
{
    EngineResource * res = _resources[resourceType];
    _resources.remove(resourceType);
    delete res;
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
