#include "mainwindow.h"
#include "renderer.h"

V2MainWindow::V2MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _engine()
{
    _ui->setupUi(this);
    Renderer *render = new Renderer();
    _engine.registerModule(render);

}

V2MainWindow::~V2MainWindow()
{

}

