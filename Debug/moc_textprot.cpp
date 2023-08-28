/****************************************************************************
** Meta object code from reading C++ file 'textprot.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../views/textprot.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textprot.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_TextProt_t {
    uint offsetsAndSizes[34];
    char stringdata0[9];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[2];
    char stringdata5[2];
    char stringdata6[11];
    char stringdata7[8];
    char stringdata8[18];
    char stringdata9[13];
    char stringdata10[14];
    char stringdata11[13];
    char stringdata12[4];
    char stringdata13[7];
    char stringdata14[14];
    char stringdata15[11];
    char stringdata16[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TextProt_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TextProt_t qt_meta_stringdata_TextProt = {
    {
        QT_MOC_LITERAL(0, 8),  // "TextProt"
        QT_MOC_LITERAL(9, 18),  // "tellTextViewUpdate"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 4),  // "move"
        QT_MOC_LITERAL(34, 1),  // "x"
        QT_MOC_LITERAL(36, 1),  // "y"
        QT_MOC_LITERAL(38, 10),  // "showAttack"
        QT_MOC_LITERAL(49, 7),  // "showDie"
        QT_MOC_LITERAL(57, 17),  // "showUseHealthPack"
        QT_MOC_LITERAL(75, 12),  // "showPoisoned"
        QT_MOC_LITERAL(88, 13),  // "useHealthPack"
        QT_MOC_LITERAL(102, 12),  // "stopPoisoned"
        QT_MOC_LITERAL(115, 3),  // "die"
        QT_MOC_LITERAL(119, 6),  // "attack"
        QT_MOC_LITERAL(126, 13),  // "showAnimation"
        QT_MOC_LITERAL(140, 10),  // "setProtPos"
        QT_MOC_LITERAL(151, 14)   // "setProtViewPos"
    },
    "TextProt",
    "tellTextViewUpdate",
    "",
    "move",
    "x",
    "y",
    "showAttack",
    "showDie",
    "showUseHealthPack",
    "showPoisoned",
    "useHealthPack",
    "stopPoisoned",
    "die",
    "attack",
    "showAnimation",
    "setProtPos",
    "setProtViewPos"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TextProt[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   92,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    2,   93,    2, 0x0a,    2 /* Public */,
       6,    0,   98,    2, 0x0a,    5 /* Public */,
       7,    0,   99,    2, 0x0a,    6 /* Public */,
       8,    0,  100,    2, 0x0a,    7 /* Public */,
       9,    0,  101,    2, 0x0a,    8 /* Public */,
      10,    0,  102,    2, 0x0a,    9 /* Public */,
      11,    0,  103,    2, 0x0a,   10 /* Public */,
      12,    0,  104,    2, 0x0a,   11 /* Public */,
      13,    0,  105,    2, 0x0a,   12 /* Public */,
      14,    0,  106,    2, 0x0a,   13 /* Public */,
      15,    2,  107,    2, 0x0a,   14 /* Public */,
      16,    2,  112,    2, 0x0a,   17 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject TextProt::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TextProt.offsetsAndSizes,
    qt_meta_data_TextProt,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TextProt_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TextProt, std::true_type>,
        // method 'tellTextViewUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setProtPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setProtViewPos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void TextProt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextProt *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tellTextViewUpdate(); break;
        case 1: _t->move((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->showAttack(); break;
        case 3: _t->showDie(); break;
        case 4: _t->showUseHealthPack(); break;
        case 5: _t->showPoisoned(); break;
        case 6: _t->useHealthPack(); break;
        case 7: _t->stopPoisoned(); break;
        case 8: _t->die(); break;
        case 9: _t->attack(); break;
        case 10: _t->showAnimation(); break;
        case 11: _t->setProtPos((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 12: _t->setProtViewPos((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TextProt::*)();
            if (_t _q_method = &TextProt::tellTextViewUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *TextProt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextProt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextProt.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TextProt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void TextProt::tellTextViewUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
