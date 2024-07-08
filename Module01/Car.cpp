#include "Car.hpp"

// Car: Default constructor (OCF)	
Car::Car()          //syntax: Class::Method:                                                       
    : make("VW"), model("Beetle"), year(1960)
{
    std::cout << "Car class default constructor called." << std::endl;
}

// Car: Initialization constructor
Car::Car(const std::string& make, const std::string& model, int year)
    : make(make), model(model), year(year) {
    std::cout << "Car class constructor called." << std::endl;
}

// Copy constructor (OCF)
Car::Car(const Car& other)
    : make(other.make), model(other.model), year(other.year)
{
    std::cout << "Car class copy constructor called." << std::endl;
}

// Copy assignment operator (OCF) 
Car& Car::operator=(const Car& other)
{
    if (this != &other) {
        make = other.make;
        model = other.model;
        year = other.year;
        std::cout << "Car class copy assignment operator called." << std::endl;
    }
    return *this;
}

// Destructor (OCF)
Car::~Car()
{
    std::cout << "Car class destructor called." << std::endl;
}

// METHODS ================================================================//

void Car::drive() const             //syntax: void Class::method() const
{
    std::cout << "Driving " << make << " " << model << " (" << year << ") edition." << std::endl;
}

void Car::accelerate() const
{
    std::cout << "Accelerating the " << make << " " << model << "." << std::endl;
}

void Car::brake() const
{
    std::cout << "Braking the " << make << " " << model << "." << std::endl;
}

void Car::steer() const
{
    std::cout << "Steering the " << make << " " << model << "." << std::endl;
}
