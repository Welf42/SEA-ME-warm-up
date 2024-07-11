# Phonebook Application Documentation

## Qt Classes and Libraries Used

### Core Qt Classes
- **QMainWindow**: Main application window class.
- **QDialog**: Base class for dialog windows.
- **QWidget**: Base class for all user interface objects.
- **QObject**: Base class for all Qt objects.

### GUI Components
- **QListView**: Widget that displays a list of items.
- **QTextBrowser**: Rich text browser with hypertext navigation.
- **QLineEdit**: Widget for entering and editing a single line of plain text.
- **QPushButton**: Command button.
- **QLabel**: Text or image display.

### Models and Data
- **QStandardItemModel**: Item model for use with views and delegates.
- **QStandardItem**: Item for use with QStandardItemModel.
- **QModelIndex**: Used to locate data in data models.

### Layouts
- **QVBoxLayout**: Vertical box layout.
- **QFormLayout**: Manages forms of input widgets and their labels.

### Dialogs and Messaging
- **QInputDialog**: Simple convenience dialog to get a single value from the user.
- **QMessageBox**: Modal dialog for informing the user or asking simple questions.

### Other Qt Classes
- **QIcon**: Scalable icons in different modes and states.
- **QPixmap**: Off-screen image representation for displaying images.
- **QDialogButtonBox**: Widget that presents buttons in a layout.

## Custom Classes

### AddContactDialog
Inherits from QDialog. Used for adding new contacts.

#### Methods:
- `AddContactDialog(QWidget *parent = nullptr)`: Constructor.
- `getName() const`: Returns the entered name.
- `getNickname() const`: Returns the entered nickname.
- `getPhoneNumber() const`: Returns the entered phone number.

### Phonebook
Inherits from QMainWindow. Main class for the phonebook application.

#### Methods:
- `Phonebook(QWidget *parent = nullptr)`: Constructor.
- `~Phonebook()`: Destructor.

#### Private Slots:
- `on_pushButton_add_clicked()`: Handles add button click.
- `on_pushButton_bookmark_clicked()`: Handles bookmark button click.
- `on_pushButton_details_clicked()`: Handles details button click.
- `on_pushButton_remove_clicked()`: Handles remove button click.
- `on_pushButton_allContacts_clicked()`: Displays all contacts.
- `on_pushButton_bookmarks_clicked()`: Displays bookmarked contacts.
- `on_lineEdit_filter_textChanged(const QString &text)`: Handles filter text changes.
- `on_listView_contact_clicked(const QModelIndex &index)`: Handles contact list item click.

#### Private Methods:
- `updateContactList(bool bookmarksOnly = false, const QString& filter = QString())`: Updates the contact list view.
- `displayContactDetails(const QModelIndex &index)`: Displays details of a selected contact.
- `updateBookmarkStatus(const QModelIndex &index, bool isBookmarked)`: Updates bookmark status of a contact.
- `loadSampleContacts()`: Loads sample contacts into the phonebook.
- `addContact(const QString &name, const QString &nickname, const QString &number, bool isBookmarked)`: Adds a new contact.
- `findItemInAllContacts(const QStandardItem* item)`: Finds a contact in the all contacts list.
- `isValidName(const QString &name) const`: Validates a name.
- `isValidPhoneNumber(const QString &number) const`: Validates a phone number.
- `isDuplicatePhoneNumber(const QString &number) const`: Checks for duplicate phone numbers.

## Other Libraries and Functions

### Standard C++ Libraries
- `<QString>`: Qt's string class.
- `<QList>`: Qt's template-based container class.

### Regular Expressions
- `QRegularExpression`: Used for pattern matching and validation.

This documentation provides an overview of the Qt classes, custom classes, and their methods used in the Phonebook application code, with emphasis on the Qt components.
