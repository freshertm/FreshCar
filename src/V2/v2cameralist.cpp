#include "v2cameralist.h"
#include <v2camera.h>

V2CameraList::V2CameraList()
{
    _current = new V2Camera();
}

V2CameraList::~V2CameraList()
{

}

V2Camera *V2CameraList::currentCamera()
{
    return _current;
}

void V2CameraList::setCurrent(V2Camera * camera)
{
    Q_ASSERT(camera != nullptr);
    _current = camera;
    emit newCameraSelected(camera);
}

