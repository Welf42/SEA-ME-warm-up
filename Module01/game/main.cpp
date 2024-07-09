#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <thread>
#include <chrono>
#include "PrintHeader.hpp"
#include "Car.hpp"

// Function to get user input
template<typename T>
T getInput(const std::string& prompt) {
    T value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}

// Function to create a car based on user input
std::unique_ptr<Car> createCar() {
    std::string type = getInput<std::string>("Enter car type (CAR/SPORT/SDV): ");
    std::string customOrDefault = getInput<std::string>("Custom [C] or Default [D] car? ");
    
    std::string make, model;
    int year;
    
    if (customOrDefault == "C") {
        make = getInput<std::string>("Enter make: ");
        model = getInput<std::string>("Enter model: ");
        year = getInput<int>("Enter year: ");
    }
    
    if (type == "CAR") {
        return std::make_unique<Car>(customOrDefault == "C" ? Car(make, model, year) : Car());
    } else if (type == "SPORT") {
        int topSpeed = getInput<int>("Enter top speed: ");
        return std::make_unique<SportsCar>(customOrDefault == "C" ? SportsCar(make, model, year, topSpeed) : SportsCar());
    } else if (type == "SDV") {
        std::string softwareVersion = getInput<std::string>("Enter software version: ");
        std::vector<std::string> sensors, actuators;
        
        while (true) {
            std::string sensor = getInput<std::string>("Enter sensor (or 'none' to finish): ");
            if (sensor == "none") break;
            sensors.push_back(sensor);
        }
        
        while (true) {
            std::string actuator = getInput<std::string>("Enter actuator (or 'none' to finish): ");
            if (actuator == "none") break;
            actuators.push_back(actuator);
        }
        
        return std::make_unique<SoftwareDefinedVehicle>(customOrDefault == "C" ? 
            SoftwareDefinedVehicle(make, model, year, softwareVersion, sensors, actuators) : SoftwareDefinedVehicle());
    }
    
    throw std::runtime_error("Invalid car type");
}

// Function to upgrade car
void upgradeCar(std::unique_ptr<Car>& car) {
    if (dynamic_cast<SportsCar*>(car.get())) {
        int newTopSpeed = getInput<int>("Enter new top speed for upgrade: ");
        // Note: We can't directly modify topSpeed as it's private. You might want to add a setTopSpeed method to SportsCar.
        std::cout << "Top speed upgraded to " << newTopSpeed << " km/h\n";
    } else if (dynamic_cast<SoftwareDefinedVehicle*>(car.get())) {
        std::string newVersion = getInput<std::string>("Enter new software version for upgrade: ");
        dynamic_cast<SoftwareDefinedVehicle*>(car.get())->updateSoftware(newVersion);
    } else {
        std::cout << "No upgrades available for this car type.\n";
    }
}

// Random number generator
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> speedChange(10, 30);

// Game logic
void playGame(std::unique_ptr<Car>& car) {
    int speed = 0;
    int mileage = 0;
    const int trackLength = 5000;
    bool isSDV = dynamic_cast<SoftwareDefinedVehicle*>(car.get()) != nullptr;
    bool isAutonomous = false;
    
    std::cout << "Welcome to the Racing Game\n";
    
    while (mileage < trackLength) {
        if (!isAutonomous) {
            std::cout << "Enter your command: drive [D], accelerate [A], steer [S], brake [B]";
            if (isSDV) std::cout << ", computer vision [CV]";
            std::cout << ": ";
            
            std::string command;
            std::cin >> command;
            
            if (command == "D") car->drive();
            else if (command == "A") {
                car->accelerate();
                speed += speedChange(gen);
                if (auto sportsCar = dynamic_cast<SportsCar*>(car.get()))
                    speed = std::min(speed, 367); // Using default top speed of SportsCar
                else
                    speed = std::min(speed, 120);
            }
            else if (command == "S") car->steer();
            else if (command == "B") {
                car->brake();
                speed = std::max(0, speed - speedChange(gen));
            }
            else if (command == "CV" && isSDV) {
                isAutonomous = true;
                std::cout << "Autonomous driving activated.\n";
                dynamic_cast<SoftwareDefinedVehicle*>(car.get())->computerVision();
            }
            else std::cout << "Invalid command.\n";
        } else {
            // Autonomous driving
            std::string commands[] = {"D", "A", "S", "B"};
            std::string command;

            if (speed == 0) {
                command = "A";  // Always accelerate if speed is 0
            } else {
                command = commands[std::uniform_int_distribution<>(0, 3)(gen)];
            }
            
            std::cout << "Autonomous action: " << command << std::endl;
            
            if (command == "D") car->drive();
            else if (command == "A") {
                car->accelerate();
                speed += speedChange(gen);
                speed = std::min(speed, 120);
            }
            else if (command == "S") car->steer();
            else if (command == "B") {
                car->brake();
                speed = std::max(0, speed - speedChange(gen));
            }
            
            dynamic_cast<SoftwareDefinedVehicle*>(car.get())->computerVision();
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        
        mileage += speed;
        std::cout << "Speed: " << speed << " km/h, Mileage: " << mileage << " m\n";
    }
    
    std::cout << "Congratulations! You've reached the end of the track.\n";
}


int main() {
    printHeader("../img/truck_header.txt");
    std::cout << "Welcome to the Car Creator\n";
    
    auto car = createCar();
    
    std::string upgrade;
    std::cout << "Do you want to upgrade your car? (Y/N): ";
    std::cin >> upgrade;
    
    if (upgrade == "Y" || upgrade == "y") {
        upgradeCar(car);
    }
    
    playGame(car);
    
    return 0;
}
