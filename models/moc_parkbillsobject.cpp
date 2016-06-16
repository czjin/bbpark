/****************************************************************************
** Meta object code from reading C++ file 'parkbillsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/parkbillsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parkbillsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParkBillsObject_t {
    QByteArrayData data[7];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParkBillsObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParkBillsObject_t qt_meta_stringdata_ParkBillsObject = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ParkBillsObject"
QT_MOC_LITERAL(1, 16, 2), // "id"
QT_MOC_LITERAL(2, 19, 10), // "session_id"
QT_MOC_LITERAL(3, 30, 6), // "source"
QT_MOC_LITERAL(4, 37, 6), // "amount"
QT_MOC_LITERAL(5, 44, 6), // "status"
QT_MOC_LITERAL(6, 51, 10) // "created_at"

    },
    "ParkBillsObject\0id\0session_id\0source\0"
    "amount\0status\0created_at"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParkBillsObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::Int, 0x00095003,
       4, QMetaType::Double, 0x00095003,
       5, QMetaType::Int, 0x00095003,
       6, QMetaType::QDateTime, 0x00095003,

       0        // eod
};

void ParkBillsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        ParkBillsObject *_t = static_cast<ParkBillsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getsession_id(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getsource(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getamount(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getstatus(); break;
        case 5: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ParkBillsObject *_t = static_cast<ParkBillsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setsession_id(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setsource(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setamount(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setstatus(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
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

const QMetaObject ParkBillsObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_ParkBillsObject.data,
      qt_meta_data_ParkBillsObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParkBillsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParkBillsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParkBillsObject.stringdata0))
        return static_cast<void*>(const_cast< ParkBillsObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< ParkBillsObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int ParkBillsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
