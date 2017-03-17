#include "appcameracontrol.h"
#include "v2engine.h"
#include "v2cameralist.h"
#include "v2orthocamera.h"
#include "v2window.h"

void AppCameraControl::onMouseWheel(int diff)
{

}

AppCameraControl::AppCameraControl(QSharedPointer<V2Engine> &engine):
    _xShift(0.0f),
    _yShift(0.0f)
{
    _camList = engine->module<V2CameraList>();
    Q_ASSERT(_camList.isNull());

    connect(_camList.data(), &V2CameraList::newCameraSelected, this, &AppCameraControl::onCameraChanged);
    _camList->addRef();

    _window = engine->module<V2Window>();
    Q_ASSERT(_window.isNull());

    connect(_window.data(), &V2Window::resizeSignal, this, &AppCameraControl::onResize);
    _window->addRef();
    _width = _window->width();
    _height = _window->height();
}

AppCameraControl::~AppCameraControl()
{
    _window->release();
    _camList->release();
}

void AppCameraControl::onCameraChanged(const QSharedPointer<V2Camera> &camera)
{
    auto cam = qSharedPointerDynamicCast<V2OrthoCamera>(camera);
    Q_ASSERT(!cam.isNull());
    _camera = cam;
}

void AppCameraControl::onResize(int width, int height)
{
    _width = width;
    _height = height;
    updateCamera();
}

void AppCameraControl::onMouseDown(int x, int y)
{
    _mouseXPos = x;
    _mouseYPos = y;
}

void AppCameraControl::onMouseMove(int x, int y)
{
    _xShift += x - _mouseXPos;
    _mouseXPos = x;

    _yShift += y - _mouseYPos;
    _mouseYPos = y;

    updateCamera();
}

void AppCameraControl::onMouseRelease(int x, int y)
{

}

void AppCameraControl::updateCamera()
{

}
