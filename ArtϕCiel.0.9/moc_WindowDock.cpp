/****************************************************************************
** Meta object code from reading C++ file 'WindowDock.hpp'
**
** Created: Thu Jun 28 00:02:53 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "WindowDock.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WindowDock.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WindowDock[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      23,   11,   11,   11, 0x05,
      41,   11,   11,   11, 0x05,
      52,   11,   11,   11, 0x05,
      77,   11,   11,   11, 0x05,
      98,   11,   11,   11, 0x05,
     118,   11,   11,   11, 0x05,
     138,   11,   11,   11, 0x05,
     151,   11,   11,   11, 0x05,
     167,   11,   11,   11, 0x05,
     179,   11,   11,   11, 0x05,
     189,   11,   11,   11, 0x05,
     200,   11,   11,   11, 0x05,
     211,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     229,   11,   11,   11, 0x0a,
     240,   11,   11,   11, 0x0a,
     258,   11,   11,   11, 0x0a,
     269,   11,   11,   11, 0x0a,
     291,   11,   11,   11, 0x0a,
     312,   11,   11,   11, 0x0a,
     332,   11,   11,   11, 0x0a,
     352,   11,   11,   11, 0x0a,
     365,   11,   11,   11, 0x0a,
     381,   11,   11,   11, 0x0a,
     393,   11,   11,   11, 0x0a,
     403,   11,   11,   11, 0x0a,
     414,   11,   11,   11, 0x0a,
     425,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_WindowDock[] = {
    "WindowDock\0\0EmitPlay()\0EmitOneStepMore()\0"
    "EmitStop()\0EmitChangeFrameTime(int)\0"
    "EmitAddEntityPoint()\0EmitAddEntityALot()\0"
    "EmitAddEntityLine()\0EmitSelect()\0"
    "EmitRemoveOne()\0EmitClear()\0EmitNew()\0"
    "EmitOpen()\0EmitSave()\0EmitContour(bool)\0"
    "SlotPlay()\0SlotOneStepMore()\0SlotStop()\0"
    "SlotChangeFrameTime()\0SlotAddEntityPoint()\0"
    "SlotAddEntityALot()\0SlotAddEntityLine()\0"
    "SlotSelect()\0SlotRemoveOne()\0SlotClear()\0"
    "SlotNew()\0SlotOpen()\0SlotSave()\0"
    "SlotContour(int)\0"
};

void WindowDock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WindowDock *_t = static_cast<WindowDock *>(_o);
        switch (_id) {
        case 0: _t->EmitPlay(); break;
        case 1: _t->EmitOneStepMore(); break;
        case 2: _t->EmitStop(); break;
        case 3: _t->EmitChangeFrameTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->EmitAddEntityPoint(); break;
        case 5: _t->EmitAddEntityALot(); break;
        case 6: _t->EmitAddEntityLine(); break;
        case 7: _t->EmitSelect(); break;
        case 8: _t->EmitRemoveOne(); break;
        case 9: _t->EmitClear(); break;
        case 10: _t->EmitNew(); break;
        case 11: _t->EmitOpen(); break;
        case 12: _t->EmitSave(); break;
        case 13: _t->EmitContour((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->SlotPlay(); break;
        case 15: _t->SlotOneStepMore(); break;
        case 16: _t->SlotStop(); break;
        case 17: _t->SlotChangeFrameTime(); break;
        case 18: _t->SlotAddEntityPoint(); break;
        case 19: _t->SlotAddEntityALot(); break;
        case 20: _t->SlotAddEntityLine(); break;
        case 21: _t->SlotSelect(); break;
        case 22: _t->SlotRemoveOne(); break;
        case 23: _t->SlotClear(); break;
        case 24: _t->SlotNew(); break;
        case 25: _t->SlotOpen(); break;
        case 26: _t->SlotSave(); break;
        case 27: _t->SlotContour((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WindowDock::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WindowDock::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_WindowDock,
      qt_meta_data_WindowDock, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WindowDock::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WindowDock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WindowDock::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WindowDock))
        return static_cast<void*>(const_cast< WindowDock*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int WindowDock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void WindowDock::EmitPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void WindowDock::EmitOneStepMore()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void WindowDock::EmitStop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void WindowDock::EmitChangeFrameTime(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void WindowDock::EmitAddEntityPoint()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void WindowDock::EmitAddEntityALot()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void WindowDock::EmitAddEntityLine()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void WindowDock::EmitSelect()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void WindowDock::EmitRemoveOne()
{
    QMetaObject::activate(this, &staticMetaObject, 8, 0);
}

// SIGNAL 9
void WindowDock::EmitClear()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void WindowDock::EmitNew()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void WindowDock::EmitOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 11, 0);
}

// SIGNAL 12
void WindowDock::EmitSave()
{
    QMetaObject::activate(this, &staticMetaObject, 12, 0);
}

// SIGNAL 13
void WindowDock::EmitContour(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_END_MOC_NAMESPACE
