/****************************************************************************
** Meta object code from reading C++ file 'optionswidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../optionswidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'optionswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OptionsWidget_t {
    QByteArrayData data[17];
    char stringdata[410];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionsWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionsWidget_t qt_meta_stringdata_OptionsWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "OptionsWidget"
QT_MOC_LITERAL(1, 14, 13), // "AcceptOptions"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14), // "ProgramOptions"
QT_MOC_LITERAL(4, 44, 7), // "Options"
QT_MOC_LITERAL(5, 52, 34), // "on_horizontalSlider_R_valueCh..."
QT_MOC_LITERAL(6, 87, 5), // "value"
QT_MOC_LITERAL(7, 93, 34), // "on_horizontalSlider_G_valueCh..."
QT_MOC_LITERAL(8, 128, 34), // "on_horizontalSlider_B_valueCh..."
QT_MOC_LITERAL(9, 163, 24), // "on_pushButton_OK_clicked"
QT_MOC_LITERAL(10, 188, 28), // "on_pushButton_Cancel_clicked"
QT_MOC_LITERAL(11, 217, 27), // "on_pushButton_Apply_clicked"
QT_MOC_LITERAL(12, 245, 39), // "on_horizontalSlider_R_Line_va..."
QT_MOC_LITERAL(13, 285, 39), // "on_horizontalSlider_G_Line_va..."
QT_MOC_LITERAL(14, 325, 39), // "on_horizontalSlider_B_Line_va..."
QT_MOC_LITERAL(15, 365, 24), // "updateBackgroundColorBox"
QT_MOC_LITERAL(16, 390, 19) // "updateLinesColorBox"

    },
    "OptionsWidget\0AcceptOptions\0\0"
    "ProgramOptions\0Options\0"
    "on_horizontalSlider_R_valueChanged\0"
    "value\0on_horizontalSlider_G_valueChanged\0"
    "on_horizontalSlider_B_valueChanged\0"
    "on_pushButton_OK_clicked\0"
    "on_pushButton_Cancel_clicked\0"
    "on_pushButton_Apply_clicked\0"
    "on_horizontalSlider_R_Line_valueChanged\0"
    "on_horizontalSlider_G_Line_valueChanged\0"
    "on_horizontalSlider_B_Line_valueChanged\0"
    "updateBackgroundColorBox\0updateLinesColorBox"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   77,    2, 0x08 /* Private */,
       7,    1,   80,    2, 0x08 /* Private */,
       8,    1,   83,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    1,   89,    2, 0x08 /* Private */,
      13,    1,   92,    2, 0x08 /* Private */,
      14,    1,   95,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void OptionsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OptionsWidget *_t = static_cast<OptionsWidget *>(_o);
        switch (_id) {
        case 0: _t->AcceptOptions((*reinterpret_cast< ProgramOptions(*)>(_a[1]))); break;
        case 1: _t->on_horizontalSlider_R_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_horizontalSlider_G_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_horizontalSlider_B_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_OK_clicked(); break;
        case 5: _t->on_pushButton_Cancel_clicked(); break;
        case 6: _t->on_pushButton_Apply_clicked(); break;
        case 7: _t->on_horizontalSlider_R_Line_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSlider_G_Line_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_horizontalSlider_B_Line_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateBackgroundColorBox(); break;
        case 11: _t->updateLinesColorBox(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OptionsWidget::*_t)(ProgramOptions );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OptionsWidget::AcceptOptions)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject OptionsWidget::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OptionsWidget.data,
      qt_meta_data_OptionsWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OptionsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OptionsWidget.stringdata))
        return static_cast<void*>(const_cast< OptionsWidget*>(this));
    return QDialog::qt_metacast(_clname);
}

int OptionsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void OptionsWidget::AcceptOptions(ProgramOptions _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
