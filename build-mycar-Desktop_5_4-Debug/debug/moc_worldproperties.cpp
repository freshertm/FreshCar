/****************************************************************************
** Meta object code from reading C++ file 'worldproperties.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/worldproperties.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worldproperties.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WorldProperties_t {
    QByteArrayData data[19];
    char stringdata[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorldProperties_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorldProperties_t qt_meta_stringdata_WorldProperties = {
    {
QT_MOC_LITERAL(0, 0, 15), // "WorldProperties"
QT_MOC_LITERAL(1, 16, 13), // "setPopulation"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "setBodyFriction"
QT_MOC_LITERAL(4, 47, 16), // "setWheelFriction"
QT_MOC_LITERAL(5, 64, 17), // "setGroundFriction"
QT_MOC_LITERAL(6, 82, 17), // "setWheelMaxRadius"
QT_MOC_LITERAL(7, 100, 17), // "setWheelMinRadius"
QT_MOC_LITERAL(8, 118, 16), // "setWheelMaxSpeed"
QT_MOC_LITERAL(9, 135, 16), // "setWheelMinSpeed"
QT_MOC_LITERAL(10, 152, 17), // "setTimeMultiplier"
QT_MOC_LITERAL(11, 170, 13), // "setCarDieTime"
QT_MOC_LITERAL(12, 184, 16), // "setGenomeMixPart"
QT_MOC_LITERAL(13, 201, 19), // "setGenomeMutateRate"
QT_MOC_LITERAL(14, 221, 23), // "setGenomeMutateMaxCount"
QT_MOC_LITERAL(15, 245, 12), // "setDynasties"
QT_MOC_LITERAL(16, 258, 11), // "setMixCross"
QT_MOC_LITERAL(17, 270, 15), // "setMixCarsCount"
QT_MOC_LITERAL(18, 286, 16) // "setTrianglePower"

    },
    "WorldProperties\0setPopulation\0\0"
    "setBodyFriction\0setWheelFriction\0"
    "setGroundFriction\0setWheelMaxRadius\0"
    "setWheelMinRadius\0setWheelMaxSpeed\0"
    "setWheelMinSpeed\0setTimeMultiplier\0"
    "setCarDieTime\0setGenomeMixPart\0"
    "setGenomeMutateRate\0setGenomeMutateMaxCount\0"
    "setDynasties\0setMixCross\0setMixCarsCount\0"
    "setTrianglePower"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorldProperties[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x0a /* Public */,
       3,    1,  102,    2, 0x0a /* Public */,
       4,    1,  105,    2, 0x0a /* Public */,
       5,    1,  108,    2, 0x0a /* Public */,
       6,    1,  111,    2, 0x0a /* Public */,
       7,    1,  114,    2, 0x0a /* Public */,
       8,    1,  117,    2, 0x0a /* Public */,
       9,    1,  120,    2, 0x0a /* Public */,
      10,    1,  123,    2, 0x0a /* Public */,
      11,    1,  126,    2, 0x0a /* Public */,
      12,    1,  129,    2, 0x0a /* Public */,
      13,    1,  132,    2, 0x0a /* Public */,
      14,    1,  135,    2, 0x0a /* Public */,
      15,    1,  138,    2, 0x0a /* Public */,
      16,    1,  141,    2, 0x0a /* Public */,
      17,    1,  144,    2, 0x0a /* Public */,
      18,    1,  147,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void WorldProperties::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorldProperties *_t = static_cast<WorldProperties *>(_o);
        switch (_id) {
        case 0: _t->setPopulation((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 1: _t->setBodyFriction((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setWheelFriction((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setGroundFriction((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setWheelMaxRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setWheelMinRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setWheelMaxSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setWheelMinSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setTimeMultiplier((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setCarDieTime((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setGenomeMixPart((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 11: _t->setGenomeMutateRate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->setGenomeMutateMaxCount((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 13: _t->setDynasties((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 14: _t->setMixCross((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 15: _t->setMixCarsCount((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 16: _t->setTrianglePower((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WorldProperties::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WorldProperties.data,
      qt_meta_data_WorldProperties,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorldProperties::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorldProperties::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorldProperties.stringdata))
        return static_cast<void*>(const_cast< WorldProperties*>(this));
    return QObject::qt_metacast(_clname);
}

int WorldProperties::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
