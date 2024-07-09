### Qt Library Docs

## Core Qt Classes

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

<!--    /////////////////////////////////////////////////////////////// -->

## GUI Components

<details>
<summary><strong>QListView</strong></summary>

## Overview
QListView is a widget that provides a scrollable list of items. It's part of Qt's Model/View framework, allowing for flexible display of data.

### Key Features
- Displays items in a vertical list
- Supports selection modes (single, multiple, extended)
- Can display icons alongside text
- Customizable item delegates for advanced rendering

### Usage
```cpp
#include <QListView>
#include <QStringListModel>

QListView *listView = new QListView(this);
QStringListModel *model = new QStringListModel(this);
QStringList list = {"Item 1", "Item 2", "Item 3"};
model->setStringList(list);
listView->setModel(model);
```

### Best Practices
- Use with a model (e.g., QStringListModel, QStandardItemModel) to populate items
- Implement custom item delegates for complex item rendering
- Connect to selectionChanged signal to handle user selections

### Tips
- Use `setAlternatingRowColors(true)` for better readability
- Implement `setEditTriggers()` to control when items can be edited
- Use `setViewMode(QListView::IconMode)` for a grid-like icon view

### Important Methods
- `setModel(QAbstractItemModel *model)`: Sets the model for the view
- `selectionModel()`: Returns the current selection model
- `setItemDelegate(QAbstractItemDelegate *delegate)`: Sets a custom delegate for rendering items
- `setSelectionMode(QAbstractItemView::SelectionMode mode)`: Sets the selection behavior
- `currentIndex()`: Returns the model index of the current item

</details>

<details>
<summary><strong>QTextBrowser</strong></summary>

## Overview
QTextBrowser is a rich text viewer with hypertext navigation capabilities. It's ideal for displaying formatted text content like help documentation or simple HTML pages.

### Key Features
- Supports rich text formatting (HTML subset)
- Hyperlink navigation
- Text search functionality
- Can load local and remote content

### Usage
```cpp
#include <QTextBrowser>

QTextBrowser *browser = new QTextBrowser(this);
browser->setHtml("<h1>Welcome</h1><p>This is a <a href='#section'>link</a>.</p>");
browser->setOpenExternalLinks(true);
```

### Best Practices
- Use `setSource()` to load content from a URL or local file
- Connect to `anchorClicked()` signal to handle link navigation
- Use `setSearchPaths()` to set paths for resolving relative URLs

### Tips
- Use `setOpenExternalLinks(true)` to open external links in the system browser
- Implement `setOpenLinks(false)` and handle `anchorClicked()` for custom navigation
- Use `find()` method for text search functionality

### Important Methods
- `setHtml(const QString &text)`: Sets the content as HTML
- `setSource(const QUrl &name)`: Sets the source of the content to display
- `backward()` and `forward()`: Navigate through the history
- `zoomIn()` and `zoomOut()`: Adjust the text size
- `reload()`: Reloads the current document

</details>

<details>
<summary><strong>QLineEdit</strong></summary>

## Overview
QLineEdit is a one-line text editor. It allows the user to enter and edit a single line of plain text.

### Key Features
- Single-line text input
- Password echo mode
- Input validation and masking
- Undo/redo functionality

### Usage
```cpp
#include <QLineEdit>

QLineEdit *lineEdit = new QLineEdit(this);
lineEdit->setPlaceholderText("Enter your name");
connect(lineEdit, &QLineEdit::textChanged, this, &MyClass::onTextChanged);
```

### Best Practices
- Use `setPlaceholderText()` to provide hints to the user
- Implement input validation using `setValidator()`
- Connect to appropriate signals (`textChanged()`, `returnPressed()`, etc.) for real-time interaction

### Tips
- Use `setEchoMode(QLineEdit::Password)` for password fields
- Implement `setInputMask()` for formatted input (e.g., phone numbers)
- Use `setClearButtonEnabled(true)` to add a clear button inside the field

### Important Methods
- `text()`: Returns the current text
- `setText(const QString &)`: Sets the text
- `clear()`: Clears the content
- `setMaxLength(int)`: Sets the maximum allowed text length
- `setReadOnly(bool)`: Makes the line edit read-only

</details>

<details>
<summary><strong>QPushButton</strong></summary>

## Overview
QPushButton is a command button that can be clicked by the user to trigger an action.

### Key Features
- Can display text, icons, or both
- Supports auto-repeat for continuous clicking
- Can be set as the default button in dialogs
- Checkable state for toggle functionality

### Usage
```cpp
#include <QPushButton>

QPushButton *button = new QPushButton("Click Me", this);
button->setIcon(QIcon(":/icons/myicon.png"));
connect(button, &QPushButton::clicked, this, &MyClass::onButtonClicked);
```

### Best Practices
- Use clear, action-oriented text for button labels
- Implement keyboard shortcuts using `setShortcut()`
- Use `setDefault(true)` for the primary action in dialogs

### Tips
- Use `setCheckable(true)` for toggle buttons
- Implement `setAutoRepeat(true)` for buttons that need continuous pressing
- Use `setFlat(true)` for a more modern, borderless look

### Important Methods
- `setText(const QString &text)`: Sets the button's text
- `setIcon(const QIcon &icon)`: Sets the button's icon
- `setEnabled(bool)`: Enables or disables the button
- `click()`: Programmatically clicks the button
- `setMenu(QMenu *menu)`: Sets a menu to be shown when the button is clicked

</details>

<details>
<summary><strong>QLabel</strong></summary>

## Overview
QLabel is a widget used to display text or images. It's typically used for static content but can also support basic rich text.

### Key Features
- Can display plain text, rich text, or images
- Supports text alignment and word wrapping
- Can act as a buddy for other widgets (for accessibility)
- Supports basic interactions like opening URLs

### Usage
```cpp
#include <QLabel>

QLabel *label = new QLabel("Hello, World!", this);
label->setAlignment(Qt::AlignCenter);

// For images
QLabel *imageLabel = new QLabel(this);
imageLabel->setPixmap(QPixmap(":/images/myimage.png"));
```

### Best Practices
- Use `setBuddy()` to associate labels with input widgets
- Implement `setWordWrap(true)` for long text that should wrap
- Use `setOpenExternalLinks(true)` for clickable URLs in rich text

### Tips
- Use `setTextFormat(Qt::RichText)` to enable rich text rendering
- Implement `setTextInteractionFlags()` to control text selection and linking
- Use `setScaledContents(true)` to scale image content to fit the label size

### Important Methods
- `setText(const QString &)`: Sets the label's text
- `setPixmap(const QPixmap &)`: Sets an image to display
- `clear()`: Clears the label's content
- `setAlignment(Qt::Alignment)`: Sets the text alignment
- `setMargin(int)`: Sets the margin around the content

</details>

<!--    /////////////////////////////////////////////////////////////// -->
## Models and Data

<details>
<summary><strong>QStandardItemModel</strong></summary>

## Overview
QStandardItemModel is a generic model that can be used with Qt's Model/View architecture. It provides a flexible way to store custom hierarchical data.

### Key Features
- Stores items in a tree-like structure
- Can represent both list and tree data
- Supports sorting and filtering
- Easily extendable for custom data types

### Usage
```cpp
#include <QStandardItemModel>
#include <QStandardItem>

QStandardItemModel *model = new QStandardItemModel(this);
QStandardItem *parentItem = model->invisibleRootItem();

for (int i = 0; i < 4; ++i) {
    QStandardItem *item = new QStandardItem(QString("Item %0").arg(i));
    parentItem->appendRow(item);
    parentItem = item;
}
```

### Best Practices
- Use `setData()` and `data()` for setting and retrieving custom data
- Implement custom roles for storing different types of data per item
- Use `setHeaderData()` to set headers for views

### Tips
- Use `invisibleRootItem()` to access the top-level item
- Implement `setSortRole()` for custom sorting behavior
- Use `setItemPrototype()` to customize item creation

### Important Methods
- `setItem(int row, int column, QStandardItem *item)`: Sets an item at a specific position
- `appendRow(QStandardItem *item)`: Appends a new row with the given item
- `removeRow(int row)`: Removes a row from the model
- `clear()`: Removes all items from the model
- `itemFromIndex(const QModelIndex &index)`: Returns the item for a given model index

</details>

<details>
<summary><strong>QStandardItem</strong></summary>

## Overview
QStandardItem represents a single item in a QStandardItemModel. It can store various types of data and be used to build hierarchical structures.

### Key Features
- Can store text, icons, and custom data
- Supports parent-child relationships for tree structures
- Customizable flags (editable, checkable, etc.)
- Can be subclassed for more complex items

### Usage
```cpp
#include <QStandardItem>

QStandardItem *item = new QStandardItem("My Item");
item->setIcon(QIcon(":/icons/myicon.png"));
item->setData(QVariant(123), Qt::UserRole);
item->setCheckable(true);
item->setEditable(false);
```

### Best Practices
- Use `setData()` with custom roles to store additional information
- Implement `type()` when subclassing for custom item types
- Use `setFlags()` to control item behavior (editable, selectable, etc.)

### Tips
- Use `clone()` to create a copy of an item
- Implement `setAccessibleText()` for accessibility support
- Use `setToolTip()` to provide additional information on hover

### Important Methods
- `setText(const QString &text)`: Sets the display text of the item
- `setIcon(const QIcon &icon)`: Sets the icon for the item
- `setData(const QVariant &value, int role = Qt::UserRole + 1)`: Sets custom data for the item
- `child(int row, int column = 0)`: Returns a child item at the specified position
- `appendRow(QStandardItem *item)`: Appends a child item

</details>

<details>
<summary><strong>QModelIndex</strong></summary>

## Overview
QModelIndex is used to locate data in a data model. It acts as a temporary pointer to a specific piece of information within the model's structure.

### Key Features
- Represents the location of data in model/view architecture
- Lightweight and can be copied efficiently
- Provides row, column, and parent information
- Invalid when the referenced data is no longer available

### Usage
```cpp
#include <QModelIndex>
#include <QAbstractItemModel>

void MyClass::handleIndex(const QModelIndex &index) {
    if (index.isValid()) {
        int row = index.row();
        int column = index.column();
        QVariant data = index.data();
        QModelIndex parent = index.parent();
        // Process the data...
    }
}
```

### Best Practices
- Always check `isValid()` before using a QModelIndex
- Use `model()` to get the associated model when needed
- Don't store QModelIndex objects long-term as they may become invalid

### Tips
- Use `sibling()` to navigate between items at the same level
- Implement `internalPointer()` for custom item pointers in complex models
- Use `child()` to navigate to child items in tree models

### Important Methods
- `row()`: Returns the row of the item
- `column()`: Returns the column of the item
- `parent()`: Returns the parent index
- `data(int role = Qt::DisplayRole)`: Returns the data stored under the given role
- `model()`: Returns a pointer to the model that the index belongs to

</details>


<!--    /////////////////////////////////////////////////////////////// -->
## Layouts

<details>
<summary><strong>QVBoxLayout</strong></summary>

## Overview
QVBoxLayout is a layout that arranges its child widgets vertically in a single column. It's part of Qt's layout system, which automatically resizes and positions widgets based on their size policies and the available space.

### Key Features
- Arranges widgets from top to bottom
- Supports spacing between widgets
- Can be nested with other layouts for complex arrangements
- Automatically adjusts the size of child widgets based on their size policies

### Usage
```cpp
#include <QVBoxLayout>
#include <QPushButton>

QWidget *window = new QWidget;
QVBoxLayout *layout = new QVBoxLayout(window);

QPushButton *button1 = new QPushButton("Button 1");
QPushButton *button2 = new QPushButton("Button 2");
QPushButton *button3 = new QPushButton("Button 3");

layout->addWidget(button1);
layout->addWidget(button2);
layout->addWidget(button3);

window->show();
```

### Best Practices
- Use `addStretch()` to create space between widgets
- Nest QVBoxLayout with other layouts (e.g., QHBoxLayout) for more complex arrangements
- Set size policies on child widgets to control their resizing behavior

### Tips
- Use `setSpacing()` to adjust the spacing between widgets
- Implement `setContentsMargins()` to add margins around the layout
- Call `addLayout()` to add nested layouts

### Important Methods
- `addWidget(QWidget *widget, int stretch = 0, Qt::Alignment alignment = Qt::Alignment())`: Adds a widget to the layout
- `addLayout(QLayout *layout, int stretch = 0)`: Adds a nested layout to the layout
- `addStretch(int stretch = 1)`: Adds a stretch factor to the layout
- `setSpacing(int spacing)`: Sets the spacing between the layout's child widgets
- `setContentsMargins(int left, int top, int right, int bottom)`: Sets the margins around the layout

</details>

<details>
<summary><strong>QFormLayout</strong></summary>

## Overview
QFormLayout is a layout that arranges its child widgets in a two-column form. It's commonly used for creating forms with labeled input fields.

### Key Features
- Arranges widgets in a grid-like layout with labels and fields
- Automatically adjusts the size of labels based on their contents
- Supports spanning fields across multiple columns
- Can be used with various types of input widgets (QLineEdit, QComboBox, etc.)

### Usage
```cpp
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>

QWidget *window = new QWidget;
QFormLayout *layout = new QFormLayout(window);

QLineEdit *nameEdit = new QLineEdit;
QLineEdit *emailEdit = new QLineEdit;

layout->addRow(new QLabel("Name:"), nameEdit);
layout->addRow(new QLabel("Email:"), emailEdit);

window->show();
```

### Best Practices
- Use `addRow()` to add a label-field pair to the form
- Nest QFormLayout with other layouts for more complex arrangements
- Set size policies on child widgets to control their resizing behavior

### Tips
- Use `setFieldGrowthPolicy()` to control how fields resize
- Implement `setLabelAlignment()` to align labels within the form
- Call `addRow(QWidget *label, QWidget *field)` to add a custom label-field pair

### Important Methods
- `addRow(const QString &labelText, QWidget *field)`: Adds a row with a label and a field
- `addRow(QWidget *label, QWidget *field)`: Adds a row with a custom label and a field
- `addRow(QWidget *widget)`: Adds a row with a single widget that spans both columns
- `setFieldGrowthPolicy(FieldGrowthPolicy policy)`: Sets the field growth policy
- `setLabelAlignment(Qt::Alignment alignment)`: Sets the alignment of the labels

</details>

<!--    /////////////////////////////////////////////////////////////// -->

#### Dialogs and Messaging

<details>
<summary><strong>QInputDialog</strong></summary>

## Overview
QInputDialog is a convenience dialog that allows the user to enter a single piece of information, such as a string, number, or item from a list.

### Key Features
- Provides input fields for text, numbers, and lists
- Supports validation and input masking
- Can be used as a modal or modeless dialog
- Emits signals when the user accepts or rejects the dialog

### Usage
```cpp
#include <QInputDialog>

bool ok;
QString name = QInputDialog::getText(this, "Name", "Enter your name:", QLineEdit::Normal, "", &ok);
if (ok && !name.isEmpty()) {
    // Use the entered name
}
```

### Best Practices
- Use static convenience functions for quick input dialogs
- Customize the dialog by creating an instance of QInputDialog
- Connect to `accepted()` and `rejected()` signals for handling user input

### Tips
- Use `setInputMode()` to specify the type of input (text, number, list)
- Implement `setTextValue()`, `setIntValue()`, or `setDoubleValue()` to set initial values
- Use `setComboBoxItems()` to populate a list input dialog

### Important Methods
- `getText(QWidget *parent, const QString &title, const QString &label, QLineEdit::EchoMode echo = QLineEdit::Normal, const QString &text = QString(), bool *ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags(), Qt::InputMethodHints inputMethodHints = Qt::ImhNone)`: Static convenience function to get text input
- `getInt(QWidget *parent, const QString &title, const QString &label, int value = 0, int min = -2147483647, int max = 2147483647, int step = 1, bool *ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())`: Static convenience function to get integer input
- `getDouble(QWidget *parent, const QString &title, const QString &label, double value = 0, double min = -2147483647, double max = 2147483647, int decimals = 1, bool *ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags())`: Static convenience function to get double input
- `getItem(QWidget *parent, const QString &title, const QString &label, const QStringList &items, int current = 0, bool editable = true, bool *ok = nullptr, Qt::WindowFlags flags = Qt::WindowFlags(), Qt::InputMethodHints inputMethodHints = Qt::ImhNone)`: Static convenience function to get an item from a list

</details>

<details>
<summary><strong>QMessageBox</strong></summary>

## Overview
QMessageBox is a dialog for displaying messages, getting user feedback, and displaying critical errors or warnings.

### Key Features
- Provides predefined message boxes (information, warning, critical, question)
- Supports custom buttons and button roles
- Can display rich text and HTML content
- Emits signals when the user interacts with the dialog

### Usage
```cpp
#include <QMessageBox>

QMessageBox::information(this, "Information", "This is an information message.");

int result = QMessageBox::question(this, "Question", "Do you want to continue?", QMessageBox::Yes | QMessageBox::No);
if (result == QMessageBox::Yes) {
    // User answered yes
}
```

### Best Practices
- Use static convenience functions for quick message boxes
- Customize the dialog by creating an instance of QMessageBox
- Connect to `buttonClicked()` signal to handle user interaction

### Tips
- Use `setInformativeText()` to provide additional details
- Implement `setDetailedText()` to show more advanced information
- Use `setIcon()` to set a custom icon for the message box

### Important Methods
- `information(QWidget *parent, const QString &title, const QString &text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton)`: Static convenience function to show an information message box
- `warning(QWidget *parent, const QString &title, const QString &text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton)`: Static convenience function to show a warning message box
- `critical(QWidget *parent, const QString &title, const QString &text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton)`: Static convenience function to show a critical error message box
- `question(QWidget *parent, const QString &title, const QString &text, StandardButtons buttons = StandardButtons(Yes | No), StandardButton defaultButton = NoButton)`: Static convenience function to show a question message box
- `setStandardButtons(StandardButtons buttons)`: Sets the buttons to display in the message box

</details>

<!--    /////////////////////////////////////////////////////////////// -->
## Data structures

<details>
<summary><strong>QIcon</strong></summary>

## Overview
QIcon represents a graphical icon that can be used in various parts of a Qt application, such as buttons, menu items, or window titles.

### Key Features
- Supports different sizes and modes (normal, active, disabled, selected)
- Can load icons from various sources (files, resources, themes)
- Automatically scales icons to fit the desired size
- Provides fallback mechanisms for missing icon sizes

### Usage
```cpp
#include <QIcon>

QIcon icon(":/icons/myicon.png");
QPushButton *button = new QPushButton(icon, "My Button");
```

### Best Practices
- Use `addFile()` to add different sizes of the same icon
- Implement `setThemeName()` and `setThemeSearchPaths()` for themed icons
- Use `actualSize()` to get the appropriate icon size for a given widget

### Tips
- Call `pixmap()` to get a QPixmap representation of the icon
- Use `cacheKey()` to get a unique identifier for the icon
- Implement `setIsMask()` to specify if the icon is a mask

### Important Methods
- `addFile(const QString &fileName, const QSize &size = QSize(), Mode mode = Normal, State state = Off)`: Adds an icon to the pixmap collection
- `pixmap(const QSize &size, Mode mode = Normal, State state = Off)`: Returns a QPixmap representation of the icon
- `actualSize(const QSize &size, Mode mode = Normal, State state = Off)`: Returns the actual size of the icon for the given size, mode, and state
- `cacheKey()`: Returns a unique key identifying the icon

</details>

<details>
<summary><strong>QPixmap</strong></summary>

## Overview
QPixmap is an off-screen image representation that is optimized for drawing. It is commonly used for loading and displaying images in Qt applications.

### Key Features
- Supports various image formats (PNG, JPEG, BMP, etc.)
- Can be created from files, resources, or raw data
- Provides methods for drawing, scaling, and transforming images
- Optimized for fast rendering on the screen

### Usage
```cpp
#include <QPixmap>

QPixmap pixmap(":/images/myimage.png");
QLabel *label = new QLabel;
label->setPixmap(pixmap);
```

### Best Practices
- Use `load()` or `loadFromData()` to load images from files or memory
- Implement `scaled()` to resize the pixmap while maintaining aspect ratio
- Use `copy()` to create a copy of a portion of the pixmap

### Tips
- Call `save()` to save the pixmap to a file
- Use `isNull()` to check if the pixmap is empty
- Implement `toImage()` to convert the pixmap to a QImage

### Important Methods
- `load(const QString &fileName, const char *format = nullptr, Qt::ImageConversionFlags flags = Qt::AutoColor)`: Loads an image from a file
- `loadFromData(const uchar *buf, uint len, const char *format = nullptr, Qt::ImageConversionFlags flags = Qt::AutoColor)`: Loads an image from raw data
- `scaled(const QSize &size, Qt::AspectRatioMode aspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode transformMode = Qt::FastTransformation)`: Returns a scaled copy of the pixmap
- `save(const QString &fileName, const char *format = nullptr, int quality = -1)`: Saves the pixmap to a file
- `toImage()`: Converts the pixmap to a QImage

</details>

<details>
<summary><strong>QDialogButtonBox</strong></summary>

## Overview
QDialogButtonBox is a widget that groups buttons in a dialog following the platform's style guidelines. It provides a convenient way to add standard buttons (OK, Cancel, Apply) to dialogs.

### Key Features
- Automatically arranges buttons based on the platform's layout
- Supports predefined button roles (accept, reject, apply, etc.)
- Can be used with custom buttons or standard buttons
- Provides signals for handling button clicks

### Usage
```cpp
#include <QDialogButtonBox>

QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
connect(buttonBox, &QDialogButtonBox::accepted, this, &MyDialog::accept);
connect(buttonBox, &QDialogButtonBox::rejected, this, &MyDialog::reject);
```

### Best Practices
- Use `addButton()` to add custom buttons to the button box
- Implement `setStandardButtons()` to add predefined buttons
- Connect to `accepted()` and `rejected()` signals for handling button clicks

### Tips
- Call `clear()` to remove all buttons from the button box
- Use `button()` to get a pointer to a specific button
- Implement `setOrientation()` to change the layout direction of the buttons

### Important Methods
- `addButton(QAbstractButton *button, ButtonRole role)`: Adds a custom button to the button box
- `addButton(StandardButton button)`: Adds a predefined standard button to the button box
- `setStandardButtons(StandardButtons buttons)`: Sets the standard buttons to display in the button box
- `button(StandardButton which)`: Returns a pointer to a specific standard button
- `accepted()`: Signal emitted when an accepted button is clicked
- `rejected()`: Signal emitted when a rejected button is clicked

</details>

<details>
<summary><strong>QString</strong></summary>

## Overview
QString is Qt's own string class, designed for easy text manipulation. It provides a wide range of methods for working with strings and supports Unicode characters.

### Key Features
- Provides a rich set of methods for string manipulation
- Supports Unicode characters and encodings
- Optimized for performance and memory usage
- Integrates well with Qt's signals and slots mechanism

### Usage
```cpp
#include <QString>

QString name = "John Doe";
QString uppercaseName = name.toUpper();
QString reversedName = name.reversed();
```

### Best Practices
- Use `arg()` for string interpolation
- Implement `split()` and `join()` for working with string lists
- Use `contains()` and `indexOf()` for searching within strings

### Tips
- Call `isEmpty()` to check if a string is empty
- Use `isNull()` to check if a string is null (uninitialized)
- Implement `toLatin1()`, `toUtf8()`, or `toLocal8Bit()` to convert to a C-style string

### Important Methods
- `length()`: Returns the length of the string
- `isEmpty()`: Returns true if the string is empty
- `isNull()`: Returns true if the string is null (uninitialized)
- `append(const QString &str)`: Appends a string to the end of the string
- `prepend(const QString &str)`: Prepends a string to the beginning of the string
- `insert(int position, const QString &str)`: Inserts a string at the specified position
- `replace(const QString &before, const QString &after)`: Replaces a substring with another string
- `toLower()`: Returns a lowercase copy of the string
- `toUpper()`: Returns an uppercase copy of the string
- `trimmed()`: Returns a copy of the string with leading and trailing whitespace removed

</details>

<details>
<summary><strong>QList</strong></summary>

## Overview
QList is a template class that provides a list data structure. It stores a collection of items and supports various operations for adding, removing, and accessing elements.

### Key Features
- Stores a collection of items of a specific type
- Provides methods for adding, inserting, and removing elements
- Supports random access to elements using indexes
- Optimized for performance and memory usage

### Usage
```cpp
#include <QList>

QList<int> numbers;
numbers.append(1);
numbers.append(2);
numbers.append(3);
int firstNumber = numbers.first();
int lastNumber = numbers.last();
```

### Best Practices
- Use `at()` or `operator[]` for safe random access to elements
- Implement `contains()` to check if a list contains a specific item
- Use `indexOf()` and `lastIndexOf()` to find the index of an item

### Tips
- Call `isEmpty()` to check if a list is empty
- Use `size()` or `count()` to get the number of elements in the list
- Implement `clear()` to remove all elements from the list

### Important Methods
- `append(const T &value)`: Appends an item to the end of the list
- `prepend(const T &value)`: Prepends an item to the beginning of the list
- `insert(int i, const T &value)`: Inserts an item at the specified index
- `removeAt(int i)`: Removes the item at the specified index
- `removeOne(const T &value)`: Removes the first occurrence of the specified item
- `at(int i)`: Returns a reference to the item at the specified index
- `first()`: Returns a reference to the first item in the list
- `last()`: Returns a reference to the last item in the list
- `contains(const T &value)`: Returns true if the list contains the specified item
- `indexOf(const T &value, int from = 0)`: Returns the index of the first occurrence of the specified item
- `lastIndexOf(const T &value, int from = -1)`: Returns the index of the last occurrence of the specified item

</details>


<!--    /////////////////////////////////////////////////////////////// -->



<!--    /////////////////////////////////////////////////////////////// -->



<!--    /////////////////////////////////////////////////////////////// -->



