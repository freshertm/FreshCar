#include "renderer.h"
#include "worldobject.h"
#include <QOpenGLFunctions>
#include "renderdata.h"


Renderer::Renderer(): IModule(ModuleClassRenderer)
{
}

void Renderer::init()
{
}

void Renderer::v2windowInitialized(const V2Event *)
{

}

void Renderer::v2windowPaintReady(const V2Event *)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    foreach(WorldObject *object, _objects){
        glLoadIdentity();
        RenderData * renderData = dynamic_cast<RenderData*>(object->moduleData(this));
        renderData->process();
    }
}

void Renderer::v2resizeEvent(const V2ResizeEvent *event)
{
    glDisable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);
    glViewport(0,0,event->width(), event->heigth());
}

void Renderer::initObjectData(WorldObject *object)
{
    const Geometry * geometry = object->geometry();

    if (!geometry) {
        return;
    }
    object->setModuleData(this, new RenderData(geometry));
}

void Renderer::processObject(WorldObject * obj)
{
    obj->moduleData(this)->process();
}

