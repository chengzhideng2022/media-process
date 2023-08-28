/****************************************************************************
** Meta object code from reading C++ file 'dashboard.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../views/dashboard.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dashboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_DashBoard_t {
    uint offsetsAndSizes[34];
    char stringdata0[10];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[22];
    char stringdata5[21];
    char stringdata6[6];
    char stringdata7[15];
    char stringdata8[9];
    char stringdata9[11];
    char stringdata10[12];
    char stringdata11[23];
    char stringdata12[9];
    char stringdata13[17];
    char stringdata14[13];
    char stringdata15[14];
    char stringdata16[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_DashBoard_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_DashBoard_t qt_meta_stringdata_DashBoard = {
    {
        QT_MOC_LITERAL(0, 9),  // "DashBoard"
        QT_MOC_LITERAL(10, 16),  // "zoomInGameWidget"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 17),  // "zoomOutGameWidget"
        QT_MOC_LITERAL(46, 21),  // "addPlayerToGameWidget"
        QT_MOC_LITERAL(68, 20),  // "changeAnimationSpeed"
        QT_MOC_LITERAL(89, 5),  // "times"
        QT_MOC_LITERAL(95, 14),  // "openPathFinder"
        QT_MOC_LITERAL(110, 8),  // "exitGame"
        QT_MOC_LITERAL(119, 10),  // "autoPlayOn"
        QT_MOC_LITERAL(130, 11),  // "autoPlayOff"
        QT_MOC_LITERAL(142, 22),  // "changeHeuristicsWeight"
        QT_MOC_LITERAL(165, 8),  // "newValue"
        QT_MOC_LITERAL(174, 16),  // "showGraphicsView"
        QT_MOC_LITERAL(191, 12),  // "showTextView"
        QT_MOC_LITERAL(204, 13),  // "upLoadCommand"
        QT_MOC_LITERAL(218, 7)   // "command"
    },
    "DashBoard",
    "zoomInGameWidget",
    "",
    "zoomOutGameWidget",
    "addPlayerToGameWidget",
    "changeAnimationSpeed",
    "times",
    "openPathFinder",
    "exitGame",
    "autoPlayOn",
    "autoPlayOff",
    "changeHeuristicsWeight",
    "newValue",
    "showGraphicsView",
    "showTextView",
    "upLoadCommand",
    "command"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_DashBoard[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    0,   87,    2, 0x06,    2 /* Public */,
       4,    0,   88,    2, 0x06,    3 /* Public */,
       5,    1,   89,    2, 0x06,    4 /* Public */,
       7,    0,   92,    2, 0x06,    6 /* Public */,
       8,    0,   93,    2, 0x06,    7 /* Public */,
       9,    0,   94,    2, 0x06,    8 /* Public */,
      10,    0,   95,    2, 0x06,    9 /* Public */,
      11,    1,   96,    2, 0x06,   10 /* Public */,
      13,    0,   99,    2, 0x06,   12 /* Public */,
      14,    0,  100,    2, 0x06,   13 /* Public */,
      15,    1,  101,    2, 0x06,   14 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject DashBoard::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_DashBoard.offsetsAndSizes,
    qt_meta_data_DashBoard,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_DashBoard_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DashBoard, std::true_type>,
        // method 'zoomInGameWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zoomOutGameWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addPlayerToGameWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeAnimationSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'openPathFinder'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exitGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'autoPlayOn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'autoPlayOff'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeHeuristicsWeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'showGraphicsView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showTextView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'upLoadCommand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void DashBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DashBoard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->zoomInGameWidget(); break;
        case 1: _t->zoomOutGameWidget(); break;
        case 2: _t->addPlayerToGameWidget(); break;
        case 3: _t->changeAnimationSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->openPathFinder(); break;
        case 5: _t->exitGame(); break;
        case 6: _t->autoPlayOn(); break;
        case 7: _t->autoPlayOff(); break;
        case 8: _t->changeHeuristicsWeight((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 9: _t->showGraphicsView(); break;
        case 10: _t->showTextView(); break;
        case 11: _t->upLoadCommand((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::zoomInGameWidget; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::zoomOutGameWidget; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::addPlayerToGameWidget; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)(int );
            if (_t _q_method = &DashBoard::changeAnimationSpeed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::openPathFinder; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::exitGame; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::autoPlayOn; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::autoPlayOff; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)(float );
            if (_t _q_method = &DashBoard::changeHeuristicsWeight; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::showGraphicsView; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)();
            if (_t _q_method = &DashBoard::showTextView; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (DashBoard::*)(QString );
            if (_t _q_method = &DashBoard::upLoadCommand; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
    }
}

const QMetaObject *DashBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DashBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DashBoard.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DashBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void DashBoard::zoomInGameWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DashBoard::zoomOutGameWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DashBoard::addPlayerToGameWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DashBoard::changeAnimationSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DashBoard::openPathFinder()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DashBoard::exitGame()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DashBoard::autoPlayOn()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void DashBoard::autoPlayOff()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void DashBoard::changeHeuristicsWeight(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DashBoard::showGraphicsView()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void DashBoard::showTextView()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void DashBoard::upLoadCommand(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
