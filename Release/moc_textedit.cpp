/****************************************************************************
** Meta object code from reading C++ file 'textedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../utils/textedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TextEdit_t {
    QByteArrayData data[23];
    char stringdata[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TextEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TextEdit_t qt_meta_stringdata_TextEdit = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 8),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 13),
QT_MOC_LITERAL(4, 33, 10),
QT_MOC_LITERAL(5, 44, 10),
QT_MOC_LITERAL(6, 55, 1),
QT_MOC_LITERAL(7, 57, 8),
QT_MOC_LITERAL(8, 66, 1),
QT_MOC_LITERAL(9, 68, 9),
QT_MOC_LITERAL(10, 78, 10),
QT_MOC_LITERAL(11, 89, 9),
QT_MOC_LITERAL(12, 99, 9),
QT_MOC_LITERAL(13, 109, 9),
QT_MOC_LITERAL(14, 119, 8),
QT_MOC_LITERAL(15, 128, 1),
QT_MOC_LITERAL(16, 130, 4),
QT_MOC_LITERAL(17, 135, 24),
QT_MOC_LITERAL(18, 160, 15),
QT_MOC_LITERAL(19, 176, 6),
QT_MOC_LITERAL(20, 183, 21),
QT_MOC_LITERAL(21, 205, 20),
QT_MOC_LITERAL(22, 226, 5)
    },
    "TextEdit\0textBold\0\0textUnderline\0"
    "textItalic\0textFamily\0f\0textSize\0p\0"
    "textStyle\0styleIndex\0textColor\0backColor\0"
    "textAlign\0QAction*\0a\0save\0"
    "currentCharFormatChanged\0QTextCharFormat\0"
    "format\0cursorPositionChanged\0"
    "clipboardDataChanged\0about\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08,
       3,    0,   85,    2, 0x08,
       4,    0,   86,    2, 0x08,
       5,    1,   87,    2, 0x08,
       7,    1,   90,    2, 0x08,
       9,    1,   93,    2, 0x08,
      11,    0,   96,    2, 0x08,
      12,    0,   97,    2, 0x08,
      13,    1,   98,    2, 0x08,
      16,    0,  101,    2, 0x08,
      17,    1,  102,    2, 0x08,
      20,    0,  105,    2, 0x08,
      21,    0,  106,    2, 0x08,
      22,    0,  107,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextEdit *_t = static_cast<TextEdit *>(_o);
        switch (_id) {
        case 0: _t->textBold(); break;
        case 1: _t->textUnderline(); break;
        case 2: _t->textItalic(); break;
        case 3: _t->textFamily((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->textSize((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->textStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->textColor(); break;
        case 7: _t->backColor(); break;
        case 8: _t->textAlign((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 9: _t->save(); break;
        case 10: _t->currentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 11: _t->cursorPositionChanged(); break;
        case 12: _t->clipboardDataChanged(); break;
        case 13: _t->about(); break;
        default: ;
        }
    }
}

const QMetaObject TextEdit::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TextEdit.data,
      qt_meta_data_TextEdit,  qt_static_metacall, 0, 0}
};


const QMetaObject *TextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextEdit.stringdata))
        return static_cast<void*>(const_cast< TextEdit*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
