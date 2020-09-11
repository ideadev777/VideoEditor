/****************************************************************************
** Meta object code from reading C++ file 'cxgraphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../graphics/cxgraphicsview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cxgraphicsview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CxGraphicsView_t {
    QByteArrayData data[11];
    char stringdata[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CxGraphicsView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CxGraphicsView_t qt_meta_stringdata_CxGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 12),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 2),
QT_MOC_LITERAL(4, 32, 10),
QT_MOC_LITERAL(5, 43, 16),
QT_MOC_LITERAL(6, 60, 2),
QT_MOC_LITERAL(7, 63, 11),
QT_MOC_LITERAL(8, 75, 10),
QT_MOC_LITERAL(9, 86, 4),
QT_MOC_LITERAL(10, 91, 3)
    },
    "CxGraphicsView\0__mouseHover\0\0on\0"
    "setMyScene\0CxGraphicsScene*\0sc\0"
    "fitToScreen\0onDrawMark\0role\0col\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CxGraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a,
       7,    0,   40,    2, 0x0a,
       8,    2,   41,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor,    9,   10,

       0        // eod
};

void CxGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CxGraphicsView *_t = static_cast<CxGraphicsView *>(_o);
        switch (_id) {
        case 0: _t->__mouseHover((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->setMyScene((*reinterpret_cast< CxGraphicsScene*(*)>(_a[1]))); break;
        case 2: _t->fitToScreen(); break;
        case 3: _t->onDrawMark((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CxGraphicsScene* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CxGraphicsView::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxGraphicsView::__mouseHover)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CxGraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_CxGraphicsView.data,
      qt_meta_data_CxGraphicsView,  qt_static_metacall, 0, 0}
};


const QMetaObject *CxGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CxGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CxGraphicsView.stringdata))
        return static_cast<void*>(const_cast< CxGraphicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int CxGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CxGraphicsView::__mouseHover(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
