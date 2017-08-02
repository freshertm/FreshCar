TEMPLATE=lib
CONFIG += staticlib
TARGET=libv2
DESTDIR=../../bin
QT += core gui widgets
DEFINES += USE_V2

INCLUDEPATH += ../../lib
INCLUDEPATH += core
SOURCES += \
    core/v2engine.cpp \
    core/v2module.cpp \
    core/v2object.cpp \
    core/v2scene.cpp \
    render/v2lightmanager.cpp

HEADERS += \
    core/v2engine.h \
    core/v2module.h \
    core/v2object.h \
    core/v2resource.h \
    core/v2scene.h \
    render/v2lightmanager.h



INCLUDEPATH += render
HEADERS += \
    render/v2geometry.h \
    render/v2renderproperties.h \
    render/v2camera.h \
    render/v2cameralist.h \
    render/v2color.h \
    render/v2orthocamera.h \
    render/v2perspectivecamera.h \
    render/v2renderer.h \
    render/v2window.h

SOURCES += \
    render/v2renderproperties.cpp \
    render/v2camera.cpp \
    render/v2cameralist.cpp \
    render/v2orthocamera.cpp \
    render/v2perspectivecamera.cpp \
    render/v2renderer.cpp \
    render/v2window.cpp

INCLUDEPATH += render/private
HEADERS += \
    render/private/renderer.h \
    render/private/renderdata.h

SOURCES += \
    render/private/renderer.cpp \
    render/private/renderdata.cpp


INCLUDEPATH += physics
SOURCES+=physics/v2rigidbody2d.cpp
HEADERS+=physics/v2rigidbody2d.h

INCLUDEPATH += Box2DPhysics
HEADERS+=\
    Box2DPhysics/b2physicsmodule.h \
    Box2DPhysics/b2physicsrigidbody.h

SOURCES+=\
    Box2DPhysics/b2physicsmodule.cpp \
    Box2DPhysics/b2physicsrigidbody.cpp
