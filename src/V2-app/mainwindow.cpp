#include "mainwindow.h"
#include "renderer.h"
#include "v2appglwindow.h"

V2MainWindow::V2MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _engine()
{
    _ui->setupUi(this);
    _engine.registerModule(new Renderer());
    _engine.registerModule(new v2appGLWindow());

    _engine.module<V2Window>()->init();

}

V2MainWindow::~V2MainWindow()
{

}

