// phonebook.hpp

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>          // functions: 
#include <vector>            // functions: 
#include <string>            // functions: 
#include <algorithm>         // functions: 
#include <stdexcept>         // functions: 

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
    std::vector<size_t> bookmarks;  // bookmarks is a vector of indeces 

public:                             // public functions are callable from outside the class
    void addContact(const std::string& name, const std::string& phoneNumber, const std::string& nickname) {
        if (isPhoneNumberUnique(phoneNumber)) {
            Contact newContact{name, phoneNumber, nickname};
            contacts.push_back(newContact);
        } else {
            throw std::runtime_error("Phone number already exists.");   //
        }
    }

    void searchContacts() {
        listContacts();
        std::cout << "Enter 'D' for details, 'B' to bookmark, or 'Q' to quit: ";
        std::string input;
        std::cin >> input;

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
        auto it = std::find_if(contacts.begin(), contacts.end(),        //todo: auto
            [&name](const Contact& c) { return c.name == name; });      //todo: vector.begin()
                                                                        //todo: vector.end()
        if (it != contacts.end()) {
            contacts.erase(it);                                         //todo: erase
            return true;
        }
        return false;
    }

    bool removeContactByNumber(const std::string& phoneNumber)
    {
        auto it = std::find_if(contacts.begin(), contacts.end(),        //todo: find_if
            [&phoneNumber](const Contact& c)
            {
                return c.phoneNumber == phoneNumber;
            });

        if (it != contacts.end()) {
            contacts.erase(it);                                         //todo: erase
            return true;
        }
        return false;
    }

   void displayBookmarkedContacts() const {
        for (size_t index : bookmarks) {                //bookmark is a vector of indexes
            if (index < contacts.size()) {
                std::cout << "Index: " << index << ", Name: " << contacts[index].name << std::endl;
            } else {
                std::cout << "Invalid bookmark index: " << index << std::endl;
            }
        }
    }

    void listContacts() const {
        for (size_t i = 0; i < contacts.size(); i++) {
            std::cout << "Index: " << i << ", Name: " << contacts[i].name << std::endl;
        }
    }

    void displayContactDetails(size_t index) const {
        if (index < contacts.size()) {                                              //size: 
            const auto& contact = contacts[index];                                  //todo: get syntax right
            std::cout << "Name: " << contact.name << std::endl;
            std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
            std::cout << "Nickname: " << contact.nickname << std::endl;
        } else {
            throw std::out_of_range("Invalid index.");                              //todo: throw:
        }                                                                           //todo: out_of_range:
    }

private:    //private methods are accessable only from within the class
    // function to check if phone number is already in phonebook
    bool isPhoneNumberUnique(const std::string& phoneNumber) const {
        return std::none_of(contacts.begin(), contacts.end(),                       //todo: none_of:
            [&phoneNumber](const Contact& c) { return c.phoneNumber == phoneNumber; });
    }


    void bookmarkContact(size_t index)
    {
        if (index < contacts.size()) {
            bookmarks.push_back(index);                                                     //todo: push_back
            std::cout << "Contact " << contacts[index].name << " bookmarked." << std::endl;
        } else {
            throw std::out_of_range("Invalid index.");                                      //todo: throw
        }                                                                                   //todo: out_of_range
    }
};

#endif // PHONEBOOK_HPP
