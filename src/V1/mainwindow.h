#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGLWidget>
#include "renderwidget.h"
#ifdef USE_V2
#include "renderer.h"
#endif

class World;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:

private slots:
    void on_actionMax_mutation_genome_count_triggered();

    void on_actionWheel_mutation_rate_triggered();

    void on_actionMin_radius_triggered();

    void on_actionMax_radius_triggered();

    void on_actionCar_die_time_triggered();

    void on_actionPopulation_triggered();

    void on_actionWheel_friction_triggered();

    void on_actionGround_friction_triggered();

    void on_actionBody_friction_2_triggered();

    void on_actionPart_triggered();

    void on_actionWheel_min_speed_triggered();

    void on_actionWheel_speed_triggered();

    void on_actionCar_mix_count_triggered();

    void on_actionTrianglePower_triggered();

    void on_save_triggered();

private:
    Ui::MainWindow *ui;
    RenderWidget *widget;
    World* world;
};

#endif // MAINWINDOW_H
