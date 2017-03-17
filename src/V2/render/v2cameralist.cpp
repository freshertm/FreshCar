#include "v2cameralist.h"
#include <v2camera.h>

V2CameraList::V2CameraList()
{
    _current = QSharedPointer<V2Camera>::create();
}

V2CameraList::~V2CameraList()
{

}

const QSharedPointer<V2Camera> &V2CameraList::currentCamera()
{
    return _current;
}

void V2CameraList::setCurrent(QSharedPointer<V2Camera> &camera)
{
    Q_ASSERT(camera != nullptr);
    _current->disable();
    _current = camera;

    camera->enable();
    emit newCameraSelected(camera);
}

