#include "v2camera.h"

V2Camera::V2Camera()
{

}

V2Camera::~V2Camera()
{

}

Vector3 V2Camera::lookPoint()
{
    return _lookPoint;
}

void V2Camera::setLookPoint(const Vector3 &lookTo)
{
    _lookPoint = lookTo;
    emit lookPointChanged(_lookPoint);
}

