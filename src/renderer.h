#ifndef RENDERER_H
#define RENDERER_H

#include "world.h"
#include "imodule.h"

class WorldObject;
class RenderWidget;
class Renderer: public IModule
{
public:
    Renderer(RenderWidget* widget);

private:
private:
    virtual ObjectData *createObjectData(WorldObject*);
    virtual void processObject(WorldObject*);

    RenderWidget *widget;
};

#endif // RENDERER_H
