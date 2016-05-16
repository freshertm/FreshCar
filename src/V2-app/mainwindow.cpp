#include "mainwindow.h"
#include "renderer.h"
#include "v2appglwindow.h"
#include "v2scene.h"
#include "appcube.h"
#include "v2perspectivecamera.h"
#include "v2cameralist.h"

V2MainWindow::V2MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _engine(),
    _cameraAngle(0.0)
{
    _ui->setupUi(this);
    v2appGLWindow *glWindow = new v2appGLWindow();
    setCentralWidget(glWindow->widget());
    _engine.registerModule(glWindow);
    connect(glWindow, &V2Window::paintReadySignal, this, &V2MainWindow::onFrame);

    _engine.registerModule(new Renderer());

    V2CameraList *cameras = _engine.module<V2CameraList>();
    _camera = new V2PerspectiveCamera(glWindow);

    _camera->setFOV(65);
    _camera->setClipping(0.1, 1000.0);
    _camera->setPosition(glm::vec3(0,0,-10));
    _camera->setLookPoint(glm::vec3(0,0,0));

    cameras->setCurrent(_camera);

    _engine.scene()->addObject(new V2APPCube(10));
}

V2MainWindow::~V2MainWindow()
{

}

void V2MainWindow::onFrame()
{
    const float radius = 10.0;
    float x = radius * sin(_cameraAngle * 3.14 / 180.0);
    float y = radius * cos(_cameraAngle * 3.14 / 180.0);
    _camera->setPosition(glm::vec3(x,0,y));
    _cameraAngle += 0.1;
}

