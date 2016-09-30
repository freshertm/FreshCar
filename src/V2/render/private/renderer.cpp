#include "renderer.h"
#include "v2object.h"
#include <QOpenGLFunctions>
#include "renderdata.h"
#include "v2engine.h"
#include "v2window.h"
#include <QDebug>
#include "v2scene.h"
#include "v2cameralist.h"
#include "v2camera.h"
#include "v2renderproperties.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer(): V2Renderer(), _currentCamera(nullptr)
{
}

bool Renderer::initModule(V2Engine * engine)
{
    V2Window * window = engine->module<V2Window>();
    if (window == nullptr) {
        qDebug() << "Renderer init(): can't find window.";
        return false;
    }
    window->addRef(); // window can't be unloaded until render is working.

    V2CameraList * camList = new V2CameraList();
    camList->addRef();
    engine->addModule(camList);
    engine->initModule<V2CameraList>();

    onCameraChanged(camList->currentCamera());
    connect(camList, &V2CameraList::newCameraSelected, this, &Renderer::onCameraChanged);

    connect(window, &V2Window::resizeSignal, this, &Renderer::resizeEvent);
    connect(window, &V2Window::paintReadySignal, this, &Renderer::windowPaintReady);

    connect(engine, &V2Engine::sceneChanged, this, &Renderer::onSceneChanged);
    onSceneChanged(engine->scene());

    glClearColor(0, 0, 0, 1.0);
    qDebug() << "Renderer init() complete.";
    return true;
}

bool Renderer::stopModule(V2Engine *engine)
{
    V2Window * window = engine->module<V2Window>();
    disconnect(window, &V2Window::resizeSignal, this, &Renderer::resizeEvent);
    disconnect(window, &V2Window::paintReadySignal, this, &Renderer::windowPaintReady);
    disconnect(engine, &V2Engine::sceneChanged, this, &Renderer::onSceneChanged);
    window->release();

    V2CameraList * camList = engine->module<V2CameraList>();
    Q_ASSERT(camList != nullptr);
    camList->release();
    if (engine->unregisterModule(camList)){
        delete camList;
    }

    qDebug() << "Renderer stop() complete.";
    return true;
}

bool Renderer::enableModule(V2Engine *engine)
{
    onSceneChanged(engine->scene());
    return engine->enableModule<V2CameraList>();
}

bool Renderer::disableModule(V2Engine *engine)
{
    return engine->disableModule<V2CameraList>();
}

void Renderer::windowPaintReady()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    foreach(V2Object *object, _cachedObjectData.keys()){
        glLoadIdentity();
        processObject(object);
    }
}

void Renderer::resizeEvent(int width, int height)
{
    glDisable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_AUTO_NORMAL);
    glViewport(0,0,width, height);
    qDebug() << "Render resize "<<width<<"x"<<height;
}

void Renderer::processObject(V2Object * obj)
{
    RenderData* data = _cachedObjectData[obj];
    if (data == nullptr){
        Geometry * geometry = obj->resource<Geometry>();
        Q_ASSERT(geometry != nullptr);
        data = new RenderData(geometry);
        _cachedObjectData[obj] = data;
    }

    glm::vec3 position = obj->position();
    glTranslatef(position.x, position.y, position.z);
    glm::vec3 rotation = obj->rotation();
    glRotatef(rotation.x, 1,0,0);
    glRotatef(rotation.y, 0,1,0);
    glRotatef(rotation.z, 0,0,1);

    glm::vec3 scale = obj->scale();
    glScalef(scale.x, scale.y, scale.z);


    bool wireFrame = false;
    bool lighting = glIsEnabled(GL_LIGHTING);
    V2RenderProperties * prop = obj->resource<V2RenderProperties>();
    if (prop != nullptr){
        if (prop->isWireframe()){
            wireFrame = true;
            glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        }
        glColor3ub(prop->color().r(),prop->color().g(),prop->color().b());
        if (prop->isLightingEnabled()) {
            glEnable(GL_LIGHTING);
        } else {
            glDisable(GL_LIGHTING);
        }
    }

    data->process();

    if (prop){
        if (wireFrame){
            glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
        }
        if (lighting) {
            glEnable(GL_LIGHTING);
        }else {
            glDisable(GL_LIGHTING);
        }
    }
}

void Renderer::onCameraChanged(V2Camera *newCamera)
{
    if (_currentCamera != nullptr) {
        disconnect(_currentCamera, &V2Camera::cameraChanged, this, &Renderer::onCameraMove);
    }

    _currentCamera = newCamera;
    connect(newCamera, &V2Camera::cameraChanged,  this, &Renderer::onCameraMove);

    onCameraMove(newCamera);
}

void Renderer::onCameraMove(V2Camera* camera)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLoadMatrixf(glm::value_ptr(camera->matrix()));
    glMatrixMode(GL_MODELVIEW);
}

void Renderer::onSceneChanged(V2Scene *scene)
{
    //disconnect(_sceneConnection);
    foreach(RenderData * renderData,  _cachedObjectData.values()) {
        delete renderData;
    }
    _cachedObjectData.clear();

    connect(scene, &V2Scene::objectAdded, this, &Renderer::onObjectAddedToScene);

    foreach(V2Object *object , scene->objects()){
        onObjectAddedToScene(object);
    }
}

void Renderer::onObjectAddedToScene(V2Object * object)
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

