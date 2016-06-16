/****************************************************************************
** Meta object code from reading C++ file 'parksobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/parksobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parksobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParksObject_t {
    QByteArrayData data[17];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParksObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParksObject_t qt_meta_stringdata_ParksObject = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ParksObject"
QT_MOC_LITERAL(1, 12, 2), // "id"
QT_MOC_LITERAL(2, 15, 10), // "session_id"
QT_MOC_LITERAL(3, 26, 7), // "user_id"
QT_MOC_LITERAL(4, 34, 10), // "vehicle_id"
QT_MOC_LITERAL(5, 45, 10), // "parking_id"
QT_MOC_LITERAL(6, 56, 16), // "parking_space_no"
QT_MOC_LITERAL(7, 73, 10), // "start_time"
QT_MOC_LITERAL(8, 84, 8), // "end_time"
QT_MOC_LITERAL(9, 93, 8), // "park_fee"
QT_MOC_LITERAL(10, 102, 7), // "prepaid"
QT_MOC_LITERAL(11, 110, 14), // "order_duration"
QT_MOC_LITERAL(12, 125, 6), // "status"
QT_MOC_LITERAL(13, 132, 8), // "pay_mode"
QT_MOC_LITERAL(14, 141, 10), // "pay_source"
QT_MOC_LITERAL(15, 152, 11), // "qrcode_path"
QT_MOC_LITERAL(16, 164, 4) // "memo"

    },
    "ParksObject\0id\0session_id\0user_id\0"
    "vehicle_id\0parking_id\0parking_space_no\0"
    "start_time\0end_time\0park_fee\0prepaid\0"
    "order_duration\0status\0pay_mode\0"
    "pay_source\0qrcode_path\0memo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParksObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      16,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::Int, 0x00095003,
       4, QMetaType::Int, 0x00095003,
       5, QMetaType::Int, 0x00095003,
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::QDateTime, 0x00095003,
       8, QMetaType::QDateTime, 0x00095003,
       9, QMetaType::Double, 0x00095003,
      10, QMetaType::Double, 0x00095003,
      11, QMetaType::Int, 0x00095003,
      12, QMetaType::Int, 0x00095003,
      13, QMetaType::Int, 0x00095003,
      14, QMetaType::Int, 0x00095003,
      15, QMetaType::QString, 0x00095003,
      16, QMetaType::QString, 0x00095003,

       0        // eod
};

void ParksObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        ParksObject *_t = static_cast<ParksObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getsession_id(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getuser_id(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getvehicle_id(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getparking_id(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getparking_space_no(); break;
        case 6: *reinterpret_cast< QDateTime*>(_v) = _t->getstart_time(); break;
        case 7: *reinterpret_cast< QDateTime*>(_v) = _t->getend_time(); break;
        case 8: *reinterpret_cast< double*>(_v) = _t->getpark_fee(); break;
        case 9: *reinterpret_cast< double*>(_v) = _t->getprepaid(); break;
        case 10: *reinterpret_cast< int*>(_v) = _t->getorder_duration(); break;
        case 11: *reinterpret_cast< int*>(_v) = _t->getstatus(); break;
        case 12: *reinterpret_cast< int*>(_v) = _t->getpay_mode(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->getpay_source(); break;
        case 14: *reinterpret_cast< QString*>(_v) = _t->getqrcode_path(); break;
        case 15: *reinterpret_cast< QString*>(_v) = _t->getmemo(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ParksObject *_t = static_cast<ParksObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setsession_id(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setuser_id(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setvehicle_id(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setparking_id(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setparking_space_no(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setstart_time(*reinterpret_cast< QDateTime*>(_v)); break;
        case 7: _t->setend_time(*reinterpret_cast< QDateTime*>(_v)); break;
        case 8: _t->setpark_fee(*reinterpret_cast< double*>(_v)); break;
        case 9: _t->setprepaid(*reinterpret_cast< double*>(_v)); break;
        case 10: _t->setorder_duration(*reinterpret_cast< int*>(_v)); break;
        case 11: _t->setstatus(*reinterpret_cast< int*>(_v)); break;
        case 12: _t->setpay_mode(*reinterpret_cast< int*>(_v)); break;
        case 13: _t->setpay_source(*reinterpret_cast< int*>(_v)); break;
        case 14: _t->setqrcode_path(*reinterpret_cast< QString*>(_v)); break;
        case 15: _t->setmemo(*reinterpret_cast< QString*>(_v)); break;
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

const QMetaObject ParksObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_ParksObject.data,
      qt_meta_data_ParksObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParksObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParksObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParksObject.stringdata0))
        return static_cast<void*>(const_cast< ParksObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< ParksObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int ParksObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 16;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 16;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
