#ifndef V2EVENT_CLASSES
#define V2EVENT_CLASSES
#include "v2event.h"

class V2ResizeEvent: public V2Event{
    V2ResizeEvent(int width, int height):
        V2Event(V2WindowResizeEventType),
        _width(width),
        _height(height){}

    ~V2ResizeEvent(){}
public:
    int width(){return _width;}
    int heigth(){return _height;}
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
    int shift(){return _shift;}
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
    int x(){return _x;}
    int y(){return _y;}
private:
    int _x;
    int _y;
};

#endif // V2EVENT_CLASSES

