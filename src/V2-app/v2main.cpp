
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);
    V2MainWindow w;
    w.show();

    return a.exec();
}

