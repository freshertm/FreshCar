#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QGuiApplication>
#include <Qt3DExtras>

#include "gamelogic.h"
#include "display.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow * view = new Qt3DExtras::Qt3DWindow();

    Display *display = new Display(view);
    view->show();

    auto result = app.exec();

    delete display;
    delete view;

}
