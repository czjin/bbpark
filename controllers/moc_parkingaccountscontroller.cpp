/****************************************************************************
** Meta object code from reading C++ file 'parkingaccountscontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "parkingaccountscontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parkingaccountscontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParkingAccountsController_t {
    QByteArrayData data[10];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParkingAccountsController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParkingAccountsController_t qt_meta_stringdata_ParkingAccountsController = {
    {
QT_MOC_LITERAL(0, 0, 25), // "ParkingAccountsController"
QT_MOC_LITERAL(1, 26, 5), // "index"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "show"
QT_MOC_LITERAL(4, 38, 2), // "pk"
QT_MOC_LITERAL(5, 41, 5), // "entry"
QT_MOC_LITERAL(6, 47, 6), // "create"
QT_MOC_LITERAL(7, 54, 4), // "edit"
QT_MOC_LITERAL(8, 59, 4), // "save"
QT_MOC_LITERAL(9, 64, 6) // "remove"

    },
    "ParkingAccountsController\0index\0\0show\0"
    "pk\0entry\0create\0edit\0save\0remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParkingAccountsController[] = {

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

void ParkingAccountsController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParkingAccountsController *_t = static_cast<ParkingAccountsController *>(_o);
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

const QMetaObject ParkingAccountsController::staticMetaObject = {
    { &ApplicationController::staticMetaObject, qt_meta_stringdata_ParkingAccountsController.data,
      qt_meta_data_ParkingAccountsController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ParkingAccountsController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParkingAccountsController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ParkingAccountsController.stringdata0))
        return static_cast<void*>(const_cast< ParkingAccountsController*>(this));
    return ApplicationController::qt_metacast(_clname);
}

int ParkingAccountsController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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