#include <iostream>
#include "PrintHeader.hpp"
#include "Car.hpp"

int main()
{
    printHeader("img/truck_header.txt");

    Car myCar;  //create instance (object) from class Car
    std::cout << "Creating a default Car object." << std::endl;
    myCar.drive();
    myCar.accelerate();
    myCar.steer();
    myCar.brake();
    std::cout << std::endl; //new line

    // create a sportscar object and call a method
    SportsCar myDefaultSportsCar;
    std::cout << "Creating a default SportsCar object." << std::endl;   
    myDefaultSportsCar.drive();
    std::cout << std::endl; //new line

    SportsCar mySpecialSportsCar("Mercedes-Benz", "300 SL", 1956, 237);
    std::cout << "Creating an initialized SportsCar object." << std::endl;
    mySpecialSportsCar.drive();
    std::cout << std::endl; //new line

    // create an SDV instance and call the methods
    SoftwareDefinedVehicle sdv;
    std::cout << "Creating a SoftwareDefinedVehicle object." << std::endl;
    sdv.addSensor("Camera");
    sdv.addSensor("Radar");
    sdv.addActuator("Motor");
    sdv.updateSoftware("3.7.0");
    sdv.drive();
    sdv.accelerate();
    sdv.steer();
    sdv.brake();
    sdv.computerVision();
    sdv.infotainment();

    return (0);
}
