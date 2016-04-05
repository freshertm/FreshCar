#include "renderer.h"
#include "renderwidget.h"
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
}

void Renderer::init()
{
}

void Renderer::initObjectData(WorldObject *object)
{
    const Geometry * geometry =
            static_cast<const Geometry*> (object->getEngineResource(EngineResource::GeometryData));
    if (!geometry) {
        return;
    }
    object->setModuleData(this, new RenderData(geometry));
}

void Renderer::processObject(WorldObject * obj)
{
    obj->moduleData(this)->process();
}

