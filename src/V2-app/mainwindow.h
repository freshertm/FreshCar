#ifndef V2MAINWINDOW_H
#define V2MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "v2engine.h"
#include "v2renderproperties.h"

#include "logic/appcameracontrol.h"

namespace Ui {
class MainWindow;
}

class V2PerspectiveCamera;
//class V2OrthoCamera;
class V2MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit V2MainWindow(QWidget *parent = 0);
    ~V2MainWindow();

private slots:
    void onFrame();
    void onNewSliderValue(int value);
    void onNewSlider2Value(int value);

    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_checkBox_9_clicked(bool checked);

    void on_checkBox_3_clicked(bool checked);

private:
    Ui::MainWindow* _ui;
    QSharedPointer<V2Engine> _engine;

    QSharedPointer<V2PerspectiveCamera> _camera;
    //V2OrthoCamera * _camera;
    float _cameraAngle;
    float _cameraRadius;
    float _cameraSpeed;
    QSharedPointer<V2RenderProperties> _prop;

    QSharedPointer<AppCameraControl> _camControl;

    QSharedPointer<V2Object> _brick;
};

#endif // V2MAINWINDOW_H
