#ifndef APPCAMERACONTROL_H
#define APPCAMERACONTROL_H

#include <QObject>
#include <memory>
#include "v2window.h"
#include "v2cameralist.h"

class V2Engine;
class V2CameraList;
class V2Camera;
class AppCameraControl : public QObject
{
    Q_OBJECT
public:
    explicit AppCameraControl(QSharedPointer<V2Engine>& );
    ~AppCameraControl();

signals:

private slots:
    void onMouseWheel(const QWheelEvent *);
    void onCameraChanged(const QSharedPointer<V2Camera>&);
    void onMouseDown(const QMouseEvent *);
    void onMouseMove(const QMouseEvent *);
    void onMouseRelease(const QMouseEvent *);
private:
    void updateCamera(const QPoint &diff);

    QSharedPointer<V2CameraList> _camList;
    QSharedPointer<V2Window> _window;
    QSharedPointer<V2Camera> _camera;
    float _xShift = 0;
    float _yShift = 0;
    float _distance=100;

    QPoint _mouseClickPoint;
    bool _mousePressed;
};

#endif // APPCAMERACONTROL_H
