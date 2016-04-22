#-------------------------------------------------
#
# Project created by QtCreator 2013-07-10T14:58:24
#
#-------------------------------------------------

QT += core gui
QT += opengl openglextensions

TARGET = mycar
TEMPLATE = app





QMAKE_LFLAGS+=/INCREMENTAL:NO

#default
#CONFIG += box2d_lib qjson_lib cars_app
#v2 app
CONFIG += v2_engine v2_test_app

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
INCLUDEPATH += V2
SOURCES += V2/renderer.cpp \
    V2/worldobject.cpp \
    V2/imodule.cpp \
    V2/renderdata.cpp \
    V2/v2engine.cpp \
    V2/v2scene.cpp

HEADERS += V2/worldobject.h \
    V2/imodule.h \
    V2/geometry.h \
    V2/engineresource.h \
    V2/renderdata.h \
    V2/v2engine.h \
    V2/v2scene.h \
    V2/renderer.h
}

v2_test_app{
INCLUDEPATH += V2-app
SOURCES+= \
    V2-app/v2main.cpp \
    V2-app/mainwindow.cpp

HEADERS += \
    V2-app/mainwindow.h

FORMS += \
    V2-app/mainwindow.ui
}

cars_app {
INCLUDEPATH += V1
SOURCES+=V1/main.cpp\
    V1/mainwindow.cpp \
    V1/world.cpp \
    V1/renderwidget.cpp \
    V1/car.cpp \
    V1/ground.cpp \
    V1/worldproperties.cpp \
    V1/carbodycreator.cpp \
    V1/contactfilter.cpp \
    V1/history.cpp \
    V1/historygraph.cpp \
    V1/glthread.cpp \
    V1/carfactory.cpp

HEADERS+=V1/mainwindow.h \
    V1/world.h \
    V1/renderwidget.h \
    V1/cargenome.h \
    V1/car.h \
    V1/ground.h \
    V1/worldproperties.h \
    V1/carbodycreator.h \
    V1/contactfilter.h \
    V1/history.h \
    V1/historygraph.h \
    V1/glthread.h \
    V1/carfactory.h
FORMS    += mainwindow.ui
}

DESTDIR = ../../

HEADERS += \
    V2/v2resource.h \
    V2/v2event.h \
    V2/v2window.h \
    V2-app/v2appglwindow.h \
    V2/v2event_classes.h \
    V2/v2eventhandler.h

SOURCES += \
    V2/v2event.cpp \
    V2/v2window.cpp \
    V2-app/v2appglwindow.cpp \
    V2/v2eventhandler.cpp

