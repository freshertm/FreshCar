#include "renderer.h"
#include "worldobject.h"
#include <QOpenGLFunctions>
#include "renderdata.h"
#include "v2engine.h"
#include "v2window.h"
#include <QDebug>
#include "v2scene.h"

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

    connect(engine, &V2Engine::sceneChanged, this, &Renderer::onSceneChanged);
    onSceneChanged(engine->scene());

    glClearColor(0, 0, 0, 1.0);
    qDebug() << "Renderer init() complete.";
    return true;
}

bool Renderer::stop(V2Engine *engine)
{
    V2Window * window = engine->module<V2Window>();
    disconnect(window, &V2Window::resizeSignal, this, &Renderer::resizeEvent);
    disconnect(window, &V2Window::paintReadySignal, this, &Renderer::windowPaintReady);
    disconnect(engine, &V2Engine::sceneChanged, this, &Renderer::onSceneChanged);
    window->release();

    qDebug() << "Renderer stop() complete.";
    return true;
}

void Renderer::windowPaintReady()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    foreach(WorldObject *object, _cachedObjectData.keys()){
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

void Renderer::processObject(WorldObject * obj)
{
    RenderData* data = _cachedObjectData[obj];
    if (data == nullptr){
        Geometry * geometry = obj->resource<Geometry>();
        Q_ASSERT(geometry != nullptr);
        data = new RenderData(geometry);
        _cachedObjectData[obj] = data;
    }
    data->process();
}

void Renderer::onCameraChanged(const V2Camera &newCamera)
{

}

void Renderer::onSceneChanged(V2Scene *scene)
{
    //disconnect(_sceneConnection);
    foreach(RenderData * renderData,  _cachedObjectData.values()) {
        delete renderData;
    }
    _cachedObjectData.clear();

    connect(scene, &V2Scene::objectAdded, this, &Renderer::onObjectAddedToScene);

    foreach(WorldObject *object , scene->objects()){
        onObjectAddedToScene(object);
    }
}

void Renderer::onObjectAddedToScene(WorldObject * object)
{
    Geometry * geometry = object->resource<Geometry>();
    if (geometry == nullptr) {
        return;
    }

    if (_cachedObjectData.contains(object)){
        return;
    }
    _cachedObjectData[object] = nullptr;
}

