/****************************************************************************
** Meta object code from reading C++ file 'linkspropertieswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../linkspropertieswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linkspropertieswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LinksPropertiesWidget_t {
    QByteArrayData data[12];
    char stringdata[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LinksPropertiesWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LinksPropertiesWidget_t qt_meta_stringdata_LinksPropertiesWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "LinksPropertiesWidget"
QT_MOC_LITERAL(1, 22, 14), // "SendParameters"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 15), // "s_MBSParameters"
QT_MOC_LITERAL(4, 54, 10), // "Parameters"
QT_MOC_LITERAL(5, 65, 24), // "on_pushButton_OK_clicked"
QT_MOC_LITERAL(6, 90, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(7, 119, 27), // "on_pushButton_Apply_clicked"
QT_MOC_LITERAL(8, 147, 37), // "on_comboBox_Links_currentInde..."
QT_MOC_LITERAL(9, 185, 5), // "index"
QT_MOC_LITERAL(10, 191, 34), // "on_radioButton_LoadedModel_cl..."
QT_MOC_LITERAL(11, 226, 30) // "on_radioButton_Default_clicked"

    },
    "LinksPropertiesWidget\0SendParameters\0"
    "\0s_MBSParameters\0Parameters\0"
    "on_pushButton_OK_clicked\0"
    "on_pushButton_Cancel_clicked\0"
    "on_pushButton_Apply_clicked\0"
    "on_comboBox_Links_currentIndexChanged\0"
    "index\0on_radioButton_LoadedModel_clicked\0"
    "on_radioButton_Default_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LinksPropertiesWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,
      10,    0,   58,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LinksPropertiesWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LinksPropertiesWidget *_t = static_cast<LinksPropertiesWidget *>(_o);
        switch (_id) {
        case 0: _t->SendParameters((*reinterpret_cast< s_MBSParameters(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_OK_clicked(); break;
        case 2: _t->on_pushButton_Cancel_clicked(); break;
        case 3: _t->on_pushButton_Apply_clicked(); break;
        case 4: _t->on_comboBox_Links_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_radioButton_LoadedModel_clicked(); break;
        case 6: _t->on_radioButton_Default_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LinksPropertiesWidget::*_t)(s_MBSParameters );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LinksPropertiesWidget::SendParameters)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LinksPropertiesWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LinksPropertiesWidget.data,
      qt_meta_data_LinksPropertiesWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LinksPropertiesWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinksPropertiesWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LinksPropertiesWidget.stringdata))
        return static_cast<void*>(const_cast< LinksPropertiesWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LinksPropertiesWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void LinksPropertiesWidget::SendParameters(s_MBSParameters _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
