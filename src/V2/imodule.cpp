#include "imodule.h"

#include "worldobject.h"

void IModule::addRef()
{
    ++_refs;
}

void IModule::release()
{
    if (_refs) {
        --_refs;
    }
}

quint32 IModule::refs()
{
    return _refs;
}

void IModule::addObject(WorldObject *obj)
{
    initObjectData(obj);
    _objects.push_back(obj);
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
