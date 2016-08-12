#ifndef V2CAMERALIST_H
#define V2CAMERALIST_H
#include "v2module.h"
#include <QObject>

class V2Camera;

class V2CameraList : public V2Module
{
    Q_OBJECT
public:
    V2CameraList();
    ~V2CameraList();


    V2Camera * currentCamera();

public slots:
    void setCurrent(V2Camera *);

signals:
    void newCameraSelected(V2Camera *);
private:
    V2Camera* _current;

};

#endif // CAMERALIST_H
