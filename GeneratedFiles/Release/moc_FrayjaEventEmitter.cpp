/****************************************************************************
** Meta object code from reading C++ file 'FrayjaEventEmitter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Sources/Core/FrayjaEventEmitter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrayjaEventEmitter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrayjaEventEmitter_t {
    QByteArrayData data[13];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrayjaEventEmitter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrayjaEventEmitter_t qt_meta_stringdata_FrayjaEventEmitter = {
    {
QT_MOC_LITERAL(0, 0, 18), // "FrayjaEventEmitter"
QT_MOC_LITERAL(1, 19, 3), // "log"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "LogType"
QT_MOC_LITERAL(4, 32, 4), // "type"
QT_MOC_LITERAL(5, 37, 11), // "std::string"
QT_MOC_LITERAL(6, 49, 3), // "msg"
QT_MOC_LITERAL(7, 53, 13), // "renderedImage"
QT_MOC_LITERAL(8, 67, 13), // "pixelRendered"
QT_MOC_LITERAL(9, 81, 1), // "x"
QT_MOC_LITERAL(10, 83, 1), // "y"
QT_MOC_LITERAL(11, 85, 4), // "Vec3"
QT_MOC_LITERAL(12, 90, 5) // "color"

    },
    "FrayjaEventEmitter\0log\0\0LogType\0type\0"
    "std::string\0msg\0renderedImage\0"
    "pixelRendered\0x\0y\0Vec3\0color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrayjaEventEmitter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       7,    0,   34,    2, 0x06 /* Public */,
       8,    3,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 11,    9,   10,   12,

       0        // eod
};

void FrayjaEventEmitter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrayjaEventEmitter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< LogType(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 1: _t->renderedImage(); break;
        case 2: _t->pixelRendered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< Vec3(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FrayjaEventEmitter::*)(LogType , std::string ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrayjaEventEmitter::log)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FrayjaEventEmitter::*)() const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrayjaEventEmitter::renderedImage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FrayjaEventEmitter::*)(int , int , Vec3 ) const;
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrayjaEventEmitter::pixelRendered)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FrayjaEventEmitter::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_FrayjaEventEmitter.data,
    qt_meta_data_FrayjaEventEmitter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FrayjaEventEmitter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrayjaEventEmitter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrayjaEventEmitter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FrayjaEventEmitter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FrayjaEventEmitter::log(LogType _t1, std::string _t2)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< FrayjaEventEmitter *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FrayjaEventEmitter::renderedImage()const
{
    QMetaObject::activate(const_cast< FrayjaEventEmitter *>(this), &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FrayjaEventEmitter::pixelRendered(int _t1, int _t2, Vec3 _t3)const
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(const_cast< FrayjaEventEmitter *>(this), &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
