#include "renderer.h"
#include "worldobject.h"
#include <QOpenGLFunctions>
#include "renderdata.h"
#include "v2event.h"
#include "v2engine.h"
#include "v2window.h"
#include <QDebug>

Renderer::Renderer(): V2Renderer()
{
}

bool Renderer::init(V2Engine * engine)
{
    V2Window * window = engine->module<V2Window>();
    if (window == nullptr) {
        qDebug() << "Renderer init(): can't find window.";
        return false;
    }
    window->addRef(); // window can't be unloaded until render is working.

    connect(window, &V2Window::resizeSignal, this, &Renderer::resizeEvent);
    connect(window, &V2Window::paintReadySignal, this, &Renderer::windowPaintReady);

    glClearColor(0, 0, 0, 1.0);
    qDebug() << "Renderer init() complete.";
    return true;
}

bool Renderer::stop(V2Engine *)
{
    V2Window * window = engine->module<V2Window>();
    disconnect(window, &V2Window::resizeSignal, this, &Renderer::resizeEvent);
    disconnect(window, &V2Window::paintReadySignal, this, &Renderer::windowPaintReady);
    window->release();

    qDebug() << "Renderer stop() complete.";
    return true;
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
    qDebug() << "Render resize "<<width<<"x"<<height;
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

