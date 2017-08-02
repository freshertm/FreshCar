#include "mainwindow.h"
#include "v2renderer.h"
#include "v2appglwindow.h"
#include "v2scene.h"
#include "appcube.h"
#include "v2perspectivecamera.h"
//#include "v2orthocamera.h"
#include "v2cameralist.h"
#include "objects/brick.h"
#include "objects/cube.h"
#include "b2physicsmodule.h"

V2MainWindow::V2MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _engine(QSharedPointer<V2Engine>::create()),
    _cameraAngle(0.0),
    _cameraRadius(-53.0),
    _cameraSpeed(0),
    _prop(QSharedPointer<V2RenderProperties>::create())
{
    _ui->setupUi(this);

    auto glWindow = QSharedPointer<v2appGLWindow>::create();
    _engine->addModule(glWindow);
    if (!_engine->initModule<V2Renderer>()) {
        qDebug() << "Cannot initialize renderer.";
        return;
    }

    _ui->widget->setLayout(new QVBoxLayout());
    _ui->widget->layout()->addWidget(glWindow->widget());
    //setCentralWidget(glWindow->widget());

    connect(glWindow.data(), &V2Window::paintReadySignal, this, &V2MainWindow::onFrame);
    connect(_ui->horizontalSlider, &QSlider::valueChanged, this, &V2MainWindow::onNewSliderValue);
    connect(_ui->horizontalSlider_2, &QSlider::valueChanged, this, &V2MainWindow::onNewSlider2Value);


    auto box2d = QSharedPointer<Box2DPhysicsModule>::create();
    _engine->addModule(box2d);
    if (!_engine->initModule<Box2DPhysicsModule>())
    {
        qDebug() << "Cannot init Box2DPhysicsModule module";
    };

    if (!_engine->initModule<V2Window>())
    {
        qDebug() << "Cannot init V2Window module";
    };

    if (!_engine->enableModule<V2Renderer>())
    {
        qDebug() << "Cannot enable V2Renderer module";
    };

    if (!_engine->enableModule<V2Window>())
    {
        qDebug() << "Cannot enable V2Window module";
    };

    if (!_engine->enableModule<Box2DPhysicsModule>())
    {
        qDebug() << "Cannot enable V2Physics module";
    }

    auto cameras = _engine->module<V2CameraList>();
    auto win = qSharedPointerDynamicCast<V2Window>(glWindow);
    _camera = QSharedPointer<V2PerspectiveCamera>::create(win);
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

    auto camera = qSharedPointerDynamicCast<V2Camera>(_camera);
    cameras->setCurrent(camera);
    //V2APPCube *cube = new V2APPCube(10);
    auto cube = QSharedPointer<V2Object>(new Brick(glm::vec2(0,0), 0, 20, 3));

    //auto cube = QSharedPointer<V2Object>::create(glm::vec2(0,0), 0, 20, 3);
    _engine->scene()->addObject(cube);

    _camControl = QSharedPointer<AppCameraControl>(new AppCameraControl(_engine));
    //_camControl = QSharedPointer<AppCameraControl>::create(_engine);
}

V2MainWindow::~V2MainWindow()
{

}



void V2MainWindow::onFrame()
{
    //const float radius = 10.0;
    //float x = _cameraRadius * sin(_cameraAngle * 3.14f / 180.0f);
    //float y = _cameraRadius * cos(_cameraAngle * 3.14f / 180.0f);
    //_camera->setPosition(glm::vec3(x,0,y));
    //_cameraAngle += _cameraSpeed;
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

    auto cube = QSharedPointer<V2Object>(new Cube(glm::vec2(0,40), 0,  1));

    //auto cube = QSharedPointer<V2Object>::create(glm::vec2(0,0), 0, 20, 3);
    _engine->scene()->addObject(cube);
   // _prop->setWireframe(checked);
}

void V2MainWindow::on_checkBox_2_clicked(bool checked)
{
    //_prop->setLighting(checked);
}
