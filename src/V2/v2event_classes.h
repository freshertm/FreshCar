#ifndef V2EVENT_CLASSES
#define V2EVENT_CLASSES
#include "v2event.h"
/*
class V2WindowResizeEvent: public V2Event{
    V2WindowResizeEvent(int width, int height):
        V2Event(V2WindowResizeEventType),
        _width(width),
        _height(height){}

    ~V2WindowResizeEvent(){}
public:
    int width()  const {return _width;}
    int heigth() const {return _height;}
private:
    int _width;
    int _height;
};


class V2WheelEvent: public V2Event{
    V2WheelEvent(int shift):
        V2Event(V2WheelEventType),
        _shift(shift){}

    ~V2WheelEvent(){}
public:
    int shift() const {return _shift;}
private:
    int _shift;
};


class V2MouseEvent: public V2Event{
    V2MouseEvent(int x, int y):
        V2Event(V2MouseEventType),
        _x(x),
        _y(y){}

    ~V2MouseEvent(){}
public:
    int x() const {return _x;}
    int y() const {return _y;}
private:
    int _x;
    int _y;
};


class V2Camera;
class V2ActiveCameraChanged: public V2Event {
public:
    V2ActiveCameraChanged(V2Camera* camera):
        V2Event(V2ActiveCameraChangedType),
        _camera(camera){}
    V2Camera * camera() const {return _camera;}
private:
    V2Camera * _camera;
};
*/
#endif // V2EVENT_CLASSES

