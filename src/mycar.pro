#-------------------------------------------------
#
# Project created by QtCreator 2013-07-10T14:58:24
#
#-------------------------------------------------

QT += core gui widgets
QT += opengl
# openglextensions

TARGET = mycar
TEMPLATE = app


QMAKE_LFLAGS+=/INCREMENTAL:NO

#default
#CONFIG += box2d_lib qjson_lib cars_app
#v2 app
CONFIG += v2_engine v2_test_app
#glm_lib box2d_lib

glm_lib {
INCLUDEPATH += glm
}

INCLUDEPATH += lib/Box2D

qjson_lib {
INCLUDEPATH += QJson/include/QJson
INCLUDEPATH += QJson/src
SOURCES+= QJson/src/json_parser.cc \
    QJson/src/json_scanner.cc \
    QJson/src/json_scanner.cpp \
    QJson/src/parser.cpp \
    QJson/src/parserrunnable.cpp \
    QJson/src/qobjecthelper.cpp \
    QJson/src/serializer.cpp \
    QJson/src/serializerrunnable.cpp

HEADERS+= QJson/include/QJson/Parser \
    QJson/include/QJson/QObjectHelper \
    QJson/include/QJson/Serializer \
    QJson/src/FlexLexer.h \
    QJson/src/json_parser.hh \
    QJson/src/json_scanner.h \
    QJson/src/location.hh \
    QJson/src/parser.h \
    QJson/src/parser_p.h \
    QJson/src/parserrunnable.h \
    QJson/src/position.hh \
    QJson/src/qjson_debug.h \
    QJson/src/qjson_export.h \
    QJson/src/qobjecthelper.h \
    QJson/src/serializer.h \
    QJson/src/serializerrunnable.h \
    QJson/src/stack.hh
}

v2_engine {
DEFINES += USE_V2

INCLUDEPATH += V2/core
SOURCES += \
    V2/core/v2engine.cpp \
    V2/core/v2module.cpp \
    V2/core/v2object.cpp \
    V2/core/v2scene.cpp

HEADERS += \
    V2/core/v2engine.h \
    V2/core/v2module.h \
    V2/core/v2object.h \
    V2/core/v2resource.h \
    V2/core/v2scene.h



INCLUDEPATH += V2/render
LIBS += opengl32.lib
HEADERS += \
    V2/render/v2geometry.h \
    V2/render/v2renderproperties.h \
    V2/render/v2camera.h \
    V2/render/v2cameralist.h \
    V2/render/v2color.h \
    V2/render/v2orthocamera.h \
    V2/render/v2perspectivecamera.h \
    V2/render/v2renderer.h \
    V2/render/v2window.h

SOURCES += \
    V2/render/v2renderproperties.cpp \
    V2/render/v2camera.cpp \
    V2/render/v2cameralist.cpp \
    V2/render/v2orthocamera.cpp \
    V2/render/v2perspectivecamera.cpp \
    V2/render/v2renderer.cpp \
    V2/render/v2window.cpp

INCLUDEPATH += V2/render/private
HEADERS += \
    V2/render/private/renderer.h \
    V2/render/private/renderdata.h

SOURCES += \
    V2/render/private/renderer.cpp \
    V2/render/private/renderdata.cpp



INCLUDEPATH += V2/Box2DPhysics
HEADERS+=\
    V2/Box2DPhysics/b2physicsmodule.h \
    V2/Box2DPhysics/b2physicsrigidbody.h

SOURCES+=\
    V2/Box2DPhysics/b2physicsmodule.cpp \
    V2/Box2DPhysics/b2physicsrigidbody.cpp
}

v2_test_app{
INCLUDEPATH += V2-app
SOURCES+= \
    V2-app/v2main.cpp \
    V2-app/mainwindow.cpp \
    V2-app/logic/carbodycreator.cpp \
    V2-app/logic/worldproperties.cpp \
    V2-app/v2car.cpp \
    V2-app/appcube.cpp \
    V2-app/v2appglwindow.cpp \
    V2-app/objects/brick.cpp \
    V2-app/logic/appcameracontrol.cpp

HEADERS += \
    V2-app/mainwindow.h \
    V2-app/logic/carbodycreator.h \
    V2-app/logic/worldproperties.h \
    V2-app/logic/cargenome.h \
    V2-app/appcube.h \
    V2-app/v2appglwindow.h \
    V2-app/v2car.h \
    V2-app/objects/brick.h \
    V2-app/logic/appcameracontrol.h

FORMS += \
    V2-app/mainwindow.ui
}

DESTDIR = ../bin/

HEADERS += \
    V2-app/objects/ground.h \
    V2-app/logic/world.h


SOURCES += \
    V2-app/objects/ground.cpp \
    V2-app/logic/world.cpp



