/****************************************************************************
** Meta object code from reading C++ file 'accountsrechargeobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/accountsrechargeobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountsrechargeobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AccountsRechargeObject_t {
    QByteArrayData data[7];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccountsRechargeObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccountsRechargeObject_t qt_meta_stringdata_AccountsRechargeObject = {
    {
QT_MOC_LITERAL(0, 0, 22), // "AccountsRechargeObject"
QT_MOC_LITERAL(1, 23, 2), // "id"
QT_MOC_LITERAL(2, 26, 7), // "user_id"
QT_MOC_LITERAL(3, 34, 6), // "amount"
QT_MOC_LITERAL(4, 41, 6), // "source"
QT_MOC_LITERAL(5, 48, 10), // "created_at"
QT_MOC_LITERAL(6, 59, 4) // "memo"

    },
    "AccountsRechargeObject\0id\0user_id\0"
    "amount\0source\0created_at\0memo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountsRechargeObject[] = {

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
       2, QMetaType::Int, 0x00095003,
       3, QMetaType::Double, 0x00095003,
       4, QMetaType::Int, 0x00095003,
       5, QMetaType::QDateTime, 0x00095003,
       6, QMetaType::QString, 0x00095003,

       0        // eod
};

void AccountsRechargeObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        AccountsRechargeObject *_t = static_cast<AccountsRechargeObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getuser_id(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->getamount(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getsource(); break;
        case 4: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getmemo(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        AccountsRechargeObject *_t = static_cast<AccountsRechargeObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setuser_id(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setamount(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setsource(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 5: _t->setmemo(*reinterpret_cast< QString*>(_v)); break;
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

const QMetaObject AccountsRechargeObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_AccountsRechargeObject.data,
      qt_meta_data_AccountsRechargeObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AccountsRechargeObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountsRechargeObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AccountsRechargeObject.stringdata0))
        return static_cast<void*>(const_cast< AccountsRechargeObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< AccountsRechargeObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int AccountsRechargeObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
