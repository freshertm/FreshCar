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

/*QList<std::type_index> Renderer::dependencies() const
{
    QList<std::type_index> list;
    list.append(typeid(V2CameraList));
    list.append(typeid(V2Window));
    return list;
}*/

bool Renderer::initModule(QSharedPointer<V2Engine> &engine)
{
    if (!engine->initModule<V2Window>()) {
        qDebug() << "Renderer::initModule cannot initialize V2Window";
        return false;
    };

    auto window = engine->module<V2Window>();
    if (window.isNull()) {
        qDebug() << "Renderer init(): can't find window.";
        return false;
    }
    window->addRef(); // window can't be unloaded until render is working.

    auto camList = QSharedPointer<V2CameraList>::create();
    camList->addRef();
    engine->addModule(camList);
    engine->initModule<V2CameraList>();

    onCameraChanged(camList->currentCamera());
    connect(camList.data(), &V2CameraList::newCameraSelected, this, &Renderer::onCameraChanged);

    connect(window.data(), &V2Window::resizeSignal, this, &Renderer::resizeEvent);
    connect(window.data(), &V2Window::paintReadySignal, this, &Renderer::windowPaintReady);

    connect(engine.data(), &V2Engine::sceneChanged, this, &Renderer::onSceneChanged);
    auto scene = engine->scene();
    onSceneChanged(scene);

    float ambient[4] = {0.5, 0.5, 0.5, 1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
    glDisable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);

    glClearColor(0, 0, 0, 1.0);
    qDebug() << "Renderer init() complete.";
    return true;
}

bool Renderer::stopModule(QSharedPointer<V2Engine> &engine)
{
    auto window = engine->module<V2Window>();
    disconnect(window.data(), &V2Window::resizeSignal, this, &Renderer::resizeEvent);
    disconnect(window.data(), &V2Window::paintReadySignal, this, &Renderer::windowPaintReady);
    disconnect(engine.data(), &V2Engine::sceneChanged, this, &Renderer::onSceneChanged);

    qDebug() << "Renderer stop() complete.";
    return true;
}

bool Renderer::enableModule(QSharedPointer<V2Engine> &engine)
{
    auto scene = engine->scene();
    onSceneChanged(scene);
    return engine->enableModule<V2CameraList>();
}

bool Renderer::disableModule(QSharedPointer<V2Engine> &engine)
{
    return engine->disableModule<V2CameraList>();
}

void Renderer::windowPaintReady()
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    foreach(const auto &object, _cachedObjectData.keys()){
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

void Renderer::processObject(const QSharedPointer<V2Object> &obj)
{
    auto data = _cachedObjectData[obj];
    if (data.isNull()){
        auto geometry = obj->agent<Geometry>();
        Q_ASSERT( !geometry.isNull() );
        data = QSharedPointer<RenderData>::create(geometry);
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
    QSharedPointer<V2RenderProperties> prop = obj->agent<V2RenderProperties>();
    if (!prop.isNull()){
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

void Renderer::onCameraChanged(const QSharedPointer<V2Camera> &newCamera)
{
    if (_currentCamera.isNull()) {
        disconnect(_currentCamera.data(), &V2Camera::cameraChanged, this, &Renderer::onCameraMove);
    }

    _currentCamera = newCamera;
    connect(newCamera.data(), &V2Camera::cameraChanged,  this, &Renderer::onCameraMove);

    onCameraMove(newCamera);
}

void Renderer::onCameraMove(const QSharedPointer<V2Camera> &camera)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLoadMatrixf(glm::value_ptr(camera->matrix()));
    glMatrixMode(GL_MODELVIEW);
}

void Renderer::onSceneChanged(QSharedPointer<V2Scene> &scene)
{
    _cachedObjectData.clear();

    connect(scene.data(), &V2Scene::objectAdded, this, &Renderer::onObjectAddedToScene);

    foreach(auto &object , scene->objects()){
        onObjectAddedToScene(object);
    }
}

void Renderer::onObjectAddedToScene(const QSharedPointer<V2Object> &object)
{
    auto geometry = object->agent<Geometry>();
    if (geometry.isNull()) {
        return;
    }

    if (_cachedObjectData.contains(object)){
        return;
    }

    _cachedObjectData[object] = QSharedPointer<RenderData>();
}

