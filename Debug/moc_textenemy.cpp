/****************************************************************************
** Meta object code from reading C++ file 'textenemy.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../views/textenemy.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textenemy.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_TextEnemy_t {
    uint offsetsAndSizes[22];
    char stringdata0[10];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[14];
    char stringdata5[8];
    char stringdata6[8];
    char stringdata7[2];
    char stringdata8[8];
    char stringdata9[2];
    char stringdata10[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TextEnemy_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TextEnemy_t qt_meta_stringdata_TextEnemy = {
    {
        QT_MOC_LITERAL(0, 9),  // "TextEnemy"
        QT_MOC_LITERAL(10, 18),  // "tellTextViewUpdate"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 3),  // "die"
        QT_MOC_LITERAL(34, 13),  // "showAnimation"
        QT_MOC_LITERAL(48, 7),  // "showDie"
        QT_MOC_LITERAL(56, 7),  // "setPosX"
        QT_MOC_LITERAL(64, 1),  // "x"
        QT_MOC_LITERAL(66, 7),  // "setPosY"
        QT_MOC_LITERAL(74, 1),  // "y"
        QT_MOC_LITERAL(76, 6)   // "setPos"
    },
    "TextEnemy",
    "tellTextViewUpdate",
    "",
    "die",
    "showAnimation",
    "showDie",
    "setPosX",
    "x",
    "setPosY",
    "y",
    "setPos"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TextEnemy[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   57,    2, 0x0a,    2 /* Public */,
       4,    0,   58,    2, 0x0a,    3 /* Public */,
       5,    0,   59,    2, 0x0a,    4 /* Public */,
       6,    1,   60,    2, 0x0a,    5 /* Public */,
       8,    1,   63,    2, 0x0a,    7 /* Public */,
      10,    2,   66,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject TextEnemy::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TextEnemy.offsetsAndSizes,
    qt_meta_data_TextEnemy,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TextEnemy_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TextEnemy, std::true_type>,
        // method 'tellTextViewUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'die'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAnimation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showDie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setPosX'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setPosY'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void TextEnemy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextEnemy *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tellTextViewUpdate(); break;
        case 1: _t->die(); break;
        case 2: _t->showAnimation(); break;
        case 3: _t->showDie(); break;
        case 4: _t->setPosX((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->setPosY((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setPos((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TextEnemy::*)();
            if (_t _q_method = &TextEnemy::tellTextViewUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *TextEnemy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEnemy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextEnemy.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TextEnemy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TextEnemy::tellTextViewUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
