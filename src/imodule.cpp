#include "imodule.h"

#include "worldobject.h"

void IModule::addObject(WorldObject *obj)
{
    ObjectData * objData = createObjectData(obj);
    obj->setModuleData(this,objData);
}

void IModule::removeObject(WorldObject * obj)
{
    for ( QList<WorldObject*>::iterator i =0; i!= _objects.end(); i++)
        if (*i == obj)
        {
            _objects.erase(i);
            return;
        }
}

void IModule::processing()
{
    foreach(WorldObject * obj, _objects)
        processObject(obj);
}
