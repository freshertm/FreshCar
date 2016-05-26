#ifndef APPCAMERACONTROL_H
#define APPCAMERACONTROL_H

#include <QObject>

class V2Engine;
class V2OrthoCamera;
class V2Window;
class V2CameraList;
class AppCameraControl : public QObject
{
    Q_OBJECT
public:
    explicit AppCameraControl(V2Engine* );
    ~AppCameraControl();

signals:

public slots:

private slots:
    void onMouseWheel(int diff);
    void onCameraChanged(V2Camera*);
    void onResize(int width, int height);
    void onMouseDown(int x, int y);
    void onMouseMove(int x, int y);
    void onMouseRelease(int x, int y);
private:
    void updateCamera();

    V2CameraList * _camList;
    V2Window * _window;
    V2OrthoCamera * _camera;
    int  _width;
    int _height;
    float _xShift;
    float _yShift;
    int _mouseXPos;
    int _mouseYPos;
};

#endif // APPCAMERACONTROL_H
