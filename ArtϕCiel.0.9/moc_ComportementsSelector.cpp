/****************************************************************************
** Meta object code from reading C++ file 'ComportementsSelector.hpp'
**
** Created: Thu Jun 28 00:03:01 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ComportementsSelector.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ComportementsSelector.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ComportementSelector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   21,   21,   21, 0x0a,
      84,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ComportementSelector[] = {
    "ComportementSelector\0\0"
    "EmitSemiSitueSelected(SemieSitue*)\0"
    "SlotSemiSitueSelected(int)\0Maj()\0"
};

void ComportementSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ComportementSelector *_t = static_cast<ComportementSelector *>(_o);
        switch (_id) {
        case 0: _t->EmitSemiSitueSelected((*reinterpret_cast< SemieSitue*(*)>(_a[1]))); break;
        case 1: _t->SlotSemiSitueSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->Maj(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ComportementSelector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ComportementSelector::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ComportementSelector,
      qt_meta_data_ComportementSelector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ComportementSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ComportementSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ComportementSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComportementSelector))
        return static_cast<void*>(const_cast< ComportementSelector*>(this));
    return QWidget::qt_metacast(_clname);
}

int ComportementSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ComportementSelector::EmitSemiSitueSelected(SemieSitue * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
