#include "Car.hpp"

Engine::Engine(std::string t, int hp, double disp) : type(std::move(t)), horsepower(hp), displacement(disp) {}
void Engine::print() const {
    std::cout << "Engine: " << type << ", " << horsepower << " HP, " << displacement << "L\n";
}

Wheel::Wheel(std::string b, int d) : brand(std::move(b)), diameter(d) {}
void Wheel::print() const {
    std::cout << "Wheel: " << brand << ", " << diameter << " inches\n";
}

Brake::Brake(std::string t, int d) : type(std::move(t)), diameter(d) {}
void Brake::print() const {
    std::cout << "Brake: " << type << ", " << diameter << " mm\n";
}

Transmission::Transmission(std::string t, int g) : type(std::move(t)), gears(g) {}
void Transmission::print() const {
    std::cout << "Transmission: " << type << ", " << gears << " speeds\n";
}

Suspension::Suspension(std::string t) : type(std::move(t)) {}
void Suspension::print() const {
    std::cout << "Suspension: " << type << "\n";
}

Body::Body(std::string m, double w) : material(std::move(m)), weight(w) {}
void Body::print() const {
    std::cout << "Body: " << material << ", " << weight << " kg\n";
}

Car::Car(std::string m) : model(std::move(m)) {
    engine = new Engine("4.0L flat-six", 518, 4.0);
    
    for (int i = 0; i < 4; ++i) {
        wheels.push_back(new Wheel("Michelin Pilot Sport Cup 2", 21));
        brakes.push_back(new Brake("Carbon Ceramic", 410));
    }
    
    transmission = new Transmission("7-speed PDK", 7);
    suspension = new Suspension("Active Suspension Management");
    body = new Body("Carbon Fiber Reinforced Plastic", 1450);
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

Car::~Car() {
    delete engine;
    for (auto wheel : wheels) delete wheel;
    for (auto brake : brakes) delete brake;
    delete transmission;
    delete suspension;
    delete body;
}
