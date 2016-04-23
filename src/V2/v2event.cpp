#include "v2event.h"
#include "v2eventhandler.h"

V2Event::V2Event(Type type): _type(type)
{

}

V2Event::~V2Event()
{

}

V2EventType V2Event::type()
{
    return _type;
}

void V2EventSystem::addHandler(V2Event::Type eventType, V2EventHandler &handler)
{
    instance()->_handlers.insert(eventType, &handler);
}

void V2EventSystem::sendEvent(V2Event * event)
{
  instance()->sendEventInternal(event);
}

V2EventSystem::V2EventSystem()
{
}


V2EventSystem* V2EventSystem::_instance = nullptr;

V2EventSystem *V2EventSystem::instance()
{
    if (V2EventSystem::_instance == nullptr){
        V2EventSystem::_instance = new V2EventSystem();
    }
    return _instance;
}

void V2EventSystem::sendEventInternal(V2Event *event)
{
    QList<V2EventHandler*> handlers = _handlers.values(event->type());
    foreach(V2EventHandler* handler, handlers) {
        switch(event->type()){
            case V2MouseEventType:           handler->v2mouseEvent((const V2MouseEvent*)event);     break;
            case V2WindowResizeEventType:    handler->v2resizeEvent((const V2ResizeEvent*)event);   break;
            case V2WheelEventType:           handler->v2wheelEvent((const V2WheelEvent*)event);     break;
            case V2WindowInitializedType:    handler->v2windowInitialized(event);                   break;
            case V2WindowPaintReadyType:     handler->v2windowPaintReady(event);                    break;
        }

        handler->catchEvent(event);
    }
}
