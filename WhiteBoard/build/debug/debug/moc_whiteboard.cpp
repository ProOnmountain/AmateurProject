/****************************************************************************
** Meta object code from reading C++ file 'whiteboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/whiteboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'whiteboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WhiteBoard_t {
    QByteArrayData data[16];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WhiteBoard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WhiteBoard_t qt_meta_stringdata_WhiteBoard = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WhiteBoard"
QT_MOC_LITERAL(1, 11, 27), // "on_radioButton_rect_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 29), // "on_radioButton_circle_clicked"
QT_MOC_LITERAL(4, 70, 29), // "on_radioButton_choose_clicked"
QT_MOC_LITERAL(5, 100, 33), // "on_spinBox_lineWidth_valueCha..."
QT_MOC_LITERAL(6, 134, 4), // "arg1"
QT_MOC_LITERAL(7, 139, 40), // "on_comboBox_lineType_currentI..."
QT_MOC_LITERAL(8, 180, 5), // "index"
QT_MOC_LITERAL(9, 186, 35), // "on_pushButton_boundingColor_c..."
QT_MOC_LITERAL(10, 222, 31), // "on_pushButton_fillColor_clicked"
QT_MOC_LITERAL(11, 254, 12), // "itemSelected"
QT_MOC_LITERAL(12, 267, 14), // "QGraphicsItem*"
QT_MOC_LITERAL(13, 282, 4), // "item"
QT_MOC_LITERAL(14, 287, 19), // "Board::GraphicsType"
QT_MOC_LITERAL(15, 307, 4) // "type"

    },
    "WhiteBoard\0on_radioButton_rect_clicked\0"
    "\0on_radioButton_circle_clicked\0"
    "on_radioButton_choose_clicked\0"
    "on_spinBox_lineWidth_valueChanged\0"
    "arg1\0on_comboBox_lineType_currentIndexChanged\0"
    "index\0on_pushButton_boundingColor_clicked\0"
    "on_pushButton_fillColor_clicked\0"
    "itemSelected\0QGraphicsItem*\0item\0"
    "Board::GraphicsType\0type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WhiteBoard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    2,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,

       0        // eod
};

void WhiteBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WhiteBoard *_t = static_cast<WhiteBoard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_radioButton_rect_clicked(); break;
        case 1: _t->on_radioButton_circle_clicked(); break;
        case 2: _t->on_radioButton_choose_clicked(); break;
        case 3: _t->on_spinBox_lineWidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_lineType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_boundingColor_clicked(); break;
        case 6: _t->on_pushButton_fillColor_clicked(); break;
        case 7: _t->itemSelected((*reinterpret_cast< QGraphicsItem*(*)>(_a[1])),(*reinterpret_cast< Board::GraphicsType(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    }
}

const QMetaObject WhiteBoard::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_WhiteBoard.data,
      qt_meta_data_WhiteBoard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WhiteBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WhiteBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WhiteBoard.stringdata0))
        return static_cast<void*>(const_cast< WhiteBoard*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int WhiteBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
