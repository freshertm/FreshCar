#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <QMap>
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

    void setModuleData(IModule*, ObjectData*);
    ObjectData *moduleData(IModule*);

private:
    QMap<IModule*, ObjectData*> _moduleData;
};

#endif // WORLDOBJECT_H
