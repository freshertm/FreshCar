#include "renderer.h"
#include "renderwidget.h"
#include "worldobject.h"

class RenderData: public ObjectData
{
public:
    RenderData(const Geometry &);
};

Renderer::Renderer(): IModule()
{
}

void Renderer::resize(int width, int height)
{
    glDisable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);
}

void Renderer::init()
{

}

ObjectData *Renderer::createObjectData(WorldObject *obj)
{
    return nullptr;
}

void Renderer::processObject(WorldObject *)
{

}
