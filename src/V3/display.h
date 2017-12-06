#ifndef DISPLAY_H
#define DISPLAY_H

#include <QTimer>
#include <QObject>
#include <Qt3DExtras>
#include <Qt3DCore>

#include <QHash>

#include "scene.h"
#include "gameobject.h"

class Display: public QObject
{
public:
    Display(Qt3DExtras::Qt3DWindow* window);

public slots:
    void setScene(Scene*);

private slots:
    void onTimer();

private:
    QTimer timer;
    Qt3DExtras::Qt3DWindow* window = nullptr;
    Qt3DCore::QEntity root;

    Scene* scene = nullptr;

    Qt3DExtras::QFirstPersonCameraController cameraController;
};

#endif // DISPLAY_H
