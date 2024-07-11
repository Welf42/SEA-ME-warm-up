#include "Car.hpp"

Car::Car(std::string m) : model(std::move(m)) {
    // Initialize Porsche 911 GT3 RS parts
    engine = std::make_unique<Engine>("4.0L flat-six", 518, 4.0);
    
    for (int i = 0; i < 4; ++i) {
        wheels.push_back(std::make_unique<Wheel>("Michelin Pilot Sport Cup 2", 21));
        brakes.push_back(std::make_unique<Brake>("Carbon Ceramic", 410));
    }
    
    transmission = std::make_unique<Transmission>("7-speed PDK", 7);
    suspension = std::make_unique<Suspension>("Active Suspension Management");
    body = std::make_unique<Body>("Carbon Fiber Reinforced Plastic", 1450);
}

void Car::printDetails() const {
    std::cout << "Porsche " << model << " Details:\n";
    std::cout << "------------------------\n";
    engine->print();
    for (size_t i = 0; i < wheels.size(); ++i) {
        std::cout << "Wheel " << i+1 << ": ";
        wheels[i]->print();
        std::cout << "Brake " << i+1 << ": ";
        brakes[i]->print();
    }
    transmission->print();
    suspension->print();
    body->print();
}
