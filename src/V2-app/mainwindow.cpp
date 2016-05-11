#include "mainwindow.h"
#include "renderer.h"
#include "v2appglwindow.h"
#include "v2scene.h"
#include "appcube.h"

V2MainWindow::V2MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _engine()
{
    _ui->setupUi(this);
    v2appGLWindow *glWindow = new v2appGLWindow();
    _engine.registerModule(glWindow);
    _engine.registerModule(new Renderer());

    _engine.scene()->addObject(new V2APPCube(10));

    setCentralWidget(glWindow->widget());
}

V2MainWindow::~V2MainWindow()
{

}

