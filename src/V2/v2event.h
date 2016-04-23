#ifndef V2EVENT_H
#define V2EVENT_H

#include <QVector>
#include <QMap>

class V2Event{
public:
    enum Type
    {
        V2WheelEventType,
        V2MouseEventType,
        V2WindowResizeEventType,
        V2WindowInitializedType,
        V2WindowPaintReadyType,
        V2ActiveCameraChangedType
    };
public:
    V2Event(Type type);
    virtual ~V2Event();

    Type type();
private:
    Type _type;

};


class V2EventHandler;
class V2EventSystem
{
public:
    static void addHandler(V2Event::Type eventType, V2EventHandler &handler);
    static void sendEvent(V2Event *event);
private:
     typedef QMultiMap< V2Event::Type, V2EventHandler* > Handlers;
     Handlers _handlers;
     V2EventSystem();

     static V2EventSystem* _instance;

     static V2EventSystem *instance();

     void sendEventInternal(V2Event *event);
};


#endif // V2EVENT_H



