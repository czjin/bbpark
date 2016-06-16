/****************************************************************************
** Meta object code from reading C++ file 'adminsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/adminsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdminsObject_t {
    QByteArrayData data[8];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminsObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminsObject_t qt_meta_stringdata_AdminsObject = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AdminsObject"
QT_MOC_LITERAL(1, 13, 2), // "id"
QT_MOC_LITERAL(2, 16, 4), // "name"
QT_MOC_LITERAL(3, 21, 4), // "code"
QT_MOC_LITERAL(4, 26, 9), // "real_name"
QT_MOC_LITERAL(5, 36, 10), // "created_at"
QT_MOC_LITERAL(6, 47, 10), // "updated_at"
QT_MOC_LITERAL(7, 58, 13) // "lock_revision"

    },
    "AdminsObject\0id\0name\0code\0real_name\0"
    "created_at\0updated_at\0lock_revision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminsObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QDateTime, 0x00095003,
       6, QMetaType::QDateTime, 0x00095003,
       7, QMetaType::Int, 0x00095003,

       0        // eod
};

void AdminsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        AdminsObject *_t = static_cast<AdminsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getname(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getcode(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getreal_name(); break;
        case 4: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        case 5: *reinterpret_cast< QDateTime*>(_v) = _t->getupdated_at(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getlock_revision(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        AdminsObject *_t = static_cast<AdminsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setname(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setcode(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setreal_name(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 5: _t->setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 6: _t->setlock_revision(*reinterpret_cast< int*>(_v)); break;
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

const QMetaObject AdminsObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_AdminsObject.data,
      qt_meta_data_AdminsObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdminsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdminsObject.stringdata0))
        return static_cast<void*>(const_cast< AdminsObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< AdminsObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int AdminsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
