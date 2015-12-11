#include "worldobject.h"

WorldObject::WorldObject()
{
}

WorldObject::~WorldObject()
{
}

void WorldObject::setModuleData(IModule *m, ObjectData *d)
{
    _moduleData.insert(m,d);
}

ObjectData *WorldObject::moduleData(IModule *m)
{
    return _moduleData[m];
}

