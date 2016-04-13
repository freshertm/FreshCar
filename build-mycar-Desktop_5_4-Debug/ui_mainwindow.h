/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *addRandomCar;
    QAction *actionWheel_friction;
    QAction *actionGround_friction;
    QAction *actionBody_friction_2;
    QAction *actionPart;
    QAction *actionDynasties;
    QAction *actionCrosses;
    QAction *actionMax_mutation_genome_count;
    QAction *actionWheel_mutation_rate;
    QAction *actionMin_radius;
    QAction *actionMax_radius;
    QAction *actionCar_die_time;
    QAction *actionPopulation;
    QAction *actionWheel_torque;
    QAction *actionWheel_speed;
    QAction *actionWheel_min_speed;
    QAction *actionMin_torque;
    QAction *actionMax_torque;
    QAction *actionCar_mix_count;
    QAction *actionTrianglePower;
    QAction *save;
    QAction *actionDrawHistoryGraph;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *graphWidget;
    QWidget *parametersWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *gbParameters;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *sbPopulation;
    QLabel *label_2;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_8;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_7;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menuWorld_physics;
    QMenu *menuGenome_mixing;
    QMenu *menuGenome_mutation;
    QMenu *menuWheel_genome;
    QMenu *menu_3;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 462);
        addRandomCar = new QAction(MainWindow);
        addRandomCar->setObjectName(QStringLiteral("addRandomCar"));
        actionWheel_friction = new QAction(MainWindow);
        actionWheel_friction->setObjectName(QStringLiteral("actionWheel_friction"));
        actionGround_friction = new QAction(MainWindow);
        actionGround_friction->setObjectName(QStringLiteral("actionGround_friction"));
        actionBody_friction_2 = new QAction(MainWindow);
        actionBody_friction_2->setObjectName(QStringLiteral("actionBody_friction_2"));
        actionPart = new QAction(MainWindow);
        actionPart->setObjectName(QStringLiteral("actionPart"));
        actionDynasties = new QAction(MainWindow);
        actionDynasties->setObjectName(QStringLiteral("actionDynasties"));
        actionCrosses = new QAction(MainWindow);
        actionCrosses->setObjectName(QStringLiteral("actionCrosses"));
        actionMax_mutation_genome_count = new QAction(MainWindow);
        actionMax_mutation_genome_count->setObjectName(QStringLiteral("actionMax_mutation_genome_count"));
        actionWheel_mutation_rate = new QAction(MainWindow);
        actionWheel_mutation_rate->setObjectName(QStringLiteral("actionWheel_mutation_rate"));
        actionMin_radius = new QAction(MainWindow);
        actionMin_radius->setObjectName(QStringLiteral("actionMin_radius"));
        actionMax_radius = new QAction(MainWindow);
        actionMax_radius->setObjectName(QStringLiteral("actionMax_radius"));
        actionCar_die_time = new QAction(MainWindow);
        actionCar_die_time->setObjectName(QStringLiteral("actionCar_die_time"));
        actionPopulation = new QAction(MainWindow);
        actionPopulation->setObjectName(QStringLiteral("actionPopulation"));
        actionWheel_torque = new QAction(MainWindow);
        actionWheel_torque->setObjectName(QStringLiteral("actionWheel_torque"));
        actionWheel_speed = new QAction(MainWindow);
        actionWheel_speed->setObjectName(QStringLiteral("actionWheel_speed"));
        actionWheel_min_speed = new QAction(MainWindow);
        actionWheel_min_speed->setObjectName(QStringLiteral("actionWheel_min_speed"));
        actionMin_torque = new QAction(MainWindow);
        actionMin_torque->setObjectName(QStringLiteral("actionMin_torque"));
        actionMax_torque = new QAction(MainWindow);
        actionMax_torque->setObjectName(QStringLiteral("actionMax_torque"));
        actionCar_mix_count = new QAction(MainWindow);
        actionCar_mix_count->setObjectName(QStringLiteral("actionCar_mix_count"));
        actionTrianglePower = new QAction(MainWindow);
        actionTrianglePower->setObjectName(QStringLiteral("actionTrianglePower"));
        save = new QAction(MainWindow);
        save->setObjectName(QStringLiteral("save"));
        actionDrawHistoryGraph = new QAction(MainWindow);
        actionDrawHistoryGraph->setObjectName(QStringLiteral("actionDrawHistoryGraph"));
        actionDrawHistoryGraph->setCheckable(true);
        actionDrawHistoryGraph->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        graphWidget = new QWidget(centralWidget);
        graphWidget->setObjectName(QStringLiteral("graphWidget"));

        horizontalLayout->addWidget(graphWidget);

        parametersWidget = new QWidget(centralWidget);
        parametersWidget->setObjectName(QStringLiteral("parametersWidget"));
        verticalLayout_2 = new QVBoxLayout(parametersWidget);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 10);
        gbParameters = new QGroupBox(parametersWidget);
        gbParameters->setObjectName(QStringLiteral("gbParameters"));
        formLayout = new QFormLayout(gbParameters);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(gbParameters);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        sbPopulation = new QSpinBox(gbParameters);
        sbPopulation->setObjectName(QStringLiteral("sbPopulation"));
        sbPopulation->setMaximum(10000);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbPopulation);

        label_2 = new QLabel(gbParameters);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        label_10 = new QLabel(gbParameters);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_10);

        doubleSpinBox_8 = new QDoubleSpinBox(gbParameters);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setMaximum(10);
        doubleSpinBox_8->setSingleStep(0.1);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_8);


        verticalLayout_2->addWidget(gbParameters);

        groupBox = new QGroupBox(parametersWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        doubleSpinBox = new QDoubleSpinBox(groupBox);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMaximum(10000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBox);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(1);
        doubleSpinBox_2->setMaximum(10000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, doubleSpinBox_2);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_7);

        doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(1);
        doubleSpinBox_3->setMaximum(10000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, doubleSpinBox_3);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_5);

        doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(1);
        doubleSpinBox_4->setMaximum(10000);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, doubleSpinBox_4);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_6);

        doubleSpinBox_5 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(1);
        doubleSpinBox_5->setMaximum(10000);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, doubleSpinBox_5);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_8);

        doubleSpinBox_6 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(1);
        doubleSpinBox_6->setMaximum(10000);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, doubleSpinBox_6);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_9);

        doubleSpinBox_7 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setMaximum(10);
        doubleSpinBox_7->setSingleStep(0.1);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, doubleSpinBox_7);


        verticalLayout_2->addWidget(groupBox);

        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addWidget(parametersWidget);

        horizontalLayout->setStretch(0, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menuWorld_physics = new QMenu(menu_2);
        menuWorld_physics->setObjectName(QStringLiteral("menuWorld_physics"));
        menuGenome_mixing = new QMenu(menu_2);
        menuGenome_mixing->setObjectName(QStringLiteral("menuGenome_mixing"));
        menuGenome_mutation = new QMenu(menu_2);
        menuGenome_mutation->setObjectName(QStringLiteral("menuGenome_mutation"));
        menuWheel_genome = new QMenu(menu_2);
        menuWheel_genome->setObjectName(QStringLiteral("menuWheel_genome"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(addRandomCar);
        menu_2->addAction(menuWorld_physics->menuAction());
        menu_2->addAction(menuGenome_mixing->menuAction());
        menu_2->addAction(menuGenome_mutation->menuAction());
        menu_2->addAction(menuWheel_genome->menuAction());
        menu_2->addAction(actionTrianglePower);
        menu_2->addAction(actionCar_die_time);
        menu_2->addAction(actionPopulation);
        menu_2->addSeparator();
        menu_2->addAction(save);
        menuWorld_physics->addAction(actionBody_friction_2);
        menuWorld_physics->addAction(actionWheel_friction);
        menuWorld_physics->addAction(actionGround_friction);
        menuWorld_physics->addAction(actionWheel_torque);
        menuGenome_mixing->addAction(actionPart);
        menuGenome_mixing->addAction(actionCar_mix_count);
        menuGenome_mutation->addAction(actionMax_mutation_genome_count);
        menuGenome_mutation->addAction(actionWheel_mutation_rate);
        menuWheel_genome->addAction(actionMin_radius);
        menuWheel_genome->addAction(actionMax_radius);
        menuWheel_genome->addAction(actionWheel_min_speed);
        menuWheel_genome->addAction(actionWheel_speed);
        menu_3->addAction(actionDrawHistoryGraph);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        addRandomCar->setText(QApplication::translate("MainWindow", "One more car", 0));
        addRandomCar->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionWheel_friction->setText(QApplication::translate("MainWindow", "wheel friction", 0));
        actionGround_friction->setText(QApplication::translate("MainWindow", "ground friction", 0));
        actionBody_friction_2->setText(QApplication::translate("MainWindow", "body friction", 0));
        actionPart->setText(QApplication::translate("MainWindow", "part", 0));
        actionDynasties->setText(QApplication::translate("MainWindow", "dynasties", 0));
        actionCrosses->setText(QApplication::translate("MainWindow", "crosses", 0));
        actionMax_mutation_genome_count->setText(QApplication::translate("MainWindow", "max mutation genome count", 0));
        actionWheel_mutation_rate->setText(QApplication::translate("MainWindow", "wheel mutation rate", 0));
        actionMin_radius->setText(QApplication::translate("MainWindow", "min radius", 0));
        actionMax_radius->setText(QApplication::translate("MainWindow", "max radius", 0));
        actionCar_die_time->setText(QApplication::translate("MainWindow", "Car die time", 0));
        actionPopulation->setText(QApplication::translate("MainWindow", "Population", 0));
        actionWheel_torque->setText(QApplication::translate("MainWindow", "wheel torque", 0));
        actionWheel_speed->setText(QApplication::translate("MainWindow", "max speed", 0));
        actionWheel_min_speed->setText(QApplication::translate("MainWindow", "min speed", 0));
        actionMin_torque->setText(QApplication::translate("MainWindow", "min torque", 0));
        actionMax_torque->setText(QApplication::translate("MainWindow", "max torque", 0));
        actionCar_mix_count->setText(QApplication::translate("MainWindow", "car mix count", 0));
        actionTrianglePower->setText(QApplication::translate("MainWindow", "trianglePower", 0));
        save->setText(QApplication::translate("MainWindow", "Save world state", 0));
        actionDrawHistoryGraph->setText(QApplication::translate("MainWindow", "Draw history plots", 0));
        gbParameters->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\211\320\270\320\265", 0));
        label->setText(QApplication::translate("MainWindow", "\320\277\320\276\320\277\321\203\320\273\321\217\321\206\320\270\321\217", 0));
        label_2->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\320\272\320\276\321\215\321\204. \321\202\321\200\320\265\320\275\320\270\321\217 \321\200\320\260\320\274\321\213", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\265\321\201\320\276", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\274\320\270\320\275. \321\200\320\260\320\264\320\270\321\203\321\201", 0));
        label_4->setText(QApplication::translate("MainWindow", "\320\274\320\260\320\272\321\201. \321\200\320\260\320\264\320\270\321\203\321\201", 0));
        label_7->setText(QApplication::translate("MainWindow", "\320\274\320\270\320\275. \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0));
        label_5->setText(QApplication::translate("MainWindow", "\320\274\320\260\320\272\321\201. \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0));
        label_6->setText(QApplication::translate("MainWindow", "\320\274\320\270\320\275. \320\274\320\276\320\274\320\265\320\275\321\202", 0));
        label_8->setText(QApplication::translate("MainWindow", "\320\274\320\260\320\272\321\201. \320\274\320\276\320\274\320\265\320\275\321\202", 0));
        label_9->setText(QApplication::translate("MainWindow", "\320\272\320\276\321\215\321\204. \321\202\321\200\320\265\320\275\320\270\321\217", 0));
        menu->setTitle(QApplication::translate("MainWindow", "Add", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "World settings", 0));
        menuWorld_physics->setTitle(QApplication::translate("MainWindow", "World physics", 0));
        menuGenome_mixing->setTitle(QApplication::translate("MainWindow", "Genome mixing", 0));
        menuGenome_mutation->setTitle(QApplication::translate("MainWindow", "Genome mutation", 0));
        menuWheel_genome->setTitle(QApplication::translate("MainWindow", "Wheel genome", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "UI Preferences", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
