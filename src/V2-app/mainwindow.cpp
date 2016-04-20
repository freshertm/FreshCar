#include "mainwindow.h"

V2MainWindow::V2MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

V2MainWindow::~V2MainWindow()
{

}

