/****************************************************************************
** Meta object code from reading C++ file 'GRender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Graphics/GRender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GRender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GRender_t {
    QByteArrayData data[3];
    char stringdata[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GRender_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GRender_t qt_meta_stringdata_GRender = {
    {
QT_MOC_LITERAL(0, 0, 7), // "GRender"
QT_MOC_LITERAL(1, 8, 17), // "OpenGLInitialized"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "GRender\0OpenGLInitialized\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GRender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void GRender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GRender *_t = static_cast<GRender *>(_o);
        switch (_id) {
        case 0: _t->OpenGLInitialized(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GRender::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GRender::OpenGLInitialized)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GRender::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_GRender.data,
      qt_meta_data_GRender,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GRender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GRender::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GRender.stringdata))
        return static_cast<void*>(const_cast< GRender*>(this));
    if (!strcmp(_clname, "QOpenGLFunctions_3_3_Compatibility"))
        return static_cast< QOpenGLFunctions_3_3_Compatibility*>(const_cast< GRender*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int GRender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GRender::OpenGLInitialized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
