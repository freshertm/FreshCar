#include "renderer.h"
#include "renderwidget.h"

Renderer::Renderer(RenderWidget *widget): widget(widget)
{
}

ObjectData *Renderer::createObjectData(WorldObject *)
{
    return nullptr;
}

void Renderer::processObject(WorldObject *)
{

}
