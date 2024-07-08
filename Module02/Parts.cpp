#include "CarParts.hpp"

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
};

class Engine : public Part {
public:
    void print() override {
        std::cout << "Engine part\n";
    }
};

class Wheel : public Part {
public:
    void print() override {
        std::cout << "Wheel part\n";
    }
};

class Brake : public Part {
public:
    void print() override {
        std::cout << "Brake part\n";
    }
};

class Transmission : public Part {
public:
    void print() override {
        std::cout << "Transmission part\n" << std::endl;
    }
};
