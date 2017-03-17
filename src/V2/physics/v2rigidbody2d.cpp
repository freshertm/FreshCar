#include "v2rigidbody2d.h"

void V2RigidBody2D::setDensity(float density)
{
    _density = density;
    emit changed();
}
