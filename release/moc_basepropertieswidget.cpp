/****************************************************************************
** Meta object code from reading C++ file 'basepropertieswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../basepropertieswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basepropertieswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BasePropertiesWidget_t {
    QByteArrayData data[9];
    char stringdata[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BasePropertiesWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BasePropertiesWidget_t qt_meta_stringdata_BasePropertiesWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "BasePropertiesWidget"
QT_MOC_LITERAL(1, 21, 14), // "SendParameters"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "s_MBSParameters"
QT_MOC_LITERAL(4, 53, 30), // "on_radioButton_Default_clicked"
QT_MOC_LITERAL(5, 84, 34), // "on_radioButton_LoadedModel_cl..."
QT_MOC_LITERAL(6, 119, 25), // "on_pushButton_OK__clicked"
QT_MOC_LITERAL(7, 145, 28), // "on_pushButton_Apply__clicked"
QT_MOC_LITERAL(8, 174, 29) // "on_pushButton_Cancel__clicked"

    },
    "BasePropertiesWidget\0SendParameters\0"
    "\0s_MBSParameters\0on_radioButton_Default_clicked\0"
    "on_radioButton_LoadedModel_clicked\0"
    "on_pushButton_OK__clicked\0"
    "on_pushButton_Apply__clicked\0"
    "on_pushButton_Cancel__clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasePropertiesWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BasePropertiesWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BasePropertiesWidget *_t = static_cast<BasePropertiesWidget *>(_o);
        switch (_id) {
        case 0: _t->SendParameters((*reinterpret_cast< s_MBSParameters(*)>(_a[1]))); break;
        case 1: _t->on_radioButton_Default_clicked(); break;
        case 2: _t->on_radioButton_LoadedModel_clicked(); break;
        case 3: _t->on_pushButton_OK__clicked(); break;
        case 4: _t->on_pushButton_Apply__clicked(); break;
        case 5: _t->on_pushButton_Cancel__clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BasePropertiesWidget::*_t)(s_MBSParameters );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BasePropertiesWidget::SendParameters)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject BasePropertiesWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BasePropertiesWidget.data,
      qt_meta_data_BasePropertiesWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BasePropertiesWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasePropertiesWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BasePropertiesWidget.stringdata))
        return static_cast<void*>(const_cast< BasePropertiesWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BasePropertiesWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BasePropertiesWidget::SendParameters(s_MBSParameters _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
