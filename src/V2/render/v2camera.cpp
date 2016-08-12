#include "v2camera.h"
#include <glm/gtc/matrix_transform.hpp>

#include <QDebug>
#include <glm/gtc/type_ptr.hpp>

void printMatrix(const glm::mat4 &matrix)
{
    const float * debugMatrix = glm::value_ptr(matrix);
    //qDebug() << "Matrix:";
    for (int i=0; i< 4; ++i)
    {
        QString str;
        for (int j = 0; j<4; j++)
        {
            str += QString::number(debugMatrix[j*4 + i],'f',2) + QString(" ");
        }
        qDebug() << str;
    }
    qDebug() << QString("======");
}

V2Camera::V2Camera(): _upVector(0,1,0), _lookPoint(0,0,0), _position(0,0,-1)
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

    //qDebug("lookAt matrix:");
    //printMatrix(matrix);

    glm::mat4 projectionMatrix = getPojectionMatrix();

    //qDebug("projection matrix:");
    //printMatrix(projectionMatrix);
    _cameraMatrix = projectionMatrix * matrix;
    //printMatrix(_cameraMatrix);

    emit cameraChanged(this);
}

