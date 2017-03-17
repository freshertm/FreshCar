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

public slots:

private slots:
    void onMouseWheel(int diff);
    void onCameraChanged(const QSharedPointer<V2Camera>&);
    void onResize(int width, int height);
    void onMouseDown(int x, int y);
    void onMouseMove(int x, int y);
    void onMouseRelease(int x, int y);
private:
    void updateCamera();

    QSharedPointer<V2CameraList> _camList;
    QSharedPointer<V2Window> _window;
    QSharedPointer<V2Camera> _camera;
    int  _width;
    int _height;
    float _xShift;
    float _yShift;
    int _mouseXPos;
    int _mouseYPos;
};

#endif // APPCAMERACONTROL_H
