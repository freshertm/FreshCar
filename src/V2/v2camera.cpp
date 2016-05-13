#include "v2camera.h"
#include <glm/gtc/matrix_transform.hpp>

V2Camera::V2Camera()
{

}

V2Camera::~V2Camera()
{

}

const glm::mat4& V2Camera::matrix()
{
    return _cameraMatrix;
}

void V2Camera::setLookPoint(const glm::vec3 &lookTo)
{
    _lookPoint = lookTo;
    updateCamera();
}

void V2Camera::setUp(const glm::vec3 &upVector)
{
    _upVector = upVector;
    updateCamera();
}

void V2Camera::setPosition(const glm::vec3 &position)
{
    _position = position;
    updateCamera();
}

glm::mat4 V2Camera::getPojectionMatrix()
{
    return glm::mat4();
}

void V2Camera::updateCamera()
{
    glm::mat4 matrix = glm::lookAt(_position, _lookPoint, _upVector);
    _cameraMatrix = matrix * getPojectionMatrix();
    emit cameraChanged(this);
}

