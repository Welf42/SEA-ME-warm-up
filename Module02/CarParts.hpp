#include <iostream>
#include <string>

//CAR
class Car {
public:
    Car();      // Default constructor (OCF)
                // Copy constructor (OCF)
                // Copy assignment operator (OCF)   
    ~Car();     // Destructor (OCF)
    
    void printParts();

private:    //what is this syntax?
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
};

//PARTS
class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
};

class Engine : public Part {
public:
    void print() override {
        std::cout << "Engine part\n" << std::endl;
    }
};

class Wheel : public Part {
public:
    void print() override {
        std::cout << "Wheel part\n" << std::endl;
    }
};

class Brake : public Part {
public:
    void print() override {
        std::cout << "Brake part\n" << std::endl;
    }
};

class Transmission : public Part {
public:
    void print() override {
        std::cout << "Transmission part\n" << std::endl;
    }
};

class Chassis : public Part {
public:
    void print() override {
        std::cout << "Chassis part\n" << std::endl;
    }
};

class ECU : public Part {
public:
    void print() override {
        std::cout << "ECU part\n" << std::endl;
    }
};