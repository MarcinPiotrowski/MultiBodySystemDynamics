/****************************************************************************
** Meta object code from reading C++ file 'KMain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Kernel/KMain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KMain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KMain_t {
    QByteArrayData data[33];
    char stringdata[456];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KMain_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KMain_t qt_meta_stringdata_KMain = {
    {
QT_MOC_LITERAL(0, 0, 5), // "KMain"
QT_MOC_LITERAL(1, 6, 13), // "SendVariables"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "s_MBSVariables"
QT_MOC_LITERAL(4, 36, 12), // "MBSVariables"
QT_MOC_LITERAL(5, 49, 4), // "Time"
QT_MOC_LITERAL(6, 54, 14), // "SendParameters"
QT_MOC_LITERAL(7, 69, 15), // "s_MBSParameters"
QT_MOC_LITERAL(8, 85, 13), // "MBSParameters"
QT_MOC_LITERAL(9, 99, 18), // "SendMeasureCommand"
QT_MOC_LITERAL(10, 118, 7), // "Command"
QT_MOC_LITERAL(11, 126, 14), // "SendControlers"
QT_MOC_LITERAL(12, 141, 22), // "s_ControlersParameters"
QT_MOC_LITERAL(13, 164, 10), // "Parameters"
QT_MOC_LITERAL(14, 175, 13), // "GetParameters"
QT_MOC_LITERAL(15, 189, 23), // "PerformSingleSimulation"
QT_MOC_LITERAL(16, 213, 2), // "t0"
QT_MOC_LITERAL(17, 216, 2), // "tk"
QT_MOC_LITERAL(18, 219, 2), // "dt"
QT_MOC_LITERAL(19, 222, 23), // "StartRealTimeSimulation"
QT_MOC_LITERAL(20, 246, 5), // "Speed"
QT_MOC_LITERAL(21, 252, 4), // "Step"
QT_MOC_LITERAL(22, 257, 20), // "UpdatePostSimulation"
QT_MOC_LITERAL(23, 278, 22), // "StopRealTimeSimulation"
QT_MOC_LITERAL(24, 301, 21), // "UpdateMultibodySystem"
QT_MOC_LITERAL(25, 323, 20), // "SetupObjectsToRender"
QT_MOC_LITERAL(26, 344, 13), // "UpdateOptions"
QT_MOC_LITERAL(27, 358, 14), // "ProgramOptions"
QT_MOC_LITERAL(28, 373, 7), // "Options"
QT_MOC_LITERAL(29, 381, 25), // "RealTimeSimulationRoutine"
QT_MOC_LITERAL(30, 407, 9), // "EventLoop"
QT_MOC_LITERAL(31, 417, 15), // "UpdateControler"
QT_MOC_LITERAL(32, 433, 22) // "RefreshMultibodyObject"

    },
    "KMain\0SendVariables\0\0s_MBSVariables\0"
    "MBSVariables\0Time\0SendParameters\0"
    "s_MBSParameters\0MBSParameters\0"
    "SendMeasureCommand\0Command\0SendControlers\0"
    "s_ControlersParameters\0Parameters\0"
    "GetParameters\0PerformSingleSimulation\0"
    "t0\0tk\0dt\0StartRealTimeSimulation\0Speed\0"
    "Step\0UpdatePostSimulation\0"
    "StopRealTimeSimulation\0UpdateMultibodySystem\0"
    "SetupObjectsToRender\0UpdateOptions\0"
    "ProgramOptions\0Options\0RealTimeSimulationRoutine\0"
    "EventLoop\0UpdateControler\0"
    "RefreshMultibodyObject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KMain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   94,    2, 0x06 /* Public */,
       6,    1,   99,    2, 0x06 /* Public */,
       9,    1,  102,    2, 0x06 /* Public */,
      11,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  108,    2, 0x0a /* Public */,
      15,    3,  111,    2, 0x0a /* Public */,
      19,    2,  118,    2, 0x0a /* Public */,
      22,    1,  123,    2, 0x0a /* Public */,
      23,    0,  126,    2, 0x0a /* Public */,
      24,    0,  127,    2, 0x0a /* Public */,
      25,    0,  128,    2, 0x0a /* Public */,
      26,    1,  129,    2, 0x0a /* Public */,
      29,    0,  132,    2, 0x0a /* Public */,
      30,    0,  133,    2, 0x0a /* Public */,
      31,    1,  134,    2, 0x0a /* Public */,
      32,    0,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,   13,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   16,   17,   18,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   20,   21,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void KMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KMain *_t = static_cast<KMain *>(_o);
        switch (_id) {
        case 0: _t->SendVariables((*reinterpret_cast< s_MBSVariables(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->SendParameters((*reinterpret_cast< s_MBSParameters(*)>(_a[1]))); break;
        case 2: _t->SendMeasureCommand((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->SendControlers((*reinterpret_cast< s_ControlersParameters(*)>(_a[1]))); break;
        case 4: _t->GetParameters((*reinterpret_cast< s_MBSParameters(*)>(_a[1]))); break;
        case 5: _t->PerformSingleSimulation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 6: _t->StartRealTimeSimulation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->UpdatePostSimulation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->StopRealTimeSimulation(); break;
        case 9: _t->UpdateMultibodySystem(); break;
        case 10: _t->SetupObjectsToRender(); break;
        case 11: _t->UpdateOptions((*reinterpret_cast< ProgramOptions(*)>(_a[1]))); break;
        case 12: _t->RealTimeSimulationRoutine(); break;
        case 13: _t->EventLoop(); break;
        case 14: _t->UpdateControler((*reinterpret_cast< s_ControlersParameters(*)>(_a[1]))); break;
        case 15: _t->RefreshMultibodyObject(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KMain::*_t)(s_MBSVariables , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMain::SendVariables)) {
                *result = 0;
            }
        }
        {
            typedef void (KMain::*_t)(s_MBSParameters );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMain::SendParameters)) {
                *result = 1;
            }
        }
        {
            typedef void (KMain::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMain::SendMeasureCommand)) {
                *result = 2;
            }
        }
        {
            typedef void (KMain::*_t)(s_ControlersParameters );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMain::SendControlers)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject KMain::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KMain.data,
      qt_meta_data_KMain,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KMain::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KMain.stringdata))
        return static_cast<void*>(const_cast< KMain*>(this));
    return QObject::qt_metacast(_clname);
}

int KMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void KMain::SendVariables(s_MBSVariables _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KMain::SendParameters(s_MBSParameters _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KMain::SendMeasureCommand(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KMain::SendControlers(s_ControlersParameters _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
