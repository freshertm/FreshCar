/****************************************************************************
** Meta object code from reading C++ file 'world.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/world.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'world.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_World_t {
    QByteArrayData data[10];
    char stringdata[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_World_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_World_t qt_meta_stringdata_World = {
    {
QT_MOC_LITERAL(0, 0, 5), // "World"
QT_MOC_LITERAL(1, 6, 13), // "newGeneration"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "newCar"
QT_MOC_LITERAL(4, 28, 10), // "const Car*"
QT_MOC_LITERAL(5, 39, 3), // "car"
QT_MOC_LITERAL(6, 43, 12), // "addRandomCar"
QT_MOC_LITERAL(7, 56, 9), // "saveState"
QT_MOC_LITERAL(8, 66, 8), // "filename"
QT_MOC_LITERAL(9, 75, 9) // "loadState"

    },
    "World\0newGeneration\0\0newCar\0const Car*\0"
    "car\0addRandomCar\0saveState\0filename\0"
    "loadState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_World[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x0a /* Public */,
       7,    1,   44,    2, 0x0a /* Public */,
       9,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void World::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        World *_t = static_cast<World *>(_o);
        switch (_id) {
        case 0: _t->newGeneration(); break;
        case 1: _t->newCar((*reinterpret_cast< const Car*(*)>(_a[1]))); break;
        case 2: _t->addRandomCar(); break;
        case 3: _t->saveState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->loadState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (World::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&World::newGeneration)) {
                *result = 0;
            }
        }
        {
            typedef void (World::*_t)(const Car * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&World::newCar)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject World::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_World.data,
      qt_meta_data_World,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *World::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *World::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_World.stringdata))
        return static_cast<void*>(const_cast< World*>(this));
    return QObject::qt_metacast(_clname);
}

int World::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void World::newGeneration()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void World::newCar(const Car * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
