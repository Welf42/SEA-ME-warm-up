// phonebook.cpp

#include "phonebook.hpp"
#include <limits> // std::cin.ignore, std::cin.clear

int main() {
    Phonebook phonebook;
    std::string command;

    std::cout << "Phonebook\n";

    while (true) {
        std::cout << "\nEnter a command (ADD, SEARCH, REMOVE, BOOKMARK, LIST, EXIT): ";
        std::cin >> command;

        try {
            if (command == "ADD") {
                std::string name, number, nickname;
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter number: ";
                std::cin >> number;
                std::cout << "Enter nickname: ";
                std::cin >> nickname;
                phonebook.addContact(name, number, nickname);
                std::cout << "Contact added successfully.\n";
            }
            else if (command == "SEARCH") {
                phonebook.searchContacts();
            }
			else if (command == "REMOVE") {
				if (phonebook.removeContact())  // No argument needed here
					std::cout << "Contact removed successfully.\n";
				else
					std::cout << "Contact not found or removal failed.\n";
			}
            else if (command == "BOOKMARK") {
                phonebook.displayBookmarkedContacts();
            }
            else if (command == "LIST") {
                phonebook.listContacts();
            }
            else if (command == "EXIT") {
                std::cout << "Goodbye!\n";
                break;
            }
            else {
                std::cout << "Invalid command. Please try again.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        // Clear any error flags and remaining input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
