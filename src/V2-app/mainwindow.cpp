#include "mainwindow.h"
#include "renderer.h"
#include "v2appglwindow.h"
#include "v2scene.h"
#include "appcube.h"
#include "v2perspectivecamera.h"
//#include "v2orthocamera.h"
#include "v2cameralist.h"
#include "objects/brick.h"
#include "b2physicsmodule.h"

V2MainWindow::V2MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _engine(),
    _cameraAngle(0.0),
    _cameraRadius(-53.0),
    _cameraSpeed(0),
    _prop(new V2RenderProperties)
{
    _ui->setupUi(this);

    v2appGLWindow *glWindow = new v2appGLWindow();
    _engine.addModule(glWindow);
    if (!_engine.initModule<V2Renderer>()) {
        qDebug() << "Cannot initialize renderer.";
        return;
    }

    _ui->widget->setLayout(new QVBoxLayout());
    _ui->widget->layout()->addWidget(glWindow->widget());
    //setCentralWidget(glWindow->widget());

    connect(glWindow, &V2Window::paintReadySignal, this, &V2MainWindow::onFrame);
    connect(_ui->horizontalSlider, &QSlider::valueChanged, this, &V2MainWindow::onNewSliderValue);
    connect(_ui->horizontalSlider_2, &QSlider::valueChanged, this, &V2MainWindow::onNewSlider2Value);


    if (!_engine.addAndInitModule(new Box2DPhysicsModule()))
    {
        qDebug() << "Cannot init Box2DPhysicsModule module";
    };

    if (!_engine.initModule<V2Window>())
    {
        qDebug() << "Cannot init V2Window module";
    };

    if (!_engine.enableModule<V2Renderer>())
    {
        qDebug() << "Cannot enable V2Renderer module";
    };

    if (!_engine.enableModule<V2Window>())
    {
        qDebug() << "Cannot enable V2Window module";
    };

    if (!_engine.enableModule<Box2DPhysicsModule>())
    {
        qDebug() << "Cannot enable V2Physics module";
    }

    V2CameraList *cameras = _engine.module<V2CameraList>();
    _camera = new V2PerspectiveCamera(glWindow);
    //_camera = new V2OrthoCamera();

   /* _camera->setFar(1000);
    _camera->setNear(0.1f);
    _camera->setLeft(-10);
    _camera->setRight(10);
    _camera->setBottom(-7);
    _camera->setTop(7);*/
    _camera->setFOV(30);
    _camera->setClipping(0.1, 1000.0);
    _camera->setPosition(glm::vec3(0,0,-10));
    _camera->setLookPoint(glm::vec3(0,0,0));

    cameras->setCurrent(_camera);
    //V2APPCube *cube = new V2APPCube(10);

    V2Object *brick = new Brick(glm::vec2(0,0), 0, 20, 3);
    _engine.scene()->addObject(brick);
}

V2MainWindow::~V2MainWindow()
{

}



void V2MainWindow::onFrame()
{
    //const float radius = 10.0;
    float x = _cameraRadius * sin(_cameraAngle * 3.14f / 180.0f);
    float y = _cameraRadius * cos(_cameraAngle * 3.14f / 180.0f);
    _camera->setPosition(glm::vec3(x,0,y));
    _cameraAngle += _cameraSpeed;
}

void V2MainWindow::onNewSliderValue(int value)
{
    //_camera->setFOV(value);
    //_cameraRadius = value;
    _cameraSpeed = 0.02 *(float)value;
}

void V2MainWindow::onNewSlider2Value(int value)
{
    //_camera->setFOV(value);
    _cameraRadius = value;
}


void V2MainWindow::on_checkBox_clicked(bool checked)
{
   // _prop->setWireframe(checked);
}

void V2MainWindow::on_checkBox_2_clicked(bool checked)
{
    //_prop->setLighting(checked);
}
