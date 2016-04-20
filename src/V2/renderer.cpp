#include "renderer.h"
#include "worldobject.h"
#include <QOpenGLFunctions>
#include "renderdata.h"


Renderer::Renderer(): IModule()
{
}

void Renderer::resize(int width, int height)
{
    glDisable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);
    glViewport(0,0,width, height);
}

void Renderer::init()
{
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

