/****************************************************************************
** Meta object code from reading C++ file 'MainWindows.hpp'
**
** Created: Thu Jan 26 17:20:13 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindows.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindows.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindows[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      24,   12,   12,   12, 0x0a,
      49,   12,   12,   12, 0x0a,
      67,   12,   12,   12, 0x0a,
      78,   12,   12,   12, 0x0a,
     106,   12,   12,   12, 0x0a,
     139,   12,   12,   12, 0x0a,
     151,   12,   12,   12, 0x0a,
     162,   12,   12,   12, 0x0a,
     172,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindows[] = {
    "MainWindows\0\0SlotPlay()\0"
    "SlotChangeFrameTime(int)\0SlotOneStepMore()\0"
    "SlotStop()\0SlotSelectedEntity(Entity*)\0"
    "SlotSetComportement(SemieSitue*)\0"
    "SlotWrite()\0SlotOpen()\0SlotNew()\0"
    "SlotContour(bool)\0"
};

const QMetaObject MainWindows::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindows,
      qt_meta_data_MainWindows, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindows::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindows))
        return static_cast<void*>(const_cast< MainWindows*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: SlotPlay(); break;
        case 1: SlotChangeFrameTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: SlotOneStepMore(); break;
        case 3: SlotStop(); break;
        case 4: SlotSelectedEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 5: SlotSetComportement((*reinterpret_cast< SemieSitue*(*)>(_a[1]))); break;
        case 6: SlotWrite(); break;
        case 7: SlotOpen(); break;
        case 8: SlotNew(); break;
        case 9: SlotContour((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
