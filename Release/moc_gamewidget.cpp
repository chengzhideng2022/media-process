/****************************************************************************
** Meta object code from reading C++ file 'gamewidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../views/gamewidget.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_GameWidget_t {
    uint offsetsAndSizes[52];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[3];
    char stringdata4[4];
    char stringdata5[7];
    char stringdata6[8];
    char stringdata7[13];
    char stringdata8[2];
    char stringdata9[2];
    char stringdata10[15];
    char stringdata11[16];
    char stringdata12[12];
    char stringdata13[14];
    char stringdata14[18];
    char stringdata15[12];
    char stringdata16[18];
    char stringdata17[12];
    char stringdata18[13];
    char stringdata19[15];
    char stringdata20[6];
    char stringdata21[10];
    char stringdata22[10];
    char stringdata23[2];
    char stringdata24[2];
    char stringdata25[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_GameWidget_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_GameWidget_t qt_meta_stringdata_GameWidget = {
    {
        QT_MOC_LITERAL(0, 10),  // "GameWidget"
        QT_MOC_LITERAL(11, 14),  // "tellPathEndPos"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 2),  // "id"
        QT_MOC_LITERAL(30, 3),  // "pos"
        QT_MOC_LITERAL(34, 6),  // "zoomIn"
        QT_MOC_LITERAL(41, 7),  // "zoomOut"
        QT_MOC_LITERAL(49, 12),  // "removeHpView"
        QT_MOC_LITERAL(62, 1),  // "x"
        QT_MOC_LITERAL(64, 1),  // "y"
        QT_MOC_LITERAL(66, 14),  // "showProtAttack"
        QT_MOC_LITERAL(81, 15),  // "showEnemyAttack"
        QT_MOC_LITERAL(97, 11),  // "showProtDie"
        QT_MOC_LITERAL(109, 13),  // "showProtUseHp"
        QT_MOC_LITERAL(123, 17),  // "paintPoisonedTile"
        QT_MOC_LITERAL(141, 11),  // "poisonLevel"
        QT_MOC_LITERAL(153, 17),  // "repaintGameWidget"
        QT_MOC_LITERAL(171, 11),  // "showGameWin"
        QT_MOC_LITERAL(183, 12),  // "showGameLose"
        QT_MOC_LITERAL(196, 14),  // "changeAniSpeed"
        QT_MOC_LITERAL(211, 5),  // "times"
        QT_MOC_LITERAL(217, 9),  // "addPlayer"
        QT_MOC_LITERAL(227, 9),  // "colorTile"
        QT_MOC_LITERAL(237, 1),  // "R"
        QT_MOC_LITERAL(239, 1),  // "G"
        QT_MOC_LITERAL(241, 1)   // "B"
    },
    "GameWidget",
    "tellPathEndPos",
    "",
    "id",
    "pos",
    "zoomIn",
    "zoomOut",
    "removeHpView",
    "x",
    "y",
    "showProtAttack",
    "showEnemyAttack",
    "showProtDie",
    "showProtUseHp",
    "paintPoisonedTile",
    "poisonLevel",
    "repaintGameWidget",
    "showGameWin",
    "showGameLose",
    "changeAniSpeed",
    "times",
    "addPlayer",
    "colorTile",
    "R",
    "G",
    "B"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_GameWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  104,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,  109,    2, 0x0a,    4 /* Public */,
       6,    0,  110,    2, 0x0a,    5 /* Public */,
       7,    2,  111,    2, 0x0a,    6 /* Public */,
      10,    2,  116,    2, 0x0a,    9 /* Public */,
      11,    2,  121,    2, 0x0a,   12 /* Public */,
      12,    2,  126,    2, 0x0a,   15 /* Public */,
      13,    2,  131,    2, 0x0a,   18 /* Public */,
      14,    3,  136,    2, 0x0a,   21 /* Public */,
      16,    0,  143,    2, 0x0a,   25 /* Public */,
      17,    0,  144,    2, 0x0a,   26 /* Public */,
      18,    0,  145,    2, 0x0a,   27 /* Public */,
      19,    1,  146,    2, 0x0a,   28 /* Public */,
      21,    0,  149,    2, 0x0a,   30 /* Public */,
      22,    5,  150,    2, 0x0a,   31 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   23,   24,   25,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GameWidget.offsetsAndSizes,
    qt_meta_data_GameWidget,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_GameWidget_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameWidget, std::true_type>,
        // method 'tellPathEndPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'zoomIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zoomOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeHpView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showProtAttack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showEnemyAttack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showProtDie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showProtUseHp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'paintPoisonedTile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'repaintGameWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showGameWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showGameLose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'changeAniSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addPlayer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'colorTile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void GameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tellPathEndPos((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2]))); break;
        case 1: _t->zoomIn(); break;
        case 2: _t->zoomOut(); break;
        case 3: _t->removeHpView((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->showProtAttack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->showEnemyAttack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->showProtDie((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->showProtUseHp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 8: _t->paintPoisonedTile((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 9: _t->repaintGameWidget(); break;
        case 10: _t->showGameWin(); break;
        case 11: _t->showGameLose(); break;
        case 12: _t->changeAniSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->addPlayer(); break;
        case 14: _t->colorTile((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameWidget::*)(int , QPoint );
            if (_t _q_method = &GameWidget::tellPathEndPos; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *GameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void GameWidget::tellPathEndPos(int _t1, QPoint _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
