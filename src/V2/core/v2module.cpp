#include "v2module.h"

#include "v2object.h"

bool IModule::enable(V2Engine * engine)
{
    if (enabled()) {
        return true;
    }
    if (enableModule(engine)) {
        _enabled = true;
        blockSignals(false);
        return true;
    }
    return false;
}

bool IModule::disable(V2Engine * engine)
{
    if (!enabled()) {
        return true;
    }

    if (disableModule(engine)) {
        _enabled = false;
        blockSignals(true);
        return true;
    }
    return false;
}

bool IModule::enabled()
{
    return _enabled;
}

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
/*
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
}*/
