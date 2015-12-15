#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <QMap>
#include "geometry.h"
class ObjectData
{
public:
    virtual ~ObjectData(){}
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
    const Geometry &geometryData() const;

    void setModuleData(IModule*, ObjectData*);
    ObjectData *moduleData(IModule*);

private:
    QMap<IModule*, ObjectData*> _moduleData;
    Geometry _geometry;
};

#endif // WORLDOBJECT_H
