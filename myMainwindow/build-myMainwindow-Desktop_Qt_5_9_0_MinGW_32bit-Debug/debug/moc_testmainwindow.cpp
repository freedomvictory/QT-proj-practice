/****************************************************************************
** Meta object code from reading C++ file 'testmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myMainwindow/testmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_testMainWindow_t {
    QByteArrayData data[8];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_testMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_testMainWindow_t qt_meta_stringdata_testMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "testMainWindow"
QT_MOC_LITERAL(1, 15, 20), // "action_new_triggered"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "m_action_handle"
QT_MOC_LITERAL(4, 53, 23), // "on_action_New_triggered"
QT_MOC_LITERAL(5, 77, 30), // "on_actionshow_Docker_triggered"
QT_MOC_LITERAL(6, 108, 7), // "setText"
QT_MOC_LITERAL(7, 116, 6) // "string"

    },
    "testMainWindow\0action_new_triggered\0"
    "\0m_action_handle\0on_action_New_triggered\0"
    "on_actionshow_Docker_triggered\0setText\0"
    "string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_testMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       3,    1,   42,    2, 0x08 /* Private */,
       4,    0,   45,    2, 0x08 /* Private */,
       5,    0,   46,    2, 0x08 /* Private */,
       6,    1,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void testMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        testMainWindow *_t = static_cast<testMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->action_new_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->m_action_handle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_action_New_triggered(); break;
        case 3: _t->on_actionshow_Docker_triggered(); break;
        case 4: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject testMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_testMainWindow.data,
      qt_meta_data_testMainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *testMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *testMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_testMainWindow.stringdata0))
        return static_cast<void*>(const_cast< testMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int testMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
