#include "v2perspectivecamera.h"

#include <glm/gtc/matrix_transform.hpp>
#include "v2window.h"

V2PerspectiveCamera::V2PerspectiveCamera(V2Window * window):
    _window(window), _fov(90.0), _near(0.01), _far(100), _aspect(1.0)
{
    Q_ASSERT(window != nullptr);
    window->addRef();
}

V2PerspectiveCamera::~V2PerspectiveCamera()
{
    _window->release();
}

bool V2PerspectiveCamera::enable()
{
    connect(_window, &V2Window::resizeSignal, this, &V2PerspectiveCamera::onResize);
    onResize(_window->width(), _window->height());
    return true;
}

bool V2PerspectiveCamera::disable()
{
    disconnect(_window, &V2Window::resizeSignal, this, &V2PerspectiveCamera::onResize);
    return true;
}

glm::mat4 V2PerspectiveCamera::getPojectionMatrix()
{
    return glm::perspective(_fov, _aspect, _near, _far);
}

void V2PerspectiveCamera::setFOV(float fov)
{
    _fov = fov * 3.1415 / 180.0;
    updateCamera();
}

void V2PerspectiveCamera::setClipping(float near, float far)
{
    _near = near;
    _far = far;
    updateCamera();
}

void V2PerspectiveCamera::onResize(int width, int height)
{
    if (height == 0) {
        height = 1;
    }

    _aspect = (float) width / (float) height;

    updateCamera();
}

