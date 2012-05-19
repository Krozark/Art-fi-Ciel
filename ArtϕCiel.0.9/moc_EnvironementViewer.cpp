/****************************************************************************
** Meta object code from reading C++ file 'EnvironementViewer.hpp'
**
** Created: Thu Jan 26 17:20:12 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "EnvironementViewer.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EnvironementViewer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EnvironementViewer[] = {

 // content:
       5,       // revision
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

const QMetaObject EnvironementViewer::staticMetaObject = {
    { &QSFMLCanvas::staticMetaObject, qt_meta_stringdata_EnvironementViewer,
      qt_meta_data_EnvironementViewer, 0 }
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
        switch (_id) {
        case 0: SlotSelectedEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 1: SlotAddEntityPoint(); break;
        case 2: SlotAddEntityALot(); break;
        case 3: slotAddEntityLine(); break;
        case 4: SlotRemoveOne(); break;
        case 5: SlotSelect(); break;
        case 6: SlotClear(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
