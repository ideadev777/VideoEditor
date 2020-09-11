/****************************************************************************
** Meta object code from reading C++ file 'cxgraphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphics/cxgraphicsscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cxgraphicsscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CxGraphicsScene_t {
    QByteArrayData data[20];
    char stringdata[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CxGraphicsScene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CxGraphicsScene_t qt_meta_stringdata_CxGraphicsScene = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 12),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 2),
QT_MOC_LITERAL(4, 33, 15),
QT_MOC_LITERAL(5, 49, 20),
QT_MOC_LITERAL(6, 70, 11),
QT_MOC_LITERAL(7, 82, 15),
QT_MOC_LITERAL(8, 98, 4),
QT_MOC_LITERAL(9, 103, 13),
QT_MOC_LITERAL(10, 117, 14),
QT_MOC_LITERAL(11, 132, 18),
QT_MOC_LITERAL(12, 151, 10),
QT_MOC_LITERAL(13, 162, 4),
QT_MOC_LITERAL(14, 167, 3),
QT_MOC_LITERAL(15, 171, 15),
QT_MOC_LITERAL(16, 187, 16),
QT_MOC_LITERAL(17, 204, 15),
QT_MOC_LITERAL(18, 220, 11),
QT_MOC_LITERAL(19, 232, 13)
    },
    "CxGraphicsScene\0__mouseHover\0\0on\0"
    "__screenClicked\0__currentTimeChanged\0"
    "__itemAdded\0CxGraphicsItem*\0item\0"
    "__itemDeleted\0__initDrawRole\0"
    "onSelectionChanged\0onDrawMark\0role\0"
    "col\0onRemoveCurItem\0onRemoveAllItems\0"
    "setMovementMode\0setFillMode\0onItemClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CxGraphicsScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x05,
       4,    0,   82,    2, 0x05,
       5,    1,   83,    2, 0x05,
       6,    1,   86,    2, 0x05,
       9,    1,   89,    2, 0x05,
      10,    0,   92,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      11,    0,   93,    2, 0x0a,
      12,    2,   94,    2, 0x0a,
      15,    0,   99,    2, 0x0a,
      16,    0,  100,    2, 0x0a,
      17,    0,  101,    2, 0x0a,
      18,    0,  102,    2, 0x0a,
      19,    1,  103,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void CxGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CxGraphicsScene *_t = static_cast<CxGraphicsScene *>(_o);
        switch (_id) {
        case 0: _t->__mouseHover((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->__screenClicked(); break;
        case 2: _t->__currentTimeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->__itemAdded((*reinterpret_cast< CxGraphicsItem*(*)>(_a[1]))); break;
        case 4: _t->__itemDeleted((*reinterpret_cast< CxGraphicsItem*(*)>(_a[1]))); break;
        case 5: _t->__initDrawRole(); break;
        case 6: _t->onSelectionChanged(); break;
        case 7: _t->onDrawMark((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 8: _t->onRemoveCurItem(); break;
        case 9: _t->onRemoveAllItems(); break;
        case 10: _t->setMovementMode(); break;
        case 11: _t->setFillMode(); break;
        case 12: _t->onItemClicked((*reinterpret_cast< CxGraphicsItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CxGraphicsItem* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CxGraphicsItem* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CxGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CxGraphicsScene::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxGraphicsScene::__mouseHover)) {
                *result = 0;
            }
        }
        {
            typedef void (CxGraphicsScene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxGraphicsScene::__screenClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (CxGraphicsScene::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxGraphicsScene::__currentTimeChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (CxGraphicsScene::*_t)(CxGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxGraphicsScene::__itemAdded)) {
                *result = 3;
            }
        }
        {
            typedef void (CxGraphicsScene::*_t)(CxGraphicsItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxGraphicsScene::__itemDeleted)) {
                *result = 4;
            }
        }
        {
            typedef void (CxGraphicsScene::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxGraphicsScene::__initDrawRole)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject CxGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_CxGraphicsScene.data,
      qt_meta_data_CxGraphicsScene,  qt_static_metacall, 0, 0}
};


const QMetaObject *CxGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CxGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CxGraphicsScene.stringdata))
        return static_cast<void*>(const_cast< CxGraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int CxGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CxGraphicsScene::__mouseHover(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CxGraphicsScene::__screenClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CxGraphicsScene::__currentTimeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CxGraphicsScene::__itemAdded(CxGraphicsItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CxGraphicsScene::__itemDeleted(CxGraphicsItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CxGraphicsScene::__initDrawRole()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
