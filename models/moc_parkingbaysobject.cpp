/****************************************************************************
** Meta object code from reading C++ file 'parkingbaysobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/parkingbaysobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parkingbaysobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParkingBaysObject_t {
    QByteArrayData data[9];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParkingBaysObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParkingBaysObject_t qt_meta_stringdata_ParkingBaysObject = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ParkingBaysObject"
QT_MOC_LITERAL(1, 18, 2), // "id"
QT_MOC_LITERAL(2, 21, 10), // "parking_id"
QT_MOC_LITERAL(3, 32, 6), // "number"
QT_MOC_LITERAL(4, 39, 6), // "status"
QT_MOC_LITERAL(5, 46, 11), // "qrcode_path"
QT_MOC_LITERAL(6, 58, 10), // "created_at"
QT_MOC_LITERAL(7, 69, 10), // "updated_at"
QT_MOC_LITERAL(8, 80, 13) // "lock_revision"

    },
    "ParkingBaysObject\0id\0parking_id\0number\0"
    "status\0qrcode_path\0created_at\0updated_at\0"
    "lock_revision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParkingBaysObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       8,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::Int, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::Int, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QDateTime, 0x00095003,
       7, QMetaType::QDateTime, 0x00095003,
       8, QMetaType::Int, 0x00095003,

       0        // eod
};

void ParkingBaysObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        ParkingBaysObject *_t = static_cast<ParkingBaysObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getparking_id(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getnumber(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getstatus(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getqrcode_path(); break;
        case 5: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        case 6: *reinterpret_cast< QDateTime*>(_v) = _t->getupdated_at(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getlock_revision(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ParkingBaysObject *_t = static_cast<ParkingBaysObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setparking_id(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setnumber(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setstatus(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setqrcode_path(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 6: _t->setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 7: _t->setlock_revision(*reinterpret_cast< int*>(_v)); break;
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

const QMetaObject ParkingBaysObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_ParkingBaysObject.data,
      qt_meta_data_ParkingBaysObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParkingBaysObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParkingBaysObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParkingBaysObject.stringdata0))
        return static_cast<void*>(const_cast< ParkingBaysObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< ParkingBaysObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int ParkingBaysObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE