/****************************************************************************
** Meta object code from reading C++ file 'mainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../source/header/mainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainWidget_t {
    QByteArrayData data[10];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainWidget_t qt_meta_stringdata_mainWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainWidget"
QT_MOC_LITERAL(1, 11, 39), // "on_sellTypeComboBox_currentIn..."
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 4), // "type"
QT_MOC_LITERAL(4, 57, 24), // "on_sellCancelBtn_clicked"
QT_MOC_LITERAL(5, 82, 40), // "on_sellBrandComboBox_currentI..."
QT_MOC_LITERAL(6, 123, 5), // "brand"
QT_MOC_LITERAL(7, 129, 30), // "on_sellNumSpinBox_valueChanged"
QT_MOC_LITERAL(8, 160, 5), // "value"
QT_MOC_LITERAL(9, 166, 20) // "on_sellOkBtn_clicked"

    },
    "mainWidget\0on_sellTypeComboBox_currentIndexChanged\0"
    "\0type\0on_sellCancelBtn_clicked\0"
    "on_sellBrandComboBox_currentIndexChanged\0"
    "brand\0on_sellNumSpinBox_valueChanged\0"
    "value\0on_sellOkBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainWidget[] = {

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
       4,    0,   42,    2, 0x08 /* Private */,
       5,    1,   43,    2, 0x08 /* Private */,
       7,    1,   46,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void mainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainWidget *_t = static_cast<mainWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sellTypeComboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_sellCancelBtn_clicked(); break;
        case 2: _t->on_sellBrandComboBox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_sellNumSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_sellOkBtn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject mainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainWidget.data,
      qt_meta_data_mainWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainWidget.stringdata0))
        return static_cast<void*>(const_cast< mainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
