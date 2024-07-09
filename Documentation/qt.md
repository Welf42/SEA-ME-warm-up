<details>
<summary><strong>QMainWindow</strong></summary>

## Overview
QMainWindow is the central widget for creating the main application window in Qt. It provides a framework for building an application's user interface with standard features like menus, toolbars, dock widgets, and a status bar[1].

### Key Features
- Central widget area
- Menu bar
- Tool bars
- Dock widgets
- Status bar

### Usage
```cpp
#include <QMainWindow>

class MyMainWindow : public QMainWindow {
    Q_OBJECT
public:
    MyMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        setCentralWidget(new QWidget);
        createMenus();
        createToolBars();
        createStatusBar();
    }
};
```

### Best Practices
- Set a central widget to hold the main content of your application
- Use actions to create menu items and toolbar buttons for consistency
- Implement dock widgets for modular, user-customizable interfaces

### Tips
- Use `setMenuBar()`, `addToolBar()`, and `setStatusBar()` to add respective components
- Utilize `QSettings` to save and restore window state and geometry

### Important Methods
- `setCentralWidget(QWidget *widget)`: Sets the central widget of the window
- `menuBar()`: Returns the menu bar for the main window
- `statusBar()`: Returns the status bar for the main window
- `addToolBar(QToolBar *toolbar)`: Adds a toolbar to the main window
- `addDockWidget(Qt::DockWidgetArea area, QDockWidget *dockwidget)`: Adds a dock widget to the specified area

</details>

<details>
<summary><strong>QDialog</strong></summary>

## Overview
QDialog is a window for short-term tasks and brief communication with the user. It's typically used for settings, input forms, or displaying information.

### Key Features
- Modal or modeless operation
- Built-in button layouts (OK, Cancel, etc.)
- Can be customized with any widgets

### Usage
```cpp
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>

class MyDialog : public QDialog {
    Q_OBJECT
public:
    MyDialog(QWidget *parent = nullptr) : QDialog(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);
        QPushButton *okButton = new QPushButton("OK", this);
        layout->addWidget(okButton);
        connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    }
};

// Using the dialog
MyDialog dialog;
if (dialog.exec() == QDialog::Accepted) {
    // Handle acceptance
}
```

### Best Practices
- Use `exec()` for modal dialogs and `show()` for modeless ones
- Implement `accept()` and `reject()` slots for handling dialog closure
- Utilize `QDialogButtonBox` for standard button layouts

### Tips
- Override `sizeHint()` to suggest an initial size for your dialog
- Use `setModal(true)` to prevent interaction with other windows while the dialog is open

### Important Methods
- `exec()`: Shows the dialog as modal and returns a dialog code
- `show()`: Shows the dialog as modeless
- `accept()`: Accepts the dialog (typically emitted when OK is clicked)
- `reject()`: Rejects the dialog (typically emitted when Cancel is clicked)

</details>

<details>
<summary><strong>QWidget</strong></summary>

## Overview
QWidget is the base class of all user interface objects in Qt. It's the atom of the user interface: the basic building block for creating custom UI elements.

### Key Features
- Can contain other widgets
- Can be styled with CSS-like stylesheets
- Handles its own painting and event processing

### Usage
```cpp
#include <QWidget>
#include <QPainter>

class MyCustomWidget : public QWidget {
    Q_OBJECT
public:
    MyCustomWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawText(rect(), Qt::AlignCenter, "Hello, World!");
    }
};
```

### Best Practices
- Override `paintEvent()` for custom drawing
- Use layouts to manage child widgets
- Implement custom signals and slots for widget-specific events

### Tips
- Call `update()` to schedule a repaint of the widget
- Use `setAttribute(Qt::WA_OpaquePaintEvent)` for widgets that completely fill their paint area
- Implement `sizeHint()` and `minimumSizeHint()` for proper sizing in layouts

### Important Methods
- `setLayout(QLayout *layout)`: Sets the layout manager for the widget
- `show()`: Shows the widget and its child widgets
- `hide()`: Hides the widget and its child widgets
- `update()`: Schedules a paint event for updating the widget
- `setStyleSheet(const QString &styleSheet)`: Sets the widget's style sheet

</details>

<details>
<summary><strong>QObject</strong></summary>

## Overview
QObject is the base class for all Qt objects. It's central to Qt's meta-object system, enabling features like signals and slots, properties, and dynamic object management.

### Key Features
- Signal and slot mechanism
- Object naming and hierarchical ownership
- Meta-object information (run-time type information)
- Event handling

### Usage
```cpp
#include <QObject>

class MyClass : public QObject {
    Q_OBJECT
public:
    MyClass(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void mySignal();

public slots:
    void mySlot() {
        emit mySignal();
    }
};
```

### Best Practices
- Always use the `Q_OBJECT` macro in classes derived from QObject
- Utilize parent-child relationships for automatic memory management
- Use signals and slots for loose coupling between objects

### Tips
- Use `connect()` to establish signal-slot connections
- Implement custom properties with `Q_PROPERTY` macro
- Use `qobject_cast<>()` for safe downcasting of QObject pointers

### Important Methods
- `connect()`: Connects a signal to a slot
- `disconnect()`: Disconnects a signal from a slot
- `sender()`: Returns a pointer to the object that sent the signal
- `deleteLater()`: Schedules the object for deletion
- `setProperty()` and `property()`: Set and get dynamic properties

</details>

This covers the core Qt classes. Each section provides an overview, key features, usage examples, best practices, tips, and important methods for the respective class. The information is based on the official Qt documentation and common Qt programming practices[1][2][3][4][5].

Citations:
[1] https://doc.qt.io/qt-6/qmainwindow.html
[2] https://doc.qt.io/qt-6/mainwindow.html
[3] https://stackoverflow.com/questions/57850332/which-class-should-inherit-a-qmainwindow
[4] https://www.qtcentre.org/threads/71197-Adding-class-to-MainWindow-using-QHBoxLayout
[5] https://forum.qt.io/topic/118748/combining-classes-append-class-to-qmainwindow