#ifndef PRINTHEADER_HPP
# define PRINTHEADER_HPP

#include <fstream>
#include <iostream>

void printHeader(std::string path)
{
    // std::ifstream headerFile("img/seame_header.txt");
    // std::ifstream headerFile("../img/truck_header.txt");
    // std::ifstream headerFile("img/header.txt");
    std::ifstream headerFile(path);
    
    if (!headerFile.is_open())
    {
        std::cerr << "Error: Unable to open header file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(headerFile, line))
    {
        std::cout << line << std::endl;
    }
    headerFile.close();
}
#endif // CAR_HPP

