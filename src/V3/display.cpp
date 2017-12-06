#include "display.h"

Display::Display(Qt3DExtras::Qt3DWindow *window): window(window)
{
    auto graph = window->defaultFrameGraph();
    window->setTitle(QStringLiteral("Welcome"));
    window->defaultFrameGraph()->setClearColor(QColor(210, 210, 220));
    window->setRootEntity(&root);

    auto camera = window->camera();
    camera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    camera->setFarPlane(45);
    camera->setAspectRatio(16/9);
    camera->setFarPlane(1000.0);
    camera->setPosition(QVector3D(0.0, 0.0, -40.0));
    camera->setUpVector(QVector3D(0.0, 1.0, 0.0));

    cameraController.setCamera(camera);

    connect(&timer, &QTimer::timeout, this, &Display::onTimer);
    timer.start(50);
}

void Display::setScene(Scene *)
{

}

void Display::onTimer()
{

}
