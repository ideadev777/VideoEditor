/****************************************************************************
** Meta object code from reading C++ file 'cxvideopanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../panel/cxvideopanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cxvideopanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CxVideoPanel_t {
    QByteArrayData data[21];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CxVideoPanel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CxVideoPanel_t qt_meta_stringdata_CxVideoPanel = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 14),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 2),
QT_MOC_LITERAL(4, 32, 2),
QT_MOC_LITERAL(5, 35, 9),
QT_MOC_LITERAL(6, 45, 4),
QT_MOC_LITERAL(7, 50, 15),
QT_MOC_LITERAL(8, 66, 3),
QT_MOC_LITERAL(9, 70, 10),
QT_MOC_LITERAL(10, 81, 10),
QT_MOC_LITERAL(11, 92, 12),
QT_MOC_LITERAL(12, 105, 5),
QT_MOC_LITERAL(13, 111, 6),
QT_MOC_LITERAL(14, 118, 19),
QT_MOC_LITERAL(15, 138, 12),
QT_MOC_LITERAL(16, 151, 4),
QT_MOC_LITERAL(17, 156, 14),
QT_MOC_LITERAL(18, 171, 5),
QT_MOC_LITERAL(19, 177, 6),
QT_MOC_LITERAL(20, 184, 1)
    },
    "CxVideoPanel\0__rangeChanged\0\0st\0en\0"
    "__preview\0msec\0__curPosChanged\0pos\0"
    "setSegment\0emitSignal\0fitSeekItems\0"
    "isAll\0onMute\0setCurrentLayerItem\0"
    "CxLayerItem*\0item\0setCurrentTime\0msecs\0"
    "onSeek\0w\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CxVideoPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x05,
       5,    1,   74,    2, 0x05,
       7,    1,   77,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    3,   80,    2, 0x0a,
       9,    2,   87,    2, 0x2a,
      11,    1,   92,    2, 0x0a,
      11,    0,   95,    2, 0x2a,
      13,    0,   96,    2, 0x0a,
      14,    1,   97,    2, 0x0a,
      17,    1,  100,    2, 0x0a,
      19,    1,  103,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QReal,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal, QMetaType::Bool,    3,    4,   10,
    QMetaType::Void, QMetaType::QReal, QMetaType::QReal,    3,    4,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QReal,   20,

       0        // eod
};

void CxVideoPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CxVideoPanel *_t = static_cast<CxVideoPanel *>(_o);
        switch (_id) {
        case 0: _t->__rangeChanged((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 1: _t->__preview((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->__curPosChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 3: _t->setSegment((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->setSegment((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 5: _t->fitSeekItems((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->fitSeekItems(); break;
        case 7: _t->onMute(); break;
        case 8: _t->setCurrentLayerItem((*reinterpret_cast< CxLayerItem*(*)>(_a[1]))); break;
        case 9: _t->setCurrentTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onSeek((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
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
            typedef void (CxVideoPanel::*_t)(qreal , qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxVideoPanel::__rangeChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CxVideoPanel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxVideoPanel::__preview)) {
                *result = 1;
            }
        }
        {
            typedef void (CxVideoPanel::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxVideoPanel::__curPosChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CxVideoPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CxVideoPanel.data,
      qt_meta_data_CxVideoPanel,  qt_static_metacall, 0, 0}
};


const QMetaObject *CxVideoPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CxVideoPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CxVideoPanel.stringdata))
        return static_cast<void*>(const_cast< CxVideoPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int CxVideoPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CxVideoPanel::__rangeChanged(qreal _t1, qreal _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CxVideoPanel::__preview(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CxVideoPanel::__curPosChanged(qreal _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
