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


void
gluLookAt(const Vector3& eye, const Vector3& center, const Vector3& up)
{
    //int i;
    //float forward[3], side[3], up[3];
    //GLfloat m[4][4];

    Vector3 forward = center - eye;
    /*forward[0] = centerx - eyex;
    forward[1] = centery - eyey;
    forward[2] = centerz - eyez;

    up[0] = upx;
    up[1] = upy;
    up[2] = upz;*/
    //forward = forward.normalized();

    //normalize(forward);

    /* Side = forward x up */
    //Vector3 side = forward.cross(up);
    //cross(forward, up, side);
    //side = side.normalized;
    //normalize(side);

    /* Recompute up as: up = side x forward */
    //up = side.cross(forward);
    //cross(side, forward, up);
    //Matrix4 matrix;
    //matrix.setIdentity();
    //__gluMakeIdentityf(&m[0][0]);

    /*m[0][0] = side[0];
    m[1][0] = side[1];
    m[2][0] = side[2];

    m[0][1] = up[0];
    m[1][1] = up[1];
    m[2][1] = up[2];

    m[0][2] = -forward[0];
    m[1][2] = -forward[1];
    m[2][2] = -forward[2];*/

    /*

    */

    /*glMultMatrixf(&m[0][0]);
    glTranslated(-eyex, -eyey, -eyez);*/
}

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

    V2CameraList * camList = new V2CameraList();
    camList->addRef();
    engine->registerModule(camList);
    _currentCamera = camList->currentCamera();

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

    Vector3 position = obj->position();
    glTranslatef(position.x, position.y, position.z);
    Vector3 rotation = obj->rotation();
    glRotatef(rotation.x, 1,0,0);
    glRotatef(rotation.y, 0,1,0);
    glRotatef(rotation.z, 0,0,1);

    Vector3 scale = obj->scale();
    glScalef(scale.x, scale.y, scale.z);

    data->process();
}

void Renderer::onCameraChanged(const V2Camera *newCamera)
{
    disconnect(_currentCamera, &V2Camera::positionChanged, this, &Renderer::onCameraMove);
    disconnect(_currentCamera, &V2Camera::lookPointChanged, this, &Renderer::onCameraMove);
    //disconnect(newCamera, &V2Camera::rotationChanged,  this, &Renderer::onCameraMove);

    _currentCamera = newCamera;
    connect(newCamera, &V2Camera::positionChanged,  this, &Renderer::onCameraMove);
    connect(newCamera, &V2Camera::lookPointChanged, this, &Renderer::onCameraMove);
    //connect(newCamera, &V2Camera::rotationChanged,  this, &Renderer::onCameraMove);

    onCameraMove();
}

void Renderer::onCameraMove()
{
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
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

