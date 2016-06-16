/****************************************************************************
** Meta object code from reading C++ file 'parkcouponobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/parkcouponobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parkcouponobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParkCouponObject_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParkCouponObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParkCouponObject_t qt_meta_stringdata_ParkCouponObject = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ParkCouponObject"
QT_MOC_LITERAL(1, 17, 2), // "id"
QT_MOC_LITERAL(2, 20, 9), // "coupon_no"
QT_MOC_LITERAL(3, 30, 10), // "check_code"
QT_MOC_LITERAL(4, 41, 6), // "amount"
QT_MOC_LITERAL(5, 48, 6), // "status"
QT_MOC_LITERAL(6, 55, 10), // "created_at"
QT_MOC_LITERAL(7, 66, 8), // "use_time"
QT_MOC_LITERAL(8, 75, 10) // "valid_till"

    },
    "ParkCouponObject\0id\0coupon_no\0check_code\0"
    "amount\0status\0created_at\0use_time\0"
    "valid_till"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParkCouponObject[] = {

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
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::Double, 0x00095003,
       5, QMetaType::Int, 0x00095003,
       6, QMetaType::QDateTime, 0x00095003,
       7, QMetaType::QDateTime, 0x00095003,
       8, QMetaType::QDateTime, 0x00095003,

       0        // eod
};

void ParkCouponObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        ParkCouponObject *_t = static_cast<ParkCouponObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getcoupon_no(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getcheck_code(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getamount(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getstatus(); break;
        case 5: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        case 6: *reinterpret_cast< QDateTime*>(_v) = _t->getuse_time(); break;
        case 7: *reinterpret_cast< QDateTime*>(_v) = _t->getvalid_till(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ParkCouponObject *_t = static_cast<ParkCouponObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setcoupon_no(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setcheck_code(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setamount(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setstatus(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 6: _t->setuse_time(*reinterpret_cast< QDateTime*>(_v)); break;
        case 7: _t->setvalid_till(*reinterpret_cast< QDateTime*>(_v)); break;
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

const QMetaObject ParkCouponObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_ParkCouponObject.data,
      qt_meta_data_ParkCouponObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParkCouponObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParkCouponObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParkCouponObject.stringdata0))
        return static_cast<void*>(const_cast< ParkCouponObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< ParkCouponObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int ParkCouponObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
