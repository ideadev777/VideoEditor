/****************************************************************************
** Meta object code from reading C++ file 'cxlayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../cxlayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cxlayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CxLayerItem_t {
    QByteArrayData data[4];
    char stringdata[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CxLayerItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CxLayerItem_t qt_meta_stringdata_CxLayerItem = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 7),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 2)
    },
    "CxLayerItem\0setFade\0\0on\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CxLayerItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void CxLayerItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CxLayerItem *_t = static_cast<CxLayerItem *>(_o);
        switch (_id) {
        case 0: _t->setFade((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject CxLayerItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CxLayerItem.data,
      qt_meta_data_CxLayerItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *CxLayerItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CxLayerItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CxLayerItem.stringdata))
        return static_cast<void*>(const_cast< CxLayerItem*>(this));
    if (!strcmp(_clname, "QListWidgetItem"))
        return static_cast< QListWidgetItem*>(const_cast< CxLayerItem*>(this));
    return QObject::qt_metacast(_clname);
}

int CxLayerItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_CxLayer_t {
    QByteArrayData data[16];
    char stringdata[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CxLayer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CxLayer_t qt_meta_stringdata_CxLayer = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 20),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 12),
QT_MOC_LITERAL(4, 43, 3),
QT_MOC_LITERAL(5, 47, 18),
QT_MOC_LITERAL(6, 66, 15),
QT_MOC_LITERAL(7, 82, 8),
QT_MOC_LITERAL(8, 91, 3),
QT_MOC_LITERAL(9, 95, 3),
QT_MOC_LITERAL(10, 99, 13),
QT_MOC_LITERAL(11, 113, 18),
QT_MOC_LITERAL(12, 132, 2),
QT_MOC_LITERAL(13, 135, 2),
QT_MOC_LITERAL(14, 138, 15),
QT_MOC_LITERAL(15, 154, 2)
    },
    "CxLayer\0__currentItemChanged\0\0"
    "CxLayerItem*\0cur\0onSelectionChanged\0"
    "onAddVideoLayer\0fileName\0pos\0dur\0"
    "deleteCurItem\0onSeekRangeChanged\0st\0"
    "en\0onChangeCurFade\0on\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CxLayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   57,    2, 0x08,
       6,    3,   58,    2, 0x0a,
       6,    2,   65,    2, 0x2a,
       6,    1,   70,    2, 0x2a,
      10,    0,   73,    2, 0x0a,
      11,    2,   74,    2, 0x0a,
      14,    1,   79,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 3, QMetaType::QString, QMetaType::Int, QMetaType::Int,    7,    8,    9,
    0x80000000 | 3, QMetaType::QString, QMetaType::Int,    7,    8,
    0x80000000 | 3, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,   12,   13,
    QMetaType::Void, QMetaType::Bool,   15,

       0        // eod
};

void CxLayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CxLayer *_t = static_cast<CxLayer *>(_o);
        switch (_id) {
        case 0: _t->__currentItemChanged((*reinterpret_cast< CxLayerItem*(*)>(_a[1]))); break;
        case 1: _t->onSelectionChanged(); break;
        case 2: { CxLayerItem* _r = _t->onAddVideoLayer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< CxLayerItem**>(_a[0]) = _r; }  break;
        case 3: { CxLayerItem* _r = _t->onAddVideoLayer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< CxLayerItem**>(_a[0]) = _r; }  break;
        case 4: { CxLayerItem* _r = _t->onAddVideoLayer((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< CxLayerItem**>(_a[0]) = _r; }  break;
        case 5: _t->deleteCurItem(); break;
        case 6: _t->onSeekRangeChanged((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 7: _t->onChangeCurFade((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CxLayerItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CxLayer::*_t)(CxLayerItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxLayer::__currentItemChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CxLayer::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_CxLayer.data,
      qt_meta_data_CxLayer,  qt_static_metacall, 0, 0}
};


const QMetaObject *CxLayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CxLayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CxLayer.stringdata))
        return static_cast<void*>(const_cast< CxLayer*>(this));
    return QListWidget::qt_metacast(_clname);
}

int CxLayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CxLayer::__currentItemChanged(CxLayerItem * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
