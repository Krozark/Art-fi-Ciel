/****************************************************************************
** Meta object code from reading C++ file 'EntitySelector.hpp'
**
** Created: Thu Jun 28 00:02:55 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "EntitySelector.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EntitySelector.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EntitySelector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   15,   15,   15, 0x0a,
      67,   15,   15,   15, 0x0a,
      83,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EntitySelector[] = {
    "EntitySelector\0\0EmitSelectedEntity(Entity*)\0"
    "SlotSelectdEntity(int)\0SlotRemove(int)\0"
    "Maj()\0"
};

void EntitySelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EntitySelector *_t = static_cast<EntitySelector *>(_o);
        switch (_id) {
        case 0: _t->EmitSelectedEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 1: _t->SlotSelectdEntity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->SlotRemove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Maj(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EntitySelector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EntitySelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EntitySelector,
      qt_meta_data_EntitySelector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EntitySelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EntitySelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EntitySelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EntitySelector))
        return static_cast<void*>(const_cast< EntitySelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int EntitySelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void EntitySelector::EmitSelectedEntity(Entity * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
