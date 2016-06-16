/****************************************************************************
** Meta object code from reading C++ file 'accountsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/accountsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AccountsObject_t {
    QByteArrayData data[14];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AccountsObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AccountsObject_t qt_meta_stringdata_AccountsObject = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AccountsObject"
QT_MOC_LITERAL(1, 15, 2), // "id"
QT_MOC_LITERAL(2, 18, 6), // "acc_no"
QT_MOC_LITERAL(3, 25, 7), // "user_id"
QT_MOC_LITERAL(4, 33, 8), // "pay_code"
QT_MOC_LITERAL(5, 42, 7), // "balance"
QT_MOC_LITERAL(6, 50, 6), // "credit"
QT_MOC_LITERAL(7, 57, 16), // "credit_available"
QT_MOC_LITERAL(8, 74, 6), // "status"
QT_MOC_LITERAL(9, 81, 4), // "type"
QT_MOC_LITERAL(10, 86, 6), // "issuer"
QT_MOC_LITERAL(11, 93, 10), // "created_at"
QT_MOC_LITERAL(12, 104, 10), // "updated_at"
QT_MOC_LITERAL(13, 115, 4) // "memo"

    },
    "AccountsObject\0id\0acc_no\0user_id\0"
    "pay_code\0balance\0credit\0credit_available\0"
    "status\0type\0issuer\0created_at\0updated_at\0"
    "memo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountsObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      13,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::Int, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::Double, 0x00095003,
       6, QMetaType::Double, 0x00095003,
       7, QMetaType::Double, 0x00095003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::Int, 0x00095003,
      10, QMetaType::QString, 0x00095003,
      11, QMetaType::QDateTime, 0x00095003,
      12, QMetaType::QDateTime, 0x00095003,
      13, QMetaType::QString, 0x00095003,

       0        // eod
};

void AccountsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        AccountsObject *_t = static_cast<AccountsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getacc_no(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getuser_id(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getpay_code(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->getbalance(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->getcredit(); break;
        case 6: *reinterpret_cast< double*>(_v) = _t->getcredit_available(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getstatus(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->gettype(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->getissuer(); break;
        case 10: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        case 11: *reinterpret_cast< QDateTime*>(_v) = _t->getupdated_at(); break;
        case 12: *reinterpret_cast< QString*>(_v) = _t->getmemo(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        AccountsObject *_t = static_cast<AccountsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setacc_no(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setuser_id(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setpay_code(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setbalance(*reinterpret_cast< double*>(_v)); break;
        case 5: _t->setcredit(*reinterpret_cast< double*>(_v)); break;
        case 6: _t->setcredit_available(*reinterpret_cast< double*>(_v)); break;
        case 7: _t->setstatus(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->settype(*reinterpret_cast< int*>(_v)); break;
        case 9: _t->setissuer(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 11: _t->setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 12: _t->setmemo(*reinterpret_cast< QString*>(_v)); break;
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

const QMetaObject AccountsObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_AccountsObject.data,
      qt_meta_data_AccountsObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AccountsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AccountsObject.stringdata0))
        return static_cast<void*>(const_cast< AccountsObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< AccountsObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int AccountsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 13;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 13;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
