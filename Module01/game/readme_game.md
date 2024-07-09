# Car Racing Game Documentation

## Table of Contents
1. [Introduction](#introduction)
2. [Key Concepts and Syntax](#key-concepts-and-syntax)
3. [Game Structure](#game-structure)
4. [Function Descriptions](#function-descriptions)
5. [Gameplay](#gameplay)

## Introduction

This document provides an overview of the Car Racing Game, a C++ console application that simulates creating and racing different types of cars. The game utilizes object-oriented programming concepts and modern C++ features to create an interactive and extensible racing simulation.

## Key Concepts and Syntax

### Template Functions

The game uses template functions for flexible input handling:

```cpp
template<typename T>
T getInput(const std::string& prompt) {
    T value;
    std::cout << prompt;
    std::cin >> value;
    return value;
}
```

This template function allows for type-safe input of various data types. The `typename T` syntax defines a template type parameter, allowing the function to work with different data types.

### Smart Pointers

The game extensively uses `std::unique_ptr` for memory management:

```cpp
std::unique_ptr<Car> createCar() {
    // ...
    return std::make_unique<Car>(/* ... */);
}
```

`std::unique_ptr` is a smart pointer that owns and manages another object through a pointer and disposes of that object when the `unique_ptr` goes out of scope. `std::make_unique<T>()` is a helper function that creates a `unique_ptr` instance of type T.

### Dynamic Casting

The game uses dynamic casting to safely convert between pointer types:

```cpp
if (dynamic_cast<SportsCar*>(car.get())) {
    // ...
}
```

`dynamic_cast` is used for safe downcasting in inheritance hierarchies. It returns a null pointer if the cast is not possible, allowing for runtime type checking.

### Random Number Generation

The game uses modern C++ random number generation facilities:

```cpp
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> speedChange(10, 30);
```

`std::random_device` provides a source of randomness, `std::mt19937` is a Mersenne Twister random number engine, and `std::uniform_int_distribution` generates random integers in a uniform distribution.

## Game Structure

The game is structured around several key classes:

1. `Car`: Base class for all vehicles
2. `SportsCar`: Derived from `Car`, represents high-performance vehicles
3. `SoftwareDefinedVehicle`: Derived from `Car`, represents autonomous vehicles

The main game logic is contained in the `playGame` function, which simulates the racing experience.

## Function Descriptions

### createCar()

This function creates a new car based on user input:

```cpp
std::unique_ptr<Car> createCar() {
    std::string type = getInput<std::string>("Enter car type (CAR/SPORT/SDV): ");
    // ...
    if (type == "CAR") {
        return std::make_unique<Car>(customOrDefault == "C" ? Car(make, model, year) : Car());
    } else if (type == "SPORT") {
        // ...
    }
    // ...
}
```

It uses conditional statements to determine which type of car to create and returns a `unique_ptr` to the appropriate car type.

### upgradeCar()

This function allows for upgrading specific car types:

```cpp
void upgradeCar(std::unique_ptr<Car>& car) {
    if (dynamic_cast<SportsCar*>(car.get())) {
        // Upgrade SportsCar
    } else if (dynamic_cast<SoftwareDefinedVehicle*>(car.get())) {
        // Upgrade SoftwareDefinedVehicle
    }
    // ...
}
```

It uses dynamic casting to determine the specific car type and applies the appropriate upgrade.

### playGame()

The main game loop is contained in this function:

```cpp
void playGame(std::unique_ptr<Car>& car) {
    bool isSDV = dynamic_cast<SoftwareDefinedVehicle*>(car.get()) != nullptr;
    // ...
    while (mileage < trackLength) {
        // Game logic
    }
}
```

It manages the game state, processes user input (or autonomous decisions for SDVs), and updates the car's position and speed.

## Gameplay

The game flow is as follows:

1. The player creates a car, choosing between different types and customization options.
2. The player can choose to upgrade their car.
3. The racing game begins, where the player can input commands to control their car.
4. For Software Defined Vehicles, there's an option for autonomous driving.
5. The game continues until the car reaches the end of the track.

Throughout the game, object-oriented principles like inheritance and polymorphism are utilized to manage different car types and behaviors.
```

This documentation provides an overview of the game's structure, key C++ concepts used, and detailed explanations of the main functions and gameplay. It highlights the use of templates, smart pointers, dynamic casting, and random number generation, which are crucial to the game's implementation.