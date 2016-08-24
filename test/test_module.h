#ifndef TEST_MODULE_H
#define TEST_MODULE_H

#include <QObject>
#include <QTest>

class Test_Module : public QObject
{
    Q_OBJECT
public:
    explicit Test_Module(QObject *parent = 0);
    ~Test_Module();

private slots:
    void testInitSimple();
    void testStopSimple();
    void testInitClass();

    void testEnableSimple();
    void testDisableSimple();

    void testRefs();
};

#endif // TEST_MODULE_H
