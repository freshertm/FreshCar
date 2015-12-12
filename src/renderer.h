#ifndef RENDERER_H
#define RENDERER_H

#include "world.h"
#include "imodule.h"

class WorldObject;
class RenderWidget;
class Renderer: public IModule
{
public:
    Renderer();

    void resize(int width, int height);
    void init();
private:
    virtual ObjectData *createObjectData(WorldObject*);
    virtual void processObject(WorldObject*);

    RenderWidget *widget;
};

#endif // RENDERER_H
