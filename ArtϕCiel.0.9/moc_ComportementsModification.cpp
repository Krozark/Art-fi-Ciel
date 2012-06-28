/****************************************************************************
** Meta object code from reading C++ file 'ComportementsModification.hpp'
**
** Created: Thu Jun 28 00:03:06 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ComportementsModification.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ComportementsModification.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ComportementModification[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   25,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ComportementModification[] = {
    "ComportementModification\0\0HasSave()\0"
    "save()\0"
};

void ComportementModification::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ComportementModification *_t = static_cast<ComportementModification *>(_o);
        switch (_id) {
        case 0: _t->HasSave(); break;
        case 1: _t->save(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ComportementModification::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ComportementModification::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ComportementModification,
      qt_meta_data_ComportementModification, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ComportementModification::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ComportementModification::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ComportementModification::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ComportementModification))
        return static_cast<void*>(const_cast< ComportementModification*>(this));
    return QDialog::qt_metacast(_clname);
}

int ComportementModification::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ComportementModification::HasSave()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_SemieSitueModification[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x0a,
      33,   31,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SemieSitueModification[] = {
    "SemieSitueModification\0\0save()\0A\0"
    "SetComportement(SemieSitue*)\0"
};

void SemieSitueModification::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SemieSitueModification *_t = static_cast<SemieSitueModification *>(_o);
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->SetComportement((*reinterpret_cast< SemieSitue*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SemieSitueModification::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SemieSitueModification::staticMetaObject = {
    { &ComportementModification::staticMetaObject, qt_meta_stringdata_SemieSitueModification,
      qt_meta_data_SemieSitueModification, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SemieSitueModification::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SemieSitueModification::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SemieSitueModification::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SemieSitueModification))
        return static_cast<void*>(const_cast< SemieSitueModification*>(this));
    return ComportementModification::qt_metacast(_clname);
}

int SemieSitueModification::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ComportementModification::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
