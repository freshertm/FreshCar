#ifndef V2EVENT_H
#define V2EVENT_H

#include <QVector>
#include <QMap>

enum V2EventType
{
    V2WheelEventType,
    V2MouseEventType,
    V2WindowResizeEventType,
    V2WindowInitializedType
};

class V2Event{
public:
    V2Event(V2EventType type);
    virtual ~V2Event();

    V2EventType type();
private:
    V2EventType _type;
};


class V2EventHandler;
class V2EventSystem
{
public:
    static void addHandler(V2EventType eventType, V2EventHandler &handler);
    static void sendEvent(V2Event *event);
private:
     typedef QMultiMap< V2EventType, V2EventHandler* > Handlers;
     Handlers _handlers;
     V2EventSystem();

     static V2EventSystem* _instance;

     static V2EventSystem *instance();

     void sendEventInternal(V2Event *event);
};


#endif // V2EVENT_H



