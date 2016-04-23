#ifndef V2EVENTHANDLER_H
#define V2EVENTHANDLER_H
#include "v2event.h"
#include "v2event_classes.h"

class V2EventHandler
{
    friend class V2EventSystem;
protected:
    virtual void catchEvent(const V2Event *e ) {}
    virtual void v2wheelEvent(const V2WheelEvent * ){}
    virtual void v2windowInitialized(const V2Event * ){}
    virtual void v2windowPaintReady(const V2Event * ){}
    virtual void v2resizeEvent(const V2ResizeEvent *){}
    virtual void v2mouseEvent(const V2MouseEvent *){}
public:
    virtual ~V2EventHandler(){}
};

#endif // V2EVENTHANDLER_H
