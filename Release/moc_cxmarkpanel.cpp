/****************************************************************************
** Meta object code from reading C++ file 'cxmarkpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../panel/cxmarkpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cxmarkpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CxMarkPanel_t {
    QByteArrayData data[9];
    char stringdata[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CxMarkPanel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CxMarkPanel_t qt_meta_stringdata_CxMarkPanel = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 10),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 4),
QT_MOC_LITERAL(4, 29, 3),
QT_MOC_LITERAL(5, 33, 6),
QT_MOC_LITERAL(6, 40, 8),
QT_MOC_LITERAL(7, 49, 6),
QT_MOC_LITERAL(8, 56, 8)
    },
    "CxMarkPanel\0__drawMark\0\0role\0col\0"
    "onRect\0onCircle\0onLine\0onNumber\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CxMarkPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x0a,
       6,    0,   45,    2, 0x0a,
       7,    0,   46,    2, 0x0a,
       8,    0,   47,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QColor,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CxMarkPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CxMarkPanel *_t = static_cast<CxMarkPanel *>(_o);
        switch (_id) {
        case 0: _t->__drawMark((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QColor(*)>(_a[2]))); break;
        case 1: _t->onRect(); break;
        case 2: _t->onCircle(); break;
        case 3: _t->onLine(); break;
        case 4: _t->onNumber(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CxMarkPanel::*_t)(int , QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CxMarkPanel::__drawMark)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CxMarkPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CxMarkPanel.data,
      qt_meta_data_CxMarkPanel,  qt_static_metacall, 0, 0}
};


const QMetaObject *CxMarkPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CxMarkPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CxMarkPanel.stringdata))
        return static_cast<void*>(const_cast< CxMarkPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int CxMarkPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CxMarkPanel::__drawMark(int _t1, QColor _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
