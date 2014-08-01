#ifndef RENDERER_H
#define RENDERER_H

#include "world.h"

class RenderWidget;
class Renderer
{
public:
    Renderer(RenderWidget* widget);
    void renderWorld(World* world);

private:
    RenderWidget *widget;
};

#endif // RENDERER_H
