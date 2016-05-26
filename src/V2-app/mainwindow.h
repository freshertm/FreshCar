#ifndef V2MAINWINDOW_H
#define V2MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "v2engine.h"

namespace Ui {
class MainWindow;
}

//class V2PerspectiveCamera;
class V2OrthoCamera;
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

private:
    Ui::MainWindow* _ui;
    V2Engine _engine;

    //V2PerspectiveCamera * _camera;
    V2OrthoCamera * _camera;
    float _cameraAngle;
    float _cameraRadius;
};

#endif // V2MAINWINDOW_H
