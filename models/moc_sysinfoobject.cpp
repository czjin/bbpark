/****************************************************************************
** Meta object code from reading C++ file 'sysinfoobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/sysinfoobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sysinfoobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SysinfoObject_t {
    QByteArrayData data[10];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SysinfoObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SysinfoObject_t qt_meta_stringdata_SysinfoObject = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SysinfoObject"
QT_MOC_LITERAL(1, 14, 2), // "id"
QT_MOC_LITERAL(2, 17, 7), // "company"
QT_MOC_LITERAL(3, 25, 6), // "slogan"
QT_MOC_LITERAL(4, 32, 7), // "website"
QT_MOC_LITERAL(5, 40, 15), // "contact_hotline"
QT_MOC_LITERAL(6, 56, 8), // "serv_ver"
QT_MOC_LITERAL(7, 65, 7), // "app_ver"
QT_MOC_LITERAL(8, 73, 11), // "handset_ver"
QT_MOC_LITERAL(9, 85, 10) // "created_at"

    },
    "SysinfoObject\0id\0company\0slogan\0website\0"
    "contact_hotline\0serv_ver\0app_ver\0"
    "handset_ver\0created_at"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SysinfoObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       9,   14, // properties
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
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::QString, 0x00095003,
       8, QMetaType::QString, 0x00095003,
       9, QMetaType::QDateTime, 0x00095003,

       0        // eod
};

void SysinfoObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        SysinfoObject *_t = static_cast<SysinfoObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getcompany(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getslogan(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getwebsite(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getcontact_hotline(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getserv_ver(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->getapp_ver(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->gethandset_ver(); break;
        case 8: *reinterpret_cast< QDateTime*>(_v) = _t->getcreated_at(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        SysinfoObject *_t = static_cast<SysinfoObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setcompany(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setslogan(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setwebsite(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setcontact_hotline(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setserv_ver(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setapp_ver(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->sethandset_ver(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
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

const QMetaObject SysinfoObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_SysinfoObject.data,
      qt_meta_data_SysinfoObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SysinfoObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SysinfoObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SysinfoObject.stringdata0))
        return static_cast<void*>(const_cast< SysinfoObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< SysinfoObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int SysinfoObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
