/****************************************************************************
** Meta object code from reading C++ file 'graphicsprot.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../views/graphicsprot.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicsprot.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_GraphicsProt_t {
    uint offsetsAndSizes[26];
    char stringdata0[13];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[11];
    char stringdata5[8];
    char stringdata6[18];
    char stringdata7[13];
    char stringdata8[14];
    char stringdata9[13];
    char stringdata10[4];
    char stringdata11[7];
    char stringdata12[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_GraphicsProt_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_GraphicsProt_t qt_meta_stringdata_GraphicsProt = {
    {
        QT_MOC_LITERAL(0, 12),  // "GraphicsProt"
        QT_MOC_LITERAL(13, 8),  // "gameOver"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 7),  // "gameWin"
        QT_MOC_LITERAL(31, 10),  // "showAttack"
        QT_MOC_LITERAL(42, 7),  // "showDie"
        QT_MOC_LITERAL(50, 17),  // "showUseHealthPack"
        QT_MOC_LITERAL(68, 12),  // "showPoisoned"
        QT_MOC_LITERAL(81, 13),  // "useHealthPack"
        QT_MOC_LITERAL(95, 12),  // "stopPoisoned"
        QT_MOC_LITERAL(108, 3),  // "die"
        QT_MOC_LITERAL(112, 6),  // "attack"
        QT_MOC_LITERAL(119, 13)   // "showAnimation"
    },
    "GraphicsProt",
    "gameOver",
    "",
    "gameWin",
    "showAttack",
    "showDie",
    "showUseHealthPack",
    "showPoisoned",
    "useHealthPack",
    "stopPoisoned",
    "die",
    "attack",
    "showAnimation"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_GraphicsProt[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   82,    2, 0x0a,    3 /* Public */,
       5,    0,   83,    2, 0x0a,    4 /* Public */,
       6,    0,   84,    2, 0x0a,    5 /* Public */,
       7,    0,   85,    2, 0x0a,    6 /* Public */,
       8,    0,   86,    2, 0x0a,    7 /* Public */,
       9,    0,   87,    2, 0x0a,    8 /* Public */,
      10,    0,   88,    2, 0x0a,    9 /* Public */,
      11,    0,   89,    2, 0x0a,   10 /* Public */,
      12,    0,   90,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GraphicsProt::staticMetaObject = { {
    QMetaObject::SuperData::link<GraphicActor::staticMetaObject>(),
    qt_meta_stringdata_GraphicsProt.offsetsAndSizes,
    qt_meta_data_GraphicsProt,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_GraphicsProt_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GraphicsProt, std::true_type>,
        // method 'gameOver'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAttack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showDie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showUseHealthPack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showPoisoned'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'useHealthPack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopPoisoned'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'die'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'attack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GraphicsProt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphicsProt *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->gameOver(); break;
        case 1: _t->gameWin(); break;
        case 2: _t->showAttack(); break;
        case 3: _t->showDie(); break;
        case 4: _t->showUseHealthPack(); break;
        case 5: _t->showPoisoned(); break;
        case 6: _t->useHealthPack(); break;
        case 7: _t->stopPoisoned(); break;
        case 8: _t->die(); break;
        case 9: _t->attack(); break;
        case 10: _t->showAnimation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphicsProt::*)();
            if (_t _q_method = &GraphicsProt::gameOver; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphicsProt::*)();
            if (_t _q_method = &GraphicsProt::gameWin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *GraphicsProt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsProt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsProt.stringdata0))
        return static_cast<void*>(this);
    return GraphicActor::qt_metacast(_clname);
}

int GraphicsProt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicActor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void GraphicsProt::gameOver()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GraphicsProt::gameWin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
