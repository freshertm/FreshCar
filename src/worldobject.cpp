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

const Geometry &WorldObject::geometryData() const
{
    return _geometry;
}

void WorldObject::setModuleData(IModule *m, ObjectData *d)
{
    _moduleData.insert(m,d);
}

ObjectData *WorldObject::moduleData(IModule *m)
{
    return _moduleData[m];
}

