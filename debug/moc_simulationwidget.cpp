/****************************************************************************
** Meta object code from reading C++ file 'simulationwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../simulationwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulationwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_simulationwidget_t {
    QByteArrayData data[39];
    char stringdata[968];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_simulationwidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_simulationwidget_t qt_meta_stringdata_simulationwidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "simulationwidget"
QT_MOC_LITERAL(1, 17, 22), // "SendParametersToKernel"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 15), // "s_MBSParameters"
QT_MOC_LITERAL(4, 57, 10), // "Parameters"
QT_MOC_LITERAL(5, 68, 15), // "StartSimulation"
QT_MOC_LITERAL(6, 84, 2), // "t0"
QT_MOC_LITERAL(7, 87, 2), // "tk"
QT_MOC_LITERAL(8, 90, 2), // "dt"
QT_MOC_LITERAL(9, 93, 23), // "StartRealTimeSimulation"
QT_MOC_LITERAL(10, 117, 5), // "Speed"
QT_MOC_LITERAL(11, 123, 4), // "Step"
QT_MOC_LITERAL(12, 128, 22), // "StopRealTimeSimulation"
QT_MOC_LITERAL(13, 151, 20), // "UpdatePostSimulation"
QT_MOC_LITERAL(14, 172, 16), // "UpdateControlers"
QT_MOC_LITERAL(15, 189, 22), // "s_ControlersParameters"
QT_MOC_LITERAL(16, 212, 26), // "UpdateParametersFromKernel"
QT_MOC_LITERAL(17, 239, 13), // "MBSParameters"
QT_MOC_LITERAL(18, 253, 25), // "UpdateVariablesFromKernel"
QT_MOC_LITERAL(19, 279, 14), // "s_MBSVariables"
QT_MOC_LITERAL(20, 294, 9), // "Variables"
QT_MOC_LITERAL(21, 304, 36), // "on_pushButton_showSimulation_..."
QT_MOC_LITERAL(22, 341, 37), // "on_pushButton_StartSimulation..."
QT_MOC_LITERAL(23, 379, 45), // "on_pushButton_StartRealTimeSi..."
QT_MOC_LITERAL(24, 425, 44), // "on_pushButton_showRealTimeSim..."
QT_MOC_LITERAL(25, 470, 44), // "on_pushButton_StopRealTimeSim..."
QT_MOC_LITERAL(26, 515, 51), // "on_horizontalSlider_PostSimul..."
QT_MOC_LITERAL(27, 567, 5), // "value"
QT_MOC_LITERAL(28, 573, 40), // "on_pushButton_showPostSimulat..."
QT_MOC_LITERAL(29, 614, 46), // "on_pushButton_showTrajectoryS..."
QT_MOC_LITERAL(30, 661, 59), // "on_pushButton_StartTrajectory..."
QT_MOC_LITERAL(31, 721, 41), // "on_pushButton_showPositionCon..."
QT_MOC_LITERAL(32, 763, 41), // "on_pushButton_OpenControlerWi..."
QT_MOC_LITERAL(33, 805, 19), // "on_checkBox_clicked"
QT_MOC_LITERAL(34, 825, 39), // "on_pushButton_showHapticContr..."
QT_MOC_LITERAL(35, 865, 43), // "on_pushButton_OpenControlerWi..."
QT_MOC_LITERAL(36, 909, 20), // "GetUpdatedControlers"
QT_MOC_LITERAL(37, 930, 10), // "Controlers"
QT_MOC_LITERAL(38, 941, 26) // "UpdateControlersFromKernel"

    },
    "simulationwidget\0SendParametersToKernel\0"
    "\0s_MBSParameters\0Parameters\0StartSimulation\0"
    "t0\0tk\0dt\0StartRealTimeSimulation\0Speed\0"
    "Step\0StopRealTimeSimulation\0"
    "UpdatePostSimulation\0UpdateControlers\0"
    "s_ControlersParameters\0"
    "UpdateParametersFromKernel\0MBSParameters\0"
    "UpdateVariablesFromKernel\0s_MBSVariables\0"
    "Variables\0on_pushButton_showSimulation_clicked\0"
    "on_pushButton_StartSimulation_clicked\0"
    "on_pushButton_StartRealTimeSimulation_clicked\0"
    "on_pushButton_showRealTimeSimulation_clicked\0"
    "on_pushButton_StopRealTimeSimulation_clicked\0"
    "on_horizontalSlider_PostSimulationTime_valueChanged\0"
    "value\0on_pushButton_showPostSimulation_clicked\0"
    "on_pushButton_showTrajectorySimulation_clicked\0"
    "on_pushButton_StartTrajectorySimulationSimulation_3_clicked\0"
    "on_pushButton_showPositionControl_clicked\0"
    "on_pushButton_OpenControlerWindow_clicked\0"
    "on_checkBox_clicked\0"
    "on_pushButton_showHapticControl_clicked\0"
    "on_pushButton_OpenControlerWindow_2_clicked\0"
    "GetUpdatedControlers\0Controlers\0"
    "UpdateControlersFromKernel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_simulationwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       5,    3,  137,    2, 0x06 /* Public */,
       9,    2,  144,    2, 0x06 /* Public */,
      12,    0,  149,    2, 0x06 /* Public */,
      13,    1,  150,    2, 0x06 /* Public */,
      14,    1,  153,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,  156,    2, 0x08 /* Private */,
      18,    1,  159,    2, 0x08 /* Private */,
      21,    0,  162,    2, 0x08 /* Private */,
      22,    0,  163,    2, 0x08 /* Private */,
      23,    0,  164,    2, 0x08 /* Private */,
      24,    0,  165,    2, 0x08 /* Private */,
      25,    0,  166,    2, 0x08 /* Private */,
      26,    1,  167,    2, 0x08 /* Private */,
      28,    0,  170,    2, 0x08 /* Private */,
      29,    0,  171,    2, 0x08 /* Private */,
      30,    0,  172,    2, 0x08 /* Private */,
      31,    0,  173,    2, 0x08 /* Private */,
      32,    0,  174,    2, 0x08 /* Private */,
      33,    0,  175,    2, 0x08 /* Private */,
      34,    0,  176,    2, 0x08 /* Private */,
      35,    0,  177,    2, 0x08 /* Private */,
      36,    1,  178,    2, 0x08 /* Private */,
      38,    1,  181,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    6,    7,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, 0x80000000 | 15,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   37,
    QMetaType::Void, 0x80000000 | 15,   37,

       0        // eod
};

void simulationwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        simulationwidget *_t = static_cast<simulationwidget *>(_o);
        switch (_id) {
        case 0: _t->SendParametersToKernel((*reinterpret_cast< s_MBSParameters(*)>(_a[1]))); break;
        case 1: _t->StartSimulation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->StartRealTimeSimulation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->StopRealTimeSimulation(); break;
        case 4: _t->UpdatePostSimulation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->UpdateControlers((*reinterpret_cast< s_ControlersParameters(*)>(_a[1]))); break;
        case 6: _t->UpdateParametersFromKernel((*reinterpret_cast< s_MBSParameters(*)>(_a[1]))); break;
        case 7: _t->UpdateVariablesFromKernel((*reinterpret_cast< s_MBSVariables(*)>(_a[1]))); break;
        case 8: _t->on_pushButton_showSimulation_clicked(); break;
        case 9: _t->on_pushButton_StartSimulation_clicked(); break;
        case 10: _t->on_pushButton_StartRealTimeSimulation_clicked(); break;
        case 11: _t->on_pushButton_showRealTimeSimulation_clicked(); break;
        case 12: _t->on_pushButton_StopRealTimeSimulation_clicked(); break;
        case 13: _t->on_horizontalSlider_PostSimulationTime_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_showPostSimulation_clicked(); break;
        case 15: _t->on_pushButton_showTrajectorySimulation_clicked(); break;
        case 16: _t->on_pushButton_StartTrajectorySimulationSimulation_3_clicked(); break;
        case 17: _t->on_pushButton_showPositionControl_clicked(); break;
        case 18: _t->on_pushButton_OpenControlerWindow_clicked(); break;
        case 19: _t->on_checkBox_clicked(); break;
        case 20: _t->on_pushButton_showHapticControl_clicked(); break;
        case 21: _t->on_pushButton_OpenControlerWindow_2_clicked(); break;
        case 22: _t->GetUpdatedControlers((*reinterpret_cast< s_ControlersParameters(*)>(_a[1]))); break;
        case 23: _t->UpdateControlersFromKernel((*reinterpret_cast< s_ControlersParameters(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (simulationwidget::*_t)(s_MBSParameters );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&simulationwidget::SendParametersToKernel)) {
                *result = 0;
            }
        }
        {
            typedef void (simulationwidget::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&simulationwidget::StartSimulation)) {
                *result = 1;
            }
        }
        {
            typedef void (simulationwidget::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&simulationwidget::StartRealTimeSimulation)) {
                *result = 2;
            }
        }
        {
            typedef void (simulationwidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&simulationwidget::StopRealTimeSimulation)) {
                *result = 3;
            }
        }
        {
            typedef void (simulationwidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&simulationwidget::UpdatePostSimulation)) {
                *result = 4;
            }
        }
        {
            typedef void (simulationwidget::*_t)(s_ControlersParameters );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&simulationwidget::UpdateControlers)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject simulationwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_simulationwidget.data,
      qt_meta_data_simulationwidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *simulationwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *simulationwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_simulationwidget.stringdata))
        return static_cast<void*>(const_cast< simulationwidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int simulationwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void simulationwidget::SendParametersToKernel(s_MBSParameters _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void simulationwidget::StartSimulation(double _t1, double _t2, double _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void simulationwidget::StartRealTimeSimulation(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void simulationwidget::StopRealTimeSimulation()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void simulationwidget::UpdatePostSimulation(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void simulationwidget::UpdateControlers(s_ControlersParameters _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
