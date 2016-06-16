/****************************************************************************
** Meta object code from reading C++ file 'parkprepayobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/parkprepayobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parkprepayobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParkPrepayObject_t {
    QByteArrayData data[6];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParkPrepayObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParkPrepayObject_t qt_meta_stringdata_ParkPrepayObject = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ParkPrepayObject"
QT_MOC_LITERAL(1, 17, 2), // "id"
QT_MOC_LITERAL(2, 20, 7), // "user_id"
QT_MOC_LITERAL(3, 28, 10), // "session_id"
QT_MOC_LITERAL(4, 39, 7), // "prepaid"
QT_MOC_LITERAL(5, 47, 10) // "created_at"

    },
    "ParkPrepayObject\0id\0user_id\0session_id\0"
    "prepaid\0created_at"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParkPrepayObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::Int, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::Double, 0x00095003,
       5, QMetaType::QDateTime, 0x00095003,

       0        // eod
};

void ParkPrepayObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        ParkPrepayObject *_t = static_cast<ParkPrepayObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getuser_id(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getsession_id(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getprepaid(); break;
        case 4: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ParkPrepayObject *_t = static_cast<ParkPrepayObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setuser_id(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setsession_id(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setprepaid(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
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

const QMetaObject ParkPrepayObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_ParkPrepayObject.data,
      qt_meta_data_ParkPrepayObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParkPrepayObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParkPrepayObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParkPrepayObject.stringdata0))
        return static_cast<void*>(const_cast< ParkPrepayObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< ParkPrepayObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int ParkPrepayObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
