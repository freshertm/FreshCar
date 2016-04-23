#ifndef RENDERER_H
#define RENDERER_H

#include "imodule.h"
#include "v2eventhandler.h"

class WorldObject;
class RenderWidget;
class Renderer: public IModule, public V2EventHandler
{
public:
    Renderer();

    void init();
protected:
    void v2windowInitialized(const V2Event*);
    void v2windowPaintReady(const V2Event *);
    void v2resizeEvent(const V2WindowResizeEvent* event);

private:
    virtual void initObjectData(WorldObject * object);
    virtual void processObject(WorldObject*obj);

    RenderWidget *widget;
};

#endif // RENDERER_H
