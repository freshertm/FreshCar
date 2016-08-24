#include <QApplication>
#include <QTest>
#include "test_module.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTest::qExec(new Test_Module, argc, argv);
    return 0;
}
