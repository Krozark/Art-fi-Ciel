/****************************************************************************
** Meta object code from reading C++ file 'EntityModification.hpp'
**
** Created: Thu Jun 28 00:02:58 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "EntityModification.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EntityModification.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EntityModification[] = {

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
      20,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   19,   19,   19, 0x0a,
      37,   19,   19,   19, 0x0a,
      48,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EntityModification[] = {
    "EntityModification\0\0HasSave()\0Save()\0"
    "SetColor()\0SetImage()\0"
};

void EntityModification::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EntityModification *_t = static_cast<EntityModification *>(_o);
        switch (_id) {
        case 0: _t->HasSave(); break;
        case 1: _t->Save(); break;
        case 2: _t->SetColor(); break;
        case 3: _t->SetImage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EntityModification::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EntityModification::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EntityModification,
      qt_meta_data_EntityModification, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EntityModification::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EntityModification::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EntityModification::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EntityModification))
        return static_cast<void*>(const_cast< EntityModification*>(this));
    return QDialog::qt_metacast(_clname);
}

int EntityModification::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void EntityModification::HasSave()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
