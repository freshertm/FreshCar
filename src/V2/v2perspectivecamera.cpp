#include "v2perspectivecamera.h"

#include <glm/gtc/matrix_transform.hpp>
#include "v2window.h"

V2PerspectiveCamera::V2PerspectiveCamera(V2Window * window):_window(window)
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
    _fov = fov;
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

