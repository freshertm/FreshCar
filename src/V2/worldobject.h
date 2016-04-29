#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <QMap>
#include <QList>
#include "geometry.h"
#include "imodule.h"
#include "v2resource.h"
#include <QObject>

class WorldObject;
class ObjectData
{
    friend class WorldObject;
public:
    ObjectData(){}
    virtual ~ObjectData(){}
    virtual void process(){}

    WorldObject * parent(){return _parent;}
private:
    void setParent(WorldObject* parent) {_parent = parent;}
    WorldObject *_parent;
};



class IModule;
class WorldObject: public QObject, public V2ResourceContainer
{
    Q_OBJECT
public:
    WorldObject();
    ~WorldObject();

    const Geometry * geometry();

    void setPosition(const Vector3& newPosition);
    void setRotation(const Vector3& newRotation);
    void setScale(const Vector3& newScale);
    const Vector3& position();
    const Vector3& rotation();
    const Vector3& scale();
signals:
    void positionChanged(const Vector3 & newPosition);
    void rotationChanged(const Vector3 & newRotation);
    void scaleChanged(const Vector3 & newScale);

private:   
    Vector3 _position;
    Vector3 _rotation;
    Vector3 _scale;
};

#endif // WORLDOBJECT_H
