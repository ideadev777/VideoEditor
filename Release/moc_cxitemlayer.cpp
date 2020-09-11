/****************************************************************************
** Meta object code from reading C++ file 'cxitemlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cxitemlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cxitemlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CxItemLayer_t {
    QByteArrayData data[13];
    char stringdata[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CxItemLayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CxItemLayer_t qt_meta_stringdata_CxItemLayer = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 9),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 15),
QT_MOC_LITERAL(4, 39, 4),
QT_MOC_LITERAL(5, 44, 10),
QT_MOC_LITERAL(6, 55, 16),
QT_MOC_LITERAL(7, 72, 2),
QT_MOC_LITERAL(8, 75, 12),
QT_MOC_LITERAL(9, 88, 18),
QT_MOC_LITERAL(10, 107, 15),
QT_MOC_LITERAL(11, 123, 3),
QT_MOC_LITERAL(12, 127, 11)
    },
    "CxItemLayer\0onAddItem\0\0CxGraphicsItem*\0"
    "item\0setMyScene\0CxGraphicsScene*\0sc\0"
    "onItemDelete\0onSelectionChanged\0"
    "onCurPosChanged\0pos\0fitTimeLine\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CxItemLayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a,
       5,    1,   47,    2, 0x0a,
       8,    1,   50,    2, 0x0a,
       9,    0,   53,    2, 0x0a,
      10,    1,   54,    2, 0x0a,
      12,    0,   57,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   11,
    QMetaType::Void,

       0        // eod
};

void CxItemLayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CxItemLayer *_t = static_cast<CxItemLayer *>(_o);
        switch (_id) {
        case 0: _t->onAddItem((*reinterpret_cast< CxGraphicsItem*(*)>(_a[1]))); break;
        case 1: _t->setMyScene((*reinterpret_cast< CxGraphicsScene*(*)>(_a[1]))); break;
        case 2: _t->onItemDelete((*reinterpret_cast< CxGraphicsItem*(*)>(_a[1]))); break;
        case 3: _t->onSelectionChanged(); break;
        case 4: _t->onCurPosChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: _t->fitTimeLine(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CxGraphicsItem* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CxGraphicsScene* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CxGraphicsItem* >(); break;
            }
            break;
        }
    }
}

const QMetaObject CxItemLayer::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_CxItemLayer.data,
      qt_meta_data_CxItemLayer,  qt_static_metacall, 0, 0}
};


const QMetaObject *CxItemLayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CxItemLayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CxItemLayer.stringdata))
        return static_cast<void*>(const_cast< CxItemLayer*>(this));
    return QListWidget::qt_metacast(_clname);
}

int CxItemLayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
