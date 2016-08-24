TEMPLATE=app
QT += testlib widgets

SOURCES += \
    main.cpp \
    test_module.cpp \
    ../src/V2/core/v2module.cpp

HEADERS += \
    test_module.h \
    ../src/V2/core/v2module.h

INCLUDEPATH += ../src/V2
INCLUDEPATH += ../src/V2/core
INCLUDEPATH += ../src/V2/render
INCLUDEPATH += ../src/glm

