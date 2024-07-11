#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include <vector>
#include <string>

class Part {
public:
    virtual void print() const = 0;
    virtual ~Part() = default;
};

class Engine : public Part {
private:
    std::string type;
    int horsepower;
    double displacement;

public:
    Engine(std::string t, int hp, double disp);
    void print() const override;
};

class Wheel : public Part {
private:
    std::string brand;
    int diameter;

public:
    Wheel(std::string b, int d);
    void print() const override;
};

class Brake : public Part {
private:
    std::string type;
    int diameter;

public:
    Brake(std::string t, int d);
    void print() const override;
};

class Transmission : public Part {
private:
    std::string type;
    int gears;

public:
    Transmission(std::string t, int g);
    void print() const override;
};

class Suspension : public Part {
private:
    std::string type;

public:
    explicit Suspension(std::string t);
    void print() const override;
};

class Body : public Part {
private:
    std::string material;
    double weight;

public:
    Body(std::string m, double w);
    void print() const override;
};

class Car {
private:
    std::string model;
    Engine* engine;
    std::vector<Wheel*> wheels;
    std::vector<Brake*> brakes;
    Transmission* transmission;
    Suspension* suspension;
    Body* body;

public:
    Car(std::string m);
    void printDetails() const;
    ~Car();
};

#endif // CAR_HPP
