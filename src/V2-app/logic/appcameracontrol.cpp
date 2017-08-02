#include "appcameracontrol.h"
#include "v2engine.h"
#include "v2cameralist.h"
#include "v2orthocamera.h"
#include "v2window.h"


const float distcoef = 0.01f;
const float min_distance = 20.f;
void AppCameraControl::onMouseWheel(const QWheelEvent *ev)
{
    _distance += distcoef * ev->delta();
    if (_distance < min_distance) {
        _distance = min_distance;
    }
    updateCamera(QPoint());
    //qDebug() << "camera distance: " << _distance;
}

AppCameraControl::AppCameraControl(QSharedPointer<V2Engine> &engine):
    _xShift(0.0f),
    _yShift(0.0f)
{
    _camList = engine->module<V2CameraList>();
    Q_ASSERT(!_camList.isNull());

    connect(_camList.data(), &V2CameraList::newCameraSelected, this, &AppCameraControl::onCameraChanged);
    _camList->addRef();

    _camera = _camList->currentCamera();

    _window = engine->module<V2Window>();
    Q_ASSERT(!_window.isNull());

    connect(_window.data(), &V2Window::mousePressSignal, this, &AppCameraControl::onMouseDown);
    connect(_window.data(), &V2Window::mouseReleaseSignal, this, &AppCameraControl::onMouseRelease);
    connect(_window.data(), &V2Window::mouseMoveSignal, this, &AppCameraControl::onMouseMove);
    connect(_window.data(), &V2Window::wheelSignal, this, &AppCameraControl::onMouseWheel);
    updateCamera(QPoint());
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

void AppCameraControl::onMouseDown(const QMouseEvent * ev)
{
    //qDebug() << "AppCameraControl::onMouseDown";
    _mouseClickPoint = ev->pos();
    _mousePressed = true;
}

void AppCameraControl::onMouseMove(const QMouseEvent *ev)
{
    if (!_mousePressed) {
        return;
    }

    updateCamera(ev->pos() - _mouseClickPoint);
    _mouseClickPoint = ev->pos();
}

void AppCameraControl::onMouseRelease(const QMouseEvent *ev)
{
    if (!_mousePressed) {
        return;
    }
    //qDebug() << "AppCameraControl::onMouseRelease";
    updateCamera(ev->pos() - _mouseClickPoint);
    _mouseClickPoint = ev->pos();
    _mousePressed = false;
}
const float coef = 0.2;
void AppCameraControl::updateCamera(const QPoint &diff)
{
    _xShift += coef* diff.x();
    _yShift += coef* diff.y();
    glm::vec3 pos(-_xShift, _yShift, _distance);
    //glm::vec3 eye(-_xShift, _yShift, 0.0f);
    glm::vec3 eye(0, 0, 0.0f);
    _camera->setPosition(pos);
    _camera->setLookPoint(eye);

    //qDebug() << "Camera update pos: (" << _xShift <<", " << _yShift << ")";
}
