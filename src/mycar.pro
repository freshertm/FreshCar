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
CONFIG += v2_engine v2_test_app glm_lib box2d_lib

glm_lib {
INCLUDEPATH += glm
}

box2d_lib {
INCLUDEPATH += Box2D
SOURCES+=  Box2D/Collision/b2TimeOfImpact.cpp \
    Box2D/Collision/b2DynamicTree.cpp \
    Box2D/Collision/b2Distance.cpp \
    Box2D/Collision/b2Collision.cpp \
    Box2D/Collision/b2CollidePolygon.cpp \
    Box2D/Collision/b2CollideEdge.cpp \
    Box2D/Collision/b2CollideCircle.cpp \
    Box2D/Collision/b2BroadPhase.cpp \
    Box2D/Collision/Shapes/b2PolygonShape.cpp \
    Box2D/Collision/Shapes/b2EdgeShape.cpp \
    Box2D/Collision/Shapes/b2CircleShape.cpp \
    Box2D/Collision/Shapes/b2ChainShape.cpp \
    Box2D/Common/b2Timer.cpp \
    Box2D/Common/b2StackAllocator.cpp \
    Box2D/Common/b2Settings.cpp \
    Box2D/Common/b2Math.cpp \
    Box2D/Common/b2Draw.cpp \
    Box2D/Common/b2BlockAllocator.cpp \
    Box2D/Dynamics/b2WorldCallbacks.cpp \
    Box2D/Dynamics/b2World.cpp \
    Box2D/Dynamics/b2Island.cpp \
    Box2D/Dynamics/b2Fixture.cpp \
    Box2D/Dynamics/b2ContactManager.cpp \
    Box2D/Dynamics/b2Body.cpp \
    Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    Box2D/Dynamics/Contacts/b2Contact.cpp \
    Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    Box2D/Dynamics/Joints/b2Joint.cpp \
    Box2D/Dynamics/Joints/b2GearJoint.cpp \
    Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    Box2D/Rope/b2Rope.cpp

HEADERS+=  Box2D/Box2D.h \
    Box2D/Collision/b2TimeOfImpact.h \
    Box2D/Collision/b2DynamicTree.h \
    Box2D/Collision/b2Distance.h \
    Box2D/Collision/b2Collision.h \
    Box2D/Collision/b2BroadPhase.h \
    Box2D/Collision/Shapes/b2Shape.h \
    Box2D/Collision/Shapes/b2PolygonShape.h \
    Box2D/Collision/Shapes/b2EdgeShape.h \
    Box2D/Collision/Shapes/b2CircleShape.h \
    Box2D/Collision/Shapes/b2ChainShape.h \
    Box2D/Common/b2Timer.h \
    Box2D/Common/b2StackAllocator.h \
    Box2D/Common/b2Settings.h \
    Box2D/Common/b2Math.h \
    Box2D/Common/b2GrowableStack.h \
    Box2D/Common/b2Draw.h \
    Box2D/Common/b2BlockAllocator.h \
    Box2D/Dynamics/b2WorldCallbacks.h \
    Box2D/Dynamics/b2World.h \
    Box2D/Dynamics/b2TimeStep.h \
    Box2D/Dynamics/b2Island.h \
    Box2D/Dynamics/b2Fixture.h \
    Box2D/Dynamics/b2ContactManager.h \
    Box2D/Dynamics/b2Body.h \
    Box2D/Dynamics/Contacts/b2PolygonContact.h \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2ContactSolver.h \
    Box2D/Dynamics/Contacts/b2Contact.h \
    Box2D/Dynamics/Contacts/b2CircleContact.h \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    Box2D/Dynamics/Joints/b2WheelJoint.h \
    Box2D/Dynamics/Joints/b2WeldJoint.h \
    Box2D/Dynamics/Joints/b2RopeJoint.h \
    Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    Box2D/Dynamics/Joints/b2PulleyJoint.h \
    Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    Box2D/Dynamics/Joints/b2MouseJoint.h \
    Box2D/Dynamics/Joints/b2Joint.h \
    Box2D/Dynamics/Joints/b2GearJoint.h \
    Box2D/Dynamics/Joints/b2FrictionJoint.h \
    Box2D/Dynamics/Joints/b2DistanceJoint.h \
    Box2D/Rope/b2Rope.h
}

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



INCLUDEPATH += V2/physics
HEADERS+=\
    V2/physics/v2physicsmodule.h \
    V2/physics/v2rigidbody.h

SOURCES+=\
    V2/physics/v2physicsmodule.cpp \
    V2/physics/v2rigidbody.cpp



INCLUDEPATH += V2/physics/private
HEADERS+=\
    V2/physics/private/b2physicsmodule.h \
    V2/physics/private/b2physicsrigidbody.h

SOURCES+=\
    V2/physics/private/b2physicsmodule.cpp \
    V2/physics/private/b2physicsrigidbody.cpp
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



