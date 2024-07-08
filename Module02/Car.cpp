#include "CarParts.hpp"

class Car {
public:
    Car() {
        engine_ = new Engine();
        wheels_ = new Wheel[4];
        brakes_ = new Brake[4];
        transmission_ = new Transmission();
    }
    
    void printParts() {
        engine_->print();
        for (int i = 0; i < 4; ++i) {
            wheels_[i].print();
            brakes_[i].print();
        }
        transmission_->print();
    }
    
    ~Car() {
        delete engine_;
        delete [] wheels_;
        delete [] brakes_;
        delete transmission_;
    }
    
private:
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
};