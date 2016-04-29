#include "renderer.h"
#include "worldobject.h"
#include <QOpenGLFunctions>
#include "renderdata.h"
#include "v2event.h"


Renderer::Renderer(): V2Renderer()
{
}

void Renderer::windowPaintReady()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    foreach(WorldObject *object, _objects){
        glLoadIdentity();
        processObject(object);
    }
}

void Renderer::resizeEvent(int width, int height)
{
    glDisable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);
    glViewport(0,0,width, height);
}

void Renderer::initObjectData(WorldObject *object)
{
    const Geometry * geometry = object->geometry();

    if (!geometry) {
        return;
    }
    object->setResource(new RenderData(geometry));
}

void Renderer::processObject(WorldObject * obj)
{
    RenderData* data = obj->resource<RenderData>();
    if (data == nullptr){
        return;
    }
    data->process();
}

void Renderer::onCameraChanged(const V2Camera &newCamera)
{

}

void Renderer::getWindow()
{

}

