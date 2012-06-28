/****************************************************************************
** Meta object code from reading C++ file 'EnvironementViewer.hpp'
**
** Created: Thu Jun 28 00:02:48 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "EnvironementViewer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EnvironementViewer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EnvironementViewer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      48,   19,   19,   19, 0x0a,
      69,   19,   19,   19, 0x0a,
      89,   19,   19,   19, 0x0a,
     109,   19,   19,   19, 0x0a,
     125,   19,   19,   19, 0x0a,
     138,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EnvironementViewer[] = {
    "EnvironementViewer\0\0SlotSelectedEntity(Entity*)\0"
    "SlotAddEntityPoint()\0SlotAddEntityALot()\0"
    "slotAddEntityLine()\0SlotRemoveOne()\0"
    "SlotSelect()\0SlotClear()\0"
};

void EnvironementViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EnvironementViewer *_t = static_cast<EnvironementViewer *>(_o);
        switch (_id) {
        case 0: _t->SlotSelectedEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 1: _t->SlotAddEntityPoint(); break;
        case 2: _t->SlotAddEntityALot(); break;
        case 3: _t->slotAddEntityLine(); break;
        case 4: _t->SlotRemoveOne(); break;
        case 5: _t->SlotSelect(); break;
        case 6: _t->SlotClear(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EnvironementViewer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EnvironementViewer::staticMetaObject = {
    { &QSFMLCanvas::staticMetaObject, qt_meta_stringdata_EnvironementViewer,
      qt_meta_data_EnvironementViewer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EnvironementViewer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EnvironementViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EnvironementViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EnvironementViewer))
        return static_cast<void*>(const_cast< EnvironementViewer*>(this));
    return QSFMLCanvas::qt_metacast(_clname);
}

int EnvironementViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSFMLCanvas::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
