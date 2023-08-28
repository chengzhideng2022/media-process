/****************************************************************************
** Meta object code from reading C++ file 'gamescreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../views/gamescreen.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamescreen.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_GameScreen_t {
    uint offsetsAndSizes[72];
    char stringdata0[11];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[2];
    char stringdata5[15];
    char stringdata6[14];
    char stringdata7[12];
    char stringdata8[16];
    char stringdata9[20];
    char stringdata10[12];
    char stringdata11[27];
    char stringdata12[18];
    char stringdata13[19];
    char stringdata14[18];
    char stringdata15[24];
    char stringdata16[20];
    char stringdata17[2];
    char stringdata18[2];
    char stringdata19[2];
    char stringdata20[17];
    char stringdata21[5];
    char stringdata22[5];
    char stringdata23[16];
    char stringdata24[16];
    char stringdata25[20];
    char stringdata26[9];
    char stringdata27[3];
    char stringdata28[16];
    char stringdata29[6];
    char stringdata30[11];
    char stringdata31[7];
    char stringdata32[9];
    char stringdata33[15];
    char stringdata34[8];
    char stringdata35[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_GameScreen_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_GameScreen_t qt_meta_stringdata_GameScreen = {
    {
        QT_MOC_LITERAL(0, 10),  // "GameScreen"
        QT_MOC_LITERAL(11, 22),  // "removeHpFromGameWidget"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 1),  // "x"
        QT_MOC_LITERAL(37, 1),  // "y"
        QT_MOC_LITERAL(39, 14),  // "tellProtAttack"
        QT_MOC_LITERAL(54, 13),  // "tellProtUseHp"
        QT_MOC_LITERAL(68, 11),  // "tellProtDie"
        QT_MOC_LITERAL(80, 15),  // "tellEnemyAttack"
        QT_MOC_LITERAL(96, 19),  // "tellGameWidgetPaint"
        QT_MOC_LITERAL(116, 11),  // "poisonLevel"
        QT_MOC_LITERAL(128, 26),  // "tellGameWidgetPosionedProt"
        QT_MOC_LITERAL(155, 17),  // "tellGameWidgetWin"
        QT_MOC_LITERAL(173, 18),  // "tellGameWidgetLose"
        QT_MOC_LITERAL(192, 17),  // "returnToChooseMap"
        QT_MOC_LITERAL(210, 23),  // "tellGameWidgetAddPlayer"
        QT_MOC_LITERAL(234, 19),  // "colorGameWidgetTile"
        QT_MOC_LITERAL(254, 1),  // "R"
        QT_MOC_LITERAL(256, 1),  // "G"
        QT_MOC_LITERAL(258, 1),  // "B"
        QT_MOC_LITERAL(260, 16),  // "switchGameWidget"
        QT_MOC_LITERAL(277, 4),  // "Type"
        QT_MOC_LITERAL(282, 4),  // "type"
        QT_MOC_LITERAL(287, 15),  // "paintPoisonTile"
        QT_MOC_LITERAL(303, 15),  // "exitCurrentGame"
        QT_MOC_LITERAL(319, 19),  // "gameWidgetAddPlayer"
        QT_MOC_LITERAL(339, 8),  // "nextStep"
        QT_MOC_LITERAL(348, 2),  // "id"
        QT_MOC_LITERAL(351, 15),  // "changeProtSpeed"
        QT_MOC_LITERAL(367, 5),  // "times"
        QT_MOC_LITERAL(373, 10),  // "toFindPath"
        QT_MOC_LITERAL(384, 6),  // "endPos"
        QT_MOC_LITERAL(391, 8),  // "autoplay"
        QT_MOC_LITERAL(400, 14),  // "processCommand"
        QT_MOC_LITERAL(415, 7),  // "command"
        QT_MOC_LITERAL(423, 15)   // "showCommandList"
    },
    "GameScreen",
    "removeHpFromGameWidget",
    "",
    "x",
    "y",
    "tellProtAttack",
    "tellProtUseHp",
    "tellProtDie",
    "tellEnemyAttack",
    "tellGameWidgetPaint",
    "poisonLevel",
    "tellGameWidgetPosionedProt",
    "tellGameWidgetWin",
    "tellGameWidgetLose",
    "returnToChooseMap",
    "tellGameWidgetAddPlayer",
    "colorGameWidgetTile",
    "R",
    "G",
    "B",
    "switchGameWidget",
    "Type",
    "type",
    "paintPoisonTile",
    "exitCurrentGame",
    "gameWidgetAddPlayer",
    "nextStep",
    "id",
    "changeProtSpeed",
    "times",
    "toFindPath",
    "endPos",
    "autoplay",
    "processCommand",
    "command",
    "showCommandList"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_GameScreen[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  146,    2, 0x06,    1 /* Public */,
       5,    2,  151,    2, 0x06,    4 /* Public */,
       6,    2,  156,    2, 0x06,    7 /* Public */,
       7,    2,  161,    2, 0x06,   10 /* Public */,
       8,    2,  166,    2, 0x06,   13 /* Public */,
       9,    3,  171,    2, 0x06,   16 /* Public */,
      11,    2,  178,    2, 0x06,   20 /* Public */,
      12,    0,  183,    2, 0x06,   23 /* Public */,
      13,    0,  184,    2, 0x06,   24 /* Public */,
      14,    0,  185,    2, 0x06,   25 /* Public */,
      15,    0,  186,    2, 0x06,   26 /* Public */,
      16,    5,  187,    2, 0x06,   27 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      20,    1,  198,    2, 0x0a,   33 /* Public */,
      23,    3,  201,    2, 0x0a,   35 /* Public */,
      24,    0,  208,    2, 0x0a,   39 /* Public */,
      25,    0,  209,    2, 0x0a,   40 /* Public */,
      26,    1,  210,    2, 0x0a,   41 /* Public */,
      28,    1,  213,    2, 0x0a,   43 /* Public */,
      30,    2,  216,    2, 0x0a,   45 /* Public */,
      32,    0,  221,    2, 0x0a,   48 /* Public */,
      33,    1,  222,    2, 0x0a,   49 /* Public */,
      35,    0,  225,    2, 0x0a,   51 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   17,   18,   19,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int, QMetaType::QPoint,   27,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GameScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GameScreen.offsetsAndSizes,
    qt_meta_data_GameScreen,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_GameScreen_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameScreen, std::true_type>,
        // method 'removeHpFromGameWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tellProtAttack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tellProtUseHp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tellProtDie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tellEnemyAttack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tellGameWidgetPaint'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tellGameWidgetPosionedProt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tellGameWidgetWin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tellGameWidgetLose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'returnToChooseMap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'tellGameWidgetAddPlayer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'colorGameWidgetTile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'switchGameWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Type, std::false_type>,
        // method 'paintPoisonTile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'exitCurrentGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'gameWidgetAddPlayer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextStep'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'changeProtSpeed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'toFindPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        // method 'autoplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processCommand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'showCommandList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GameScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->removeHpFromGameWidget((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->tellProtAttack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->tellProtUseHp((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->tellProtDie((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->tellEnemyAttack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->tellGameWidgetPaint((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 6: _t->tellGameWidgetPosionedProt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->tellGameWidgetWin(); break;
        case 8: _t->tellGameWidgetLose(); break;
        case 9: _t->returnToChooseMap(); break;
        case 10: _t->tellGameWidgetAddPlayer(); break;
        case 11: _t->colorGameWidgetTile((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5]))); break;
        case 12: _t->switchGameWidget((*reinterpret_cast< std::add_pointer_t<Type>>(_a[1]))); break;
        case 13: _t->paintPoisonTile((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 14: _t->exitCurrentGame(); break;
        case 15: _t->gameWidgetAddPlayer(); break;
        case 16: _t->nextStep((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->changeProtSpeed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->toFindPath((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[2]))); break;
        case 19: _t->autoplay(); break;
        case 20: _t->processCommand((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->showCommandList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GameScreen::*)(int , int );
            if (_t _q_method = &GameScreen::removeHpFromGameWidget; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int , int );
            if (_t _q_method = &GameScreen::tellProtAttack; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int , int );
            if (_t _q_method = &GameScreen::tellProtUseHp; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int , int );
            if (_t _q_method = &GameScreen::tellProtDie; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int , int );
            if (_t _q_method = &GameScreen::tellEnemyAttack; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int , int , int );
            if (_t _q_method = &GameScreen::tellGameWidgetPaint; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int , int );
            if (_t _q_method = &GameScreen::tellGameWidgetPosionedProt; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)();
            if (_t _q_method = &GameScreen::tellGameWidgetWin; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)();
            if (_t _q_method = &GameScreen::tellGameWidgetLose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)();
            if (_t _q_method = &GameScreen::returnToChooseMap; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)();
            if (_t _q_method = &GameScreen::tellGameWidgetAddPlayer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GameScreen::*)(int , int , int , int , int );
            if (_t _q_method = &GameScreen::colorGameWidgetTile; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
    }
}

const QMetaObject *GameScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameScreen.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GameScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void GameScreen::removeHpFromGameWidget(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameScreen::tellProtAttack(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GameScreen::tellProtUseHp(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GameScreen::tellProtDie(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GameScreen::tellEnemyAttack(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GameScreen::tellGameWidgetPaint(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GameScreen::tellGameWidgetPosionedProt(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GameScreen::tellGameWidgetWin()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void GameScreen::tellGameWidgetLose()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void GameScreen::returnToChooseMap()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void GameScreen::tellGameWidgetAddPlayer()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void GameScreen::colorGameWidgetTile(int _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
