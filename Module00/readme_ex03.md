# Phonebook Application Documentation

## Libraries Used

### `<iostream>`
- Provides input/output stream functionality.
- Used for console input/output operations.

### `<vector>`
- Provides dynamic array functionality.
- Used to store contacts and bookmarks.

### `<string>`
- Provides string manipulation functionality.
- Used for storing and handling text data.

### `<algorithm>`
- Provides various algorithms for data manipulation.
- Used for searching and modifying data in vectors.

### `<stdexcept>`
- Provides standard exception classes.
- Used for throwing and handling exceptions.

### `<limits>`
- Provides constants for numeric limits.
- Used for input stream manipulation.

## Classes

### `Contact`
Represents a single contact with properties:
- `name`: string
- `phoneNumber`: string
- `nickname`: string

### `Phonebook`
Manages a collection of contacts with various operations.

#### Public Methods:
- `addContact(name, phoneNumber, nickname)`: Adds a new contact.
- `searchContacts()`: Allows searching and interacting with contacts.
- `removeContact()`: Removes a contact by name or phone number.
- `displayBookmarkedContacts()`: Shows bookmarked contacts.
- `listContacts()`: Lists all contacts.
- `displayContactDetails(index)`: Shows details of a specific contact.

#### Private Methods:
- `isPhoneNumberUnique(phoneNumber)`: Checks if a phone number is unique.
- `bookmarkContact(index)`: Bookmarks a contact.
- `removeContactByName(name)`: Removes a contact by name.
- `removeContactByNumber(phoneNumber)`: Removes a contact by phone number.

## Functions and Methods Used

### Standard Library Functions:
- `std::cout`: Output stream object.
- `std::cin`: Input stream object.
- `std::cin.ignore()`: Ignores characters in the input buffer.
- `std::cin.clear()`: Clears the error state of the input stream.
- `std::numeric_limits<std::streamsize>::max()`: Returns the maximum value for streamsize.

### Vector Operations:
- `vector.push_back()`: Adds an element to the end of the vector.
- `vector.begin()`: Returns an iterator to the beginning of the vector.
- `vector.end()`: Returns an iterator to the end of the vector.
- `vector.erase()`: Removes an element from the vector.
- `vector.size()`: Returns the number of elements in the vector.

### Algorithm Functions:
- `std::find_if()`: Searches for an element satisfying a condition.
- `std::none_of()`: Checks if no elements satisfy a condition.

### Exception Handling:
- `throw std::runtime_error()`: Throws a runtime error exception.
- `throw std::out_of_range()`: Throws an out of range exception.

## Main Function
The `main()` function implements a command loop that interacts with the user and calls appropriate Phonebook methods based on user input.

