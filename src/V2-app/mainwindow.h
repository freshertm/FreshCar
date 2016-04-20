#ifndef V2MAINWINDOW_H
#define V2MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "v2engine.h"

namespace Ui {
class MainWindow;
}

class V2MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit V2MainWindow(QWidget *parent = 0);
    ~V2MainWindow();

signals:

public slots:
private:
    Ui::MainWindow* _ui;
    V2Engine _engine;
};

#endif // V2MAINWINDOW_H
