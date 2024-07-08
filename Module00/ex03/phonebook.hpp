// phonebook.hpp

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>          // functions: std::cout, std::cin, std::endl
#include <vector>            // functions: vector::push_back, vector::begin, vector::end, vector::size, vector::erase
#include <string>            // functions: string operations
#include <algorithm>         // functions: std::find_if, std::none_of
#include <stdexcept>         // functions: std::runtime_error, std::out_of_range

class Contact {
public:
    std::string name;
    std::string phoneNumber;
    std::string nickname;
};

class Phonebook
{
private:                            // class variables should be private when possible
    std::vector<Contact> contacts;  // phonebook is a vector of the contacts
    std::vector<size_t> bookmarks;  // bookmarks is a vector of indices 

public:                             // public functions are callable from outside the class
    void addContact(const std::string& name, const std::string& phoneNumber, const std::string& nickname) {
        if (isPhoneNumberUnique(phoneNumber)) {
            Contact newContact{name, phoneNumber, nickname};
            contacts.push_back(newContact);  // vector::push_back to add a new contact
        } else {
            throw std::runtime_error("Phone number already exists.");   // std::runtime_error to throw an exception
        }
    }

    void searchContacts() {
        listContacts();
        std::cout << "Enter 'D' for details, 'B' to bookmark, or 'Q' to quit: ";
        std::string input;
        std::cin >> input;  // std::cin to get user input

        if (input == "D") {
            size_t index;
            std::cout << "Enter index for contact details: ";
            std::cin >> index;
            displayContactDetails(index);
        } else if (input == "B") {
            size_t index;
            std::cout << "Enter index to bookmark: ";
            std::cin >> index;
            bookmarkContact(index);
        } else if (input == "Q") {
            return;
        } else {
            std::cout << "Invalid input." << std::endl;
        }
    }

    bool removeContact() {
        std::cout << "Remove contact by:\n";
        std::cout << "[0] Name\n";
        std::cout << "[1] Phone Number\n";
        std::cout << "Enter your choice (0 or 1): ";
        int choice;
        std::cin >> choice;

        std::string identifier;
        if (choice == 0) {
            std::cout << "Enter name to remove: ";
            std::cin >> identifier;
            return removeContactByName(identifier);
        } else if (choice == 1) {
            std::cout << "Enter phone number to remove: ";
            std::cin >> identifier;
            return removeContactByNumber(identifier);
        } else {
            std::cout << "Invalid choice.\n";
            return false;
        }
    }

    bool removeContactByName(const std::string& name)
    {
        auto it = std::find_if(contacts.begin(), contacts.end(),        // std::find_if to search for a contact
            [&name](const Contact& c) { return c.name == name; });      // vector::begin() and vector::end() to specify range
        
        if (it != contacts.end()) {
            contacts.erase(it);                                         // vector::erase to remove the contact
            return true;
        }
        return false;
    }

    bool removeContactByNumber(const std::string& phoneNumber)
    {
        auto it = std::find_if(contacts.begin(), contacts.end(),        // std::find_if to search for a contact
            [&phoneNumber](const Contact& c)
            {
                return c.phoneNumber == phoneNumber;
            });

        if (it != contacts.end()) {
            contacts.erase(it);                                         // vector::erase to remove the contact
            return true;
        }
        return false;
    }

   void displayBookmarkedContacts() const {
        for (size_t index : bookmarks) {                // Range-based for loop
            if (index < contacts.size()) {              // vector::size() to get the number of contacts
                std::cout << "Index: " << index << ", Name: " << contacts[index].name << std::endl;
            } else {
                std::cout << "Invalid bookmark index: " << index << std::endl;
            }
        }
    }

    void listContacts() const {
        for (size_t i = 0; i < contacts.size(); i++) {  // vector::size() to get the number of contacts
            std::cout << "Index: " << i << ", Name: " << contacts[i].name << std::endl;
        }
    }

    void displayContactDetails(size_t index) const {
        if (index < contacts.size()) {                                              // vector::size() to check if index is valid
            const auto& contact = contacts[index];                                  // Using auto for type inference
            std::cout << "Name: " << contact.name << std::endl;
            std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
            std::cout << "Nickname: " << contact.nickname << std::endl;
        } else {
            throw std::out_of_range("Invalid index.");                              // std::out_of_range to throw an exception
        }
    }

private:    //private methods are accessible only from within the class
    // function to check if phone number is already in phonebook
    bool isPhoneNumberUnique(const std::string& phoneNumber) const {
        return std::none_of(contacts.begin(), contacts.end(),                       // std::none_of to check if no contacts match
            [&phoneNumber](const Contact& c) { return c.phoneNumber == phoneNumber; });
    }

    void bookmarkContact(size_t index)
    {
        if (index < contacts.size()) {
            bookmarks.push_back(index);                                                     // vector::push_back to add a bookmark
            std::cout << "Contact " << contacts[index].name << " bookmarked." << std::endl;
        } else {
            throw std::out_of_range("Invalid index.");                                      // std::out_of_range to throw an exception
        }
    }
};

#endif // PHONEBOOK_HPP
