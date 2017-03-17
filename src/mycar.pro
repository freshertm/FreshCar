#-------------------------------------------------
#
# Project created by QtCreator 2013-07-10T14:58:24
#
#-------------------------------------------------

QT += core gui widgets
QT += opengl
# openglextensions
DESTDIR = ../../dest/

TARGET = mycar
TEMPLATE = app

QMAKE_LFLAGS+= /INCREMENTAL:NO

INCLUDEPATH += V2/core
INCLUDEPATH += V2/render
INCLUDEPATH += V2/physics
INCLUDEPATH += V2/Box2DPhysics
INCLUDEPATH += ../lib

INCLUDEPATH += V2-app
SOURCES+= \
    V2-app/v2main.cpp \
    V2-app/mainwindow.cpp \
    V2-app/appcube.cpp \
    V2-app/v2appglwindow.cpp \
    V2-app/objects/brick.cpp \
    V2-app/logic/appcameracontrol.cpp
    #V2-app/v2car.cpp \
    #V2-app/logic/worldproperties.cpp \
    #V2-app/objects/ground.cpp \
    #V2-app/logic/world.cpp
    #V2-app/logic/carbodycreator.cpp \

HEADERS += \
    V2-app/mainwindow.h \
    V2-app/appcube.h \
    V2-app/v2appglwindow.h \
    V2-app/objects/brick.h \
    V2-app/logic/appcameracontrol.h
    V2-app/objects/ground.h \
    #V2-app/logic/world.h
    #V2-app/logic/worldproperties.h \
    #V2-app/v2car.h \
    #V2-app/logic/cargenome.h \
    #V2-app/logic/carbodycreator.h \

FORMS += \
    V2-app/mainwindow.ui


LIBS += ../bin/libQJson.lib \
 ../bin/libv2.lib \
 ../bin/libglm.lib \
 ../bin/libBox2d.lib

LIBS += opengl32.lib
