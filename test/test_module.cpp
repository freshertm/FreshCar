#include "test_module.h"
#include "v2module.h"

Test_Module::Test_Module(QObject *parent) : QObject(parent)
{

}

Test_Module::~Test_Module()
{

}
/*
void Test_Module::testInitSimple()
{
    V2Module module;
    QCOMPARE(module.initialized(),false);
    QCOMPARE(module.signalsBlocked(),true);
    QCOMPARE(module.init(nullptr),true);
    QCOMPARE(module.signalsBlocked(),true);
    QCOMPARE(module.initialized(),true);

}

void Test_Module::testStopSimple()
{
    V2Module module;
    QCOMPARE(module.signalsBlocked(),true);
    module.init(nullptr);
    QCOMPARE(module.stop(nullptr), true);
    QCOMPARE(module.signalsBlocked(),true);
    QCOMPARE(module.initialized(), false);
    module.init(nullptr);
    module.enable(nullptr);
    QCOMPARE(module.stop(nullptr), false);
    QCOMPARE(module.signalsBlocked(),false);
}

void Test_Module::testInitClass()
{

}

void Test_Module::testEnableSimple()
{
    V2Module module;
    QCOMPARE(module.enable(nullptr), false);
    QCOMPARE(module.enabled(), false);
    QCOMPARE(module.signalsBlocked(),true);

    module.init(nullptr);

    QCOMPARE(module.enable(nullptr), true);
    QCOMPARE(module.enabled(), true);
    QCOMPARE(module.signalsBlocked(),false);
}

void Test_Module::testDisableSimple()
{
    V2Module module;
    QCOMPARE(module.disable(nullptr), true);
    module.init(nullptr);
    QCOMPARE(module.disable(nullptr), true);
    module.enable(nullptr);
    QCOMPARE(module.signalsBlocked(),false);
    QCOMPARE(module.disable(nullptr), true);
    QCOMPARE(module.signalsBlocked(),true);
}

void Test_Module::testRefs()
{
    V2Module module;
    QCOMPARE(module.refs(), 1U);
    module.addRef();
    QCOMPARE(module.refs(), 2U);
    module.release();
    QCOMPARE(module.refs(), 1U);
}
*/
