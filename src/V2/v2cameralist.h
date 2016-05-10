#ifndef V2CAMERALIST_H
#define V2CAMERALIST_H
#include "imodule.h"
#include <QObject>

class V2Camera;

class V2CameraList : public IModule
{
public:
    V2CameraList();
    ~V2CameraList();


    V2Camera * current();

public slots:
    void setCurrent();

signals:
    void newCameraSelected(V2Camera *);


};

#endif // CAMERALIST_H
