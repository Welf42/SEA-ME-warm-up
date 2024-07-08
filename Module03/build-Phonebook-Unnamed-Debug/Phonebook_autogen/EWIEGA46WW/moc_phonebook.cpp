/****************************************************************************
** Meta object code from reading C++ file 'phonebook.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Phonebook/phonebook.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phonebook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AddContactDialog_t {
    const uint offsetsAndSize[2];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AddContactDialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AddContactDialog_t qt_meta_stringdata_AddContactDialog = {
    {
QT_MOC_LITERAL(0, 16) // "AddContactDialog"

    },
    "AddContactDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddContactDialog[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void AddContactDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject AddContactDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AddContactDialog.offsetsAndSize,
    qt_meta_data_AddContactDialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AddContactDialog_t
, QtPrivate::TypeAndForceComplete<AddContactDialog, std::true_type>



>,
    nullptr
} };


const QMetaObject *AddContactDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddContactDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AddContactDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AddContactDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_Phonebook_t {
    const uint offsetsAndSize[26];
    char stringdata0[275];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Phonebook_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Phonebook_t qt_meta_stringdata_Phonebook = {
    {
QT_MOC_LITERAL(0, 9), // "Phonebook"
QT_MOC_LITERAL(10, 25), // "on_pushButton_add_clicked"
QT_MOC_LITERAL(36, 0), // ""
QT_MOC_LITERAL(37, 30), // "on_pushButton_bookmark_clicked"
QT_MOC_LITERAL(68, 29), // "on_pushButton_details_clicked"
QT_MOC_LITERAL(98, 28), // "on_pushButton_remove_clicked"
QT_MOC_LITERAL(127, 33), // "on_pushButton_allContacts_cli..."
QT_MOC_LITERAL(161, 31), // "on_pushButton_bookmarks_clicked"
QT_MOC_LITERAL(193, 30), // "on_lineEdit_filter_textChanged"
QT_MOC_LITERAL(224, 4), // "text"
QT_MOC_LITERAL(229, 27), // "on_listView_contact_clicked"
QT_MOC_LITERAL(257, 11), // "QModelIndex"
QT_MOC_LITERAL(269, 5) // "index"

    },
    "Phonebook\0on_pushButton_add_clicked\0"
    "\0on_pushButton_bookmark_clicked\0"
    "on_pushButton_details_clicked\0"
    "on_pushButton_remove_clicked\0"
    "on_pushButton_allContacts_clicked\0"
    "on_pushButton_bookmarks_clicked\0"
    "on_lineEdit_filter_textChanged\0text\0"
    "on_listView_contact_clicked\0QModelIndex\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Phonebook[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    1,   68,    2, 0x08,    7 /* Private */,
      10,    1,   71,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void Phonebook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Phonebook *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_add_clicked(); break;
        case 1: _t->on_pushButton_bookmark_clicked(); break;
        case 2: _t->on_pushButton_details_clicked(); break;
        case 3: _t->on_pushButton_remove_clicked(); break;
        case 4: _t->on_pushButton_allContacts_clicked(); break;
        case 5: _t->on_pushButton_bookmarks_clicked(); break;
        case 6: _t->on_lineEdit_filter_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_listView_contact_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Phonebook::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Phonebook.offsetsAndSize,
    qt_meta_data_Phonebook,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Phonebook_t
, QtPrivate::TypeAndForceComplete<Phonebook, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>


>,
    nullptr
} };


const QMetaObject *Phonebook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Phonebook::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Phonebook.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Phonebook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
