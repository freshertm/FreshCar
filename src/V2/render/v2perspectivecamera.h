#ifndef V2PERSPECTIVECAMERA_H
#define V2PERSPECTIVECAMERA_H

#include "v2camera.h"

class V2Window;
class V2PerspectiveCamera : public V2Camera
{
    Q_OBJECT
public:
    V2PerspectiveCamera(QSharedPointer<V2Window>&);
    virtual ~V2PerspectiveCamera();

    virtual bool enable();
    virtual bool disable();

protected:
    virtual glm::mat4 getPojectionMatrix();

public slots:
    void setFOV(float fov);
    void setClipping(float near, float far);

private slots:
    void onResize(int width, int height);

private:
    float _fov;
    float _near;
    float _far;
    float _aspect;
    QSharedPointer<V2Window> _window;
};

#endif // V2PERSPECTIVECAMERA_H
