#ifndef RENDERER_H
#define RENDERER_H

#include "imodule.h"

class WorldObject;
class RenderWidget;
class Renderer: public IModule
{
public:
    Renderer();

    void resize(int width, int height);
    void init();

    virtual ModuleClass moduleClass(){return ModuleClassRenderer;}

private:
    virtual void initObjectData(WorldObject * object);
    virtual void processObject(WorldObject*obj);

    RenderWidget *widget;
};

#endif // RENDERER_H
