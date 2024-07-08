#include "Car.hpp"

SoftwareDefinedVehicle::SoftwareDefinedVehicle()                    //todo: syntax: 
    : Car("Tesla", "Cybertruck", 2024), softwareVersion("Unknown"), sensors(), actuators()
{
    std::cout << "SoftwareDefinedVehicle class default constructor called." << std::endl;
}

// METHODS ================================================================//
// SDV specific methods
void SoftwareDefinedVehicle::updateSoftware(const std::string& newVersion)
{
    softwareVersion = newVersion;
    std::cout << "SDV has been updated to version " << newVersion << "." << std::endl;
}

void SoftwareDefinedVehicle::addSensor(const std::string& sensor)
{
    sensors.push_back(sensor);                                      //todo: push_back --> add as last element to a vector
    std::cout << sensor << " has been added to SDV parts." << std::endl;
}

void SoftwareDefinedVehicle::addActuator(const std::string& actuator)
{
    actuators.push_back(actuator);
    std::cout << actuator << " has been added to SDV parts." << std::endl;
}

void SoftwareDefinedVehicle::computerVision() const
{
    std::cout << "Using computer vision." << std::endl;
}

void SoftwareDefinedVehicle::infotainment() const
{
    std::cout << "Accessing infotainment." << std::endl;
}


// overwritten car derived functions
void SoftwareDefinedVehicle::accelerate() const
{
    // Car::accelerate();
    std::cout << "Automatic Accelerating." << std::endl;
}

void SoftwareDefinedVehicle::brake() const
{
    // Car::brake();
    std::cout << "Automatic Braking." << std::endl;
}

void SoftwareDefinedVehicle::steer() const
{
    // Car::steer();
    std::cout << "Automatic Steering." << std::endl;
}

