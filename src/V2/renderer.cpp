#include "renderer.h"
#include "worldobject.h"
#include <QOpenGLFunctions>
#include "renderdata.h"
#include "v2engine.h"
#include "v2window.h"
#include <QDebug>
#include "v2scene.h"
#include "v2cameralist.h"
#include "v2camera.h"

#include <glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
/*

void
gluLookAt(const glm::vec3& eye, const  glm::vec3& center, const  glm::vec3& up)
{

    glm::vec3 forward = center - eye;
    glm::normalize(forward);

    glm::vec3 side = glm::cross(forward,up);
    glm::normalize(side);

    glm::vec3 up2 = glm::cross(side, forward);

    glm::mat4 m;
    m[0][0] = side[0];
    m[1][0] = side[1];
    m[2][0] = side[2];

    m[0][1] = up2[0];
    m[1][1] = up2[1];
    m[2][1] = up2[2];

    m[0][2] = -forward[0];
    m[1][2] = -forward[1];
    m[2][2] = -forward[2];


    glMultMatrixf(m.);
    glTranslated(-eyex, -eyey, -eyez);
}
*/
Renderer::Renderer(): V2Renderer(), _currentCamera(nullptr)
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

    V2CameraList * camList = new V2CameraList();
    camList->addRef();
    engine->registerModule(camList);
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

bool Renderer::stop(V2Engine *engine)
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
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_AUTO_NORMAL);
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

    glm::vec3 position = obj->position();
    glTranslatef(position.x, position.y, position.z);
    glm::vec3 rotation = obj->rotation();
    glRotatef(rotation.x, 1,0,0);
    glRotatef(rotation.y, 0,1,0);
    glRotatef(rotation.z, 0,0,1);

    glm::vec3 scale = obj->scale();
    glScalef(scale.x, scale.y, scale.z);

    data->process();
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

