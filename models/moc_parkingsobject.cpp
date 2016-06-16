/****************************************************************************
** Meta object code from reading C++ file 'parkingsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/parkingsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parkingsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParkingsObject_t {
    QByteArrayData data[18];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParkingsObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParkingsObject_t qt_meta_stringdata_ParkingsObject = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ParkingsObject"
QT_MOC_LITERAL(1, 15, 2), // "id"
QT_MOC_LITERAL(2, 18, 4), // "name"
QT_MOC_LITERAL(3, 23, 11), // "description"
QT_MOC_LITERAL(4, 35, 4), // "addr"
QT_MOC_LITERAL(5, 40, 15), // "charge_standard"
QT_MOC_LITERAL(6, 56, 9), // "longitude"
QT_MOC_LITERAL(7, 66, 8), // "latitude"
QT_MOC_LITERAL(8, 75, 4), // "type"
QT_MOC_LITERAL(9, 80, 9), // "plan_path"
QT_MOC_LITERAL(10, 90, 11), // "space_start"
QT_MOC_LITERAL(11, 102, 11), // "space_total"
QT_MOC_LITERAL(12, 114, 10), // "space_free"
QT_MOC_LITERAL(13, 125, 9), // "qrcode_id"
QT_MOC_LITERAL(14, 135, 4), // "memo"
QT_MOC_LITERAL(15, 140, 10), // "created_at"
QT_MOC_LITERAL(16, 151, 10), // "updated_at"
QT_MOC_LITERAL(17, 162, 13) // "lock_revision"

    },
    "ParkingsObject\0id\0name\0description\0"
    "addr\0charge_standard\0longitude\0latitude\0"
    "type\0plan_path\0space_start\0space_total\0"
    "space_free\0qrcode_id\0memo\0created_at\0"
    "updated_at\0lock_revision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParkingsObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      17,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::Double, 0x00095003,
       7, QMetaType::Double, 0x00095003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::QString, 0x00095003,
      10, QMetaType::QString, 0x00095003,
      11, QMetaType::Int, 0x00095003,
      12, QMetaType::Int, 0x00095003,
      13, QMetaType::Int, 0x00095003,
      14, QMetaType::QString, 0x00095003,
      15, QMetaType::QDateTime, 0x00095003,
      16, QMetaType::QDateTime, 0x00095003,
      17, QMetaType::Int, 0x00095003,

       0        // eod
};

void ParkingsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        ParkingsObject *_t = static_cast<ParkingsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getname(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getdescription(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getaddr(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getcharge_standard(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->getlongitude(); break;
        case 6: *reinterpret_cast< double*>(_v) = _t->getlatitude(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->gettype(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->getplan_path(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->getspace_start(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->getspace_total(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->getspace_free(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->getqrcode_id(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->getmemo(); break;
        case 14: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        case 15: *reinterpret_cast< QDateTime*>(_v) = _t->getupdated_at(); break;
        case 16: *reinterpret_cast< int*>(_v) = _t->getlock_revision(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ParkingsObject *_t = static_cast<ParkingsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setname(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setdescription(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setaddr(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setcharge_standard(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setlongitude(*reinterpret_cast< double*>(_v)); break;
        case 6: _t->setlatitude(*reinterpret_cast< double*>(_v)); break;
        case 7: _t->settype(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setplan_path(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setspace_start(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->setspace_total(*reinterpret_cast< int*>(_v)); break;
        case 11: _t->setspace_free(*reinterpret_cast< int*>(_v)); break;
        case 12: _t->setqrcode_id(*reinterpret_cast< int*>(_v)); break;
        case 13: _t->setmemo(*reinterpret_cast< QString*>(_v)); break;
        case 14: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 15: _t->setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 16: _t->setlock_revision(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ParkingsObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_ParkingsObject.data,
      qt_meta_data_ParkingsObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParkingsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParkingsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParkingsObject.stringdata0))
        return static_cast<void*>(const_cast< ParkingsObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< ParkingsObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int ParkingsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 17;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
