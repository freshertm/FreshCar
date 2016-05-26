#ifndef V2ORTHOCAMERA_H
#define V2ORTHOCAMERA_H

#include "v2camera.h"

class V2OrthoCamera : public V2Camera
{
public:
    V2OrthoCamera();
    virtual ~V2OrthoCamera();

protected:
    virtual glm::mat4 getPojectionMatrix();

public slots:
    void setLeft(float left);
    void setRight(float right);
    void setTop(float top);
    void setBottom(float bottom);
    void setNear(float near);
    void setFar(float far);

private:
    float _left;
    float _right;
    float _top;
    float _bottom;
    float _near;
    float _far;
};

#endif // V2ORTHOCAMERA_H
