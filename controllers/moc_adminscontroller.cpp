/****************************************************************************
** Meta object code from reading C++ file 'adminscontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "adminscontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminscontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AdminsController_t {
    QByteArrayData data[10];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdminsController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdminsController_t qt_meta_stringdata_AdminsController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AdminsController"
QT_MOC_LITERAL(1, 17, 5), // "index"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "show"
QT_MOC_LITERAL(4, 29, 2), // "pk"
QT_MOC_LITERAL(5, 32, 5), // "entry"
QT_MOC_LITERAL(6, 38, 6), // "create"
QT_MOC_LITERAL(7, 45, 4), // "edit"
QT_MOC_LITERAL(8, 50, 4), // "save"
QT_MOC_LITERAL(9, 55, 6) // "remove"

    },
    "AdminsController\0index\0\0show\0pk\0entry\0"
    "create\0edit\0save\0remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminsController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    1,   50,    2, 0x0a /* Public */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
       8,    1,   58,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void AdminsController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AdminsController *_t = static_cast<AdminsController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->index(); break;
        case 1: _t->show((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->entry(); break;
        case 3: _t->create(); break;
        case 4: _t->edit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->save((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->remove((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AdminsController::staticMetaObject = {
    { &ApplicationController::staticMetaObject, qt_meta_stringdata_AdminsController.data,
      qt_meta_data_AdminsController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdminsController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminsController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdminsController.stringdata0))
        return static_cast<void*>(const_cast< AdminsController*>(this));
    return ApplicationController::qt_metacast(_clname);
}

int AdminsController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApplicationController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
