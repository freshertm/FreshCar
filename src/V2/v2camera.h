#ifndef V2CAMERA_H
#define V2CAMERA_H

#include "worldobject.h"

class V2Camera : public WorldObject
{
    Q_OBJECT
public:
    V2Camera();
    ~V2Camera();

    Vector3 lookPoint();

public slots:
    virtual void setLookPoint(const Vector3& lookTo);
signals:
    void lookPointChanged(const Vector3 &);

private:
    Vector3 _lookPoint;
};

#endif // V2CAMERA_H
