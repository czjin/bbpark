/****************************************************************************
** Meta object code from reading C++ file 'Utils.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../common/Utils.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Utils.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Utils_t {
    QByteArrayData data[24];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Utils_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Utils_t qt_meta_stringdata_Utils = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Utils"
QT_MOC_LITERAL(1, 6, 13), // "WriteSettings"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "theme"
QT_MOC_LITERAL(4, 27, 12), // "ReadSettings"
QT_MOC_LITERAL(5, 40, 14), // "gen_session_id"
QT_MOC_LITERAL(6, 55, 13), // "cal_free_time"
QT_MOC_LITERAL(7, 69, 14), // "order_duration"
QT_MOC_LITERAL(8, 84, 10), // "start_time"
QT_MOC_LITERAL(9, 95, 8), // "end_time"
QT_MOC_LITERAL(10, 104, 12), // "cal_park_fee"
QT_MOC_LITERAL(11, 117, 10), // "parking_id"
QT_MOC_LITERAL(12, 128, 13), // "cal_park_fee1"
QT_MOC_LITERAL(13, 142, 5), // "hours"
QT_MOC_LITERAL(14, 148, 7), // "minutes"
QT_MOC_LITERAL(15, 156, 13), // "cal_park_fee2"
QT_MOC_LITERAL(16, 170, 7), // "seconds"
QT_MOC_LITERAL(17, 178, 11), // "GetArchName"
QT_MOC_LITERAL(18, 190, 9), // "GetOSName"
QT_MOC_LITERAL(19, 200, 13), // "getMobileRegx"
QT_MOC_LITERAL(20, 214, 10), // "chineseFee"
QT_MOC_LITERAL(21, 225, 5), // "char*"
QT_MOC_LITERAL(22, 231, 4), // "dest"
QT_MOC_LITERAL(23, 236, 3) // "src"

    },
    "Utils\0WriteSettings\0\0theme\0ReadSettings\0"
    "gen_session_id\0cal_free_time\0"
    "order_duration\0start_time\0end_time\0"
    "cal_park_fee\0parking_id\0cal_park_fee1\0"
    "hours\0minutes\0cal_park_fee2\0seconds\0"
    "GetArchName\0GetOSName\0getMobileRegx\0"
    "chineseFee\0char*\0dest\0src"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Utils[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x0a /* Public */,
       4,    0,   72,    2, 0x0a /* Public */,
       5,    0,   73,    2, 0x0a /* Public */,
       6,    3,   74,    2, 0x0a /* Public */,
      10,    3,   81,    2, 0x0a /* Public */,
      12,    4,   88,    2, 0x0a /* Public */,
      15,    3,   97,    2, 0x0a /* Public */,
      17,    0,  104,    2, 0x0a /* Public */,
      18,    0,  105,    2, 0x0a /* Public */,
      19,    0,  106,    2, 0x0a /* Public */,
      20,    2,  107,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::Int, QMetaType::Int, QMetaType::QString, QMetaType::QString,    7,    8,    9,
    QMetaType::Float, QMetaType::Int, QMetaType::QString, QMetaType::QString,   11,    8,    9,
    QMetaType::Float, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::Int,   11,    8,   13,   14,
    QMetaType::Float, QMetaType::Int, QMetaType::QString, QMetaType::Int,   11,    8,   16,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    0x80000000 | 21, 0x80000000 | 21, 0x80000000 | 21,   22,   23,

       0        // eod
};

void Utils::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Utils *_t = static_cast<Utils *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->WriteSettings((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { int _r = _t->ReadSettings();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { QString _r = _t->gen_session_id();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->cal_free_time((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { float _r = _t->cal_park_fee((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 5: { float _r = _t->cal_park_fee1((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 6: { float _r = _t->cal_park_fee2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->GetArchName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { QString _r = _t->GetOSName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { QString _r = _t->getMobileRegx();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { char* _r = _t->chineseFee((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Utils::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Utils.data,
      qt_meta_data_Utils,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Utils::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Utils::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Utils.stringdata0))
        return static_cast<void*>(const_cast< Utils*>(this));
    return QObject::qt_metacast(_clname);
}

int Utils::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
