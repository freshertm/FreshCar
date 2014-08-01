#include <QtGui/QApplication>
#include "mainwindow.h"
#include "world.h"

int main(int argc, char *argv[])
{
    QGL::setPreferredPaintEngine(QPaintEngine::OpenGL);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
