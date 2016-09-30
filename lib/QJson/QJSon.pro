TEMPLATE=lib
CONFIG += staticlib
TARGET=libQJSon
DESTDIR=../../bin

INCLUDEPATH += include/QJson
INCLUDEPATH += src
SOURCES+= src/json_parser.cc \
    src/json_scanner.cc \
    src/json_scanner.cpp \
    src/parser.cpp \
    src/parserrunnable.cpp \
    src/qobjecthelper.cpp \
    src/serializer.cpp \
    src/serializerrunnable.cpp

HEADERS+= include/QJson/Parser \
    include/QJson/QObjectHelper \
    include/QJson/Serializer \
    src/FlexLexer.h \
    src/json_parser.hh \
    src/json_scanner.h \
    src/location.hh \
    src/parser.h \
    src/parser_p.h \
    src/parserrunnable.h \
    src/position.hh \
    src/qjson_debug.h \
    src/qjson_export.h \
    src/qobjecthelper.h \
    src/serializer.h \
    src/serializerrunnable.h \
    src/stack.hh
