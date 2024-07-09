#include "Car.hpp"

// SportsCar: Default constructor (OCF)
SportsCar::SportsCar()
    : Car("Ferrari", "F40", 1987), topSpeed(367)
{
    std::cout << "SportsCar class default constructor called." << std::endl;
}

// SportsCar: Initialization constructor
SportsCar::SportsCar(const std::string& make, const std::string& model, int year, int topSpeed)
    : Car(make, model, year), topSpeed(topSpeed)
{
    std::cout << "SportsCar class constructor called." << std::endl;
    //print initialization parameters
}

// SportsCar: Copy constructor (OCF)
SportsCar::SportsCar(const SportsCar& other)
    : Car(other), topSpeed(other.topSpeed)
{
    std::cout << "SportsCar class copy constructor called." << std::endl;
}

// SportsCar: Copy assignment operator (OCF) 
SportsCar& SportsCar::operator=(const SportsCar& other)
{
    if (this != &other)
    {
        Car::operator=(other);
        topSpeed = other.topSpeed;
        std::cout << "SportsCar class copy assignment operator called." << std::endl;
    }
    return *this;
}

// SportsCar: Destructor (OCF)
SportsCar::~SportsCar()
{
    std::cout << "SportsCar class destructor called." << std::endl;
}

// METHODS ================================================================//

void SportsCar::drive() const
{
    Car::drive();
    std::cout << "Top speed: " << topSpeed << " km/h" << std::endl;
}
