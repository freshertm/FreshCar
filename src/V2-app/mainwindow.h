#ifndef V2MAINWINDOW_H
#define V2MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "v2engine.h"
#include "renderproperties.h"

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

private:
    Ui::MainWindow* _ui;
    V2Engine _engine;

    V2PerspectiveCamera * _camera;
    //V2OrthoCamera * _camera;
    float _cameraAngle;
    float _cameraRadius;
    float _cameraSpeed;
    RenderProperties *_prop;
};

#endif // V2MAINWINDOW_H
