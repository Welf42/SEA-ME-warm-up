// Module 00 Exercise 00
// Basics of handling strings

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    size_t      i;
    std::string command;
    std::string str;

    // check input
    if (argc < 3)
    {
        std::cout << "Usage: ./convert {command} {string}" << std::endl;
        std::cout << "Command can be 'up' or 'down'!" << std::endl;
        return 1;
    }

    command = argv[1];

    // concatenate all arguments starting from argv[2]
    for (int j = 2; j < argc; j++) {
        str += argv[j];
        if (j < argc - 1) {
            str += " ";
        }
    }

    // modify the string to uppercase or lowercase
    i = 0;
    if (command == "up")
    {
        while (i < str.length()) 
        {
            if (std::islower(str[i]))
                str[i] = std::toupper(str[i]);
            ++i;
        }
    }
    else if (command == "down")
    {
        while (i < str.length())
        {
            if (std::isupper(str[i]))
                str[i] = std::tolower(str[i]);
            ++i;
        }
    } 
    else
    {
        std::cout << "Invalid command: " << command << std::endl;
        return (1);
    }

    // print result
    std::cout << str << std::endl;
    return (0);
}
