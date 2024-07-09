#include "Car.hpp"

// SDV: Default constructor (OCF)
SoftwareDefinedVehicle::SoftwareDefinedVehicle()
    : Car("Tesla", "Cybertruck", 2024), softwareVersion("Unknown"), sensors(), actuators()
{
    std::cout << "SoftwareDefinedVehicle class default constructor called." << std::endl;
}

// SDV: Initialization constructor
SoftwareDefinedVehicle::SoftwareDefinedVehicle(const std::string& make, const std::string& model, int year, 
                    const std::string &softwareVersion, const std::vector<std::string> &sensors, const std::vector<std::string> &actuators)
                    : Car(make, model, year), softwareVersion(softwareVersion), sensors(sensors), actuators(actuators)
{
    std::cout << "SoftwareDefinedVehicle class constructor called." << std::endl;
    //print initialization parameters
}

// SDV: Copy constructor (OCF)
SoftwareDefinedVehicle::SoftwareDefinedVehicle(const SoftwareDefinedVehicle& other)
    : Car(other), softwareVersion(other.softwareVersion), sensors(other.sensors), actuators(other.actuators)
{
    std::cout << "SoftwareDefinedVehicle class copy constructor called." << std::endl;
}

// SDV: Copy assignment operator (OCF)         
SoftwareDefinedVehicle& SoftwareDefinedVehicle::operator=(const SoftwareDefinedVehicle& other)
{
    if (this != &other)
    {
        Car::operator=(other);
        softwareVersion = other.softwareVersion;
        sensors = other.sensors;
        actuators = other.actuators;
        std::cout << "SoftwareDefinedVehicle class copy assignment operator called." << std::endl;
    }
    return *this;
}

// SDV: Destructor (OCF)
SoftwareDefinedVehicle::~SoftwareDefinedVehicle()
{
    std::cout << "SoftwareDefinedVehicle class destructor called." << std::endl;
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
    sensors.push_back(sensor);
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


// override car derived functions
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

