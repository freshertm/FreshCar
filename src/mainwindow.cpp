#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QInputDialog>
#include <QFileDialog>
#include <QInputDialog>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bool ok=false;
    QString seedStr = QInputDialog::getText(this,"Enter seed",QString(),QLineEdit::Normal,QString("habrahabr.ru"),&ok);

    long seed =1;
    if (!ok){
        QTime dayEnd = QTime(23,59,59,999);
        seed = QTime::currentTime().msecsTo(dayEnd);
        seedStr = "<random> "+QString::number(seed);
    }
    else
    {
        for (int i=0; i< seedStr.length(); ++i)
#if QT_VERSION >= 0x050000
			seed *= seedStr.at(i).unicode();
#else
            seed *= seedStr.at(i).toAscii();
#endif
        seedStr += QString(" (%1)").arg(seed);
    }

    setWindowTitle(QString("FreshCar - ")+seedStr);

    world = new World(seed);

    Renderer *render = new Renderer();

    world->addModule(render);

    widget = new RenderWidget(world, render);

    //ui->centralWidget->layout()->addWidget(widget);
    QLayout *lay = new QVBoxLayout();
    lay->setContentsMargins(0,0,0,0);
    lay->setSpacing(0);
    ui->graphWidget->setLayout(lay);
    ui->graphWidget->layout()->addWidget(widget);
    ui->parametersWidget->setVisible(false);

    connect(this->ui->addRandomCar,SIGNAL(triggered()),world,SLOT(addRandomCar()));
    connect(ui->actionDrawHistoryGraph, SIGNAL(triggered(bool)), widget, SLOT(setDrawGraphs(bool)));
    ui->actionDrawHistoryGraph->setChecked(widget->drawHistoryGraphs());
}



MainWindow::~MainWindow()
{
    delete widget;
    delete ui;
}

void MainWindow::on_actionMax_mutation_genome_count_triggered()
{
    world->worldPropertiesForChange()->setGenomeMutateMaxCount(QInputDialog::getInt(NULL,QString(),QString(),world->worldPropertiesForChange()->genomeMutateMaxCount(),0,world->fullGenomeLength()));
}

void MainWindow::on_actionWheel_mutation_rate_triggered()
{
    world->worldPropertiesForChange()->setGenomeMutateRate(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->genomeMutateRate(),0,1));
}

void MainWindow::on_actionMin_radius_triggered()
{
    world->worldPropertiesForChange()->setWheelMinRadius(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->wheelMinRadius(),0,world->worldPropertiesForChange()->wheelMaxRadius()));
}

void MainWindow::on_actionMax_radius_triggered()
{
    world->worldPropertiesForChange()->setWheelMaxRadius(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->wheelMaxRadius(),world->worldPropertiesForChange()->wheelMinRadius(),1000));
}

void MainWindow::on_actionCar_die_time_triggered()
{
    world->worldPropertiesForChange()->setCarDieTime(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->carDieTime(),0,1000));
}

void MainWindow::on_actionPopulation_triggered()
{
    world->worldPropertiesForChange()->setPopulation(QInputDialog::getInt(NULL,QString(),QString(),world->worldPropertiesForChange()->population(),0,5000));
}

void MainWindow::on_actionWheel_friction_triggered()
{
    world->worldPropertiesForChange()->setWheelFriction(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->wheelFriction(),0,1000));
}

void MainWindow::on_actionGround_friction_triggered()
{
    world->worldPropertiesForChange()->setGroundFriction(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->groundFriction(),0,1000));
}

void MainWindow::on_actionBody_friction_2_triggered()
{
    world->worldPropertiesForChange()->setBodyFriction(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->bodyFriction(),0,1000));
}

void MainWindow::on_actionPart_triggered()
{
    world->worldPropertiesForChange()->setGenomeMixPart(QInputDialog::getInt(NULL,QString(),QString(),world->worldPropertiesForChange()->genomeMixPart(),0,world->fullGenomeLength()));
}

void MainWindow::on_actionWheel_min_speed_triggered()
{
    world->worldPropertiesForChange()->setWheelMinSpeed(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->wheelMinSpeed(),0,world->worldProperties()->wheelMaxSpeed()));
}

void MainWindow::on_actionWheel_speed_triggered()
{
    world->worldPropertiesForChange()->setWheelMaxSpeed(QInputDialog::getDouble(NULL,QString(),QString(),world->worldPropertiesForChange()->wheelMaxSpeed(),world->worldProperties()->wheelMinSpeed(),1000000));
}

void MainWindow::on_actionCar_mix_count_triggered()
{
    world->worldPropertiesForChange()->setMixCarsCount(
                QInputDialog::getInt(NULL,QString(),QString(),
                                     world->worldPropertiesForChange()->mixCarsCount(),1,
                                     world->worldPropertiesForChange()->population()));
}

void MainWindow::on_actionTrianglePower_triggered()
{
    world->worldPropertiesForChange()->setTrianglePower(QInputDialog::getDouble(NULL,QString(),QString(),world->worldProperties()->trianglePower(),0,1000000));
}

void MainWindow::on_save_triggered()
{
    QString filename = QFileDialog::getSaveFileName();
    if (filename.isEmpty()) return;
    world->saveState(filename);
}
