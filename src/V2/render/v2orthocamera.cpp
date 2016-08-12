#include "v2orthocamera.h"
#include "v2window.h"
#include <glm/gtc/matrix_transform.hpp>

V2OrthoCamera::V2OrthoCamera()
{
}

V2OrthoCamera::~V2OrthoCamera()
{
}

glm::mat4 V2OrthoCamera::getPojectionMatrix()
{
    return glm::ortho(_left, _right, _top, _bottom, _near, _far);
}

void V2OrthoCamera::setLeft(float left)
{
    _left = left;
    updateCamera();
}

void V2OrthoCamera::setRight(float right)
{
    _right = right;
    updateCamera();
}

void V2OrthoCamera::setTop(float top)
{
    _top = top;
    updateCamera();
}

void V2OrthoCamera::setBottom(float bottom)
{
    _bottom = bottom;
    updateCamera();
}

void V2OrthoCamera::setNear(float near)
{
    _near = near;
    updateCamera();
}

void V2OrthoCamera::setFar(float far)
{
    _far = far;
    updateCamera();
}
