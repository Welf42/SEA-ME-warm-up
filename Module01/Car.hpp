// You define virtual, overwrite, etc. only here

#ifndef CAR_HPP
# define CAR_HPP

# include <iostream>
# include <string>
# include <vector>

// Car class 
class Car
{
protected:		//todo:
    std::string make;
    std::string model;
    int year;

public:			//todo:
    Car();								                                // Default constructor (OCF)
    Car(const std::string& make, const std::string& model, int year);	// Initalization constructor
    Car(const Car& other);						                        // Copy constructor (OCF)
    Car& operator=(const Car& other);			                        // Copy assignment operator (OCF)                
    virtual ~Car();                                                     // Destructor (OCF)

    virtual void drive() const;                 //todo: virtual 
    virtual void accelerate() const;            //todo: syntax: virtual void <function> const
    virtual void brake() const;
    virtual void steer() const;
    // virtual void computerVision() const;
    // virtual void infotainment() const;
};

// class SportsCar derived from Class Car
class SportsCar : public Car
{
private:
    int topSpeed;

public:
    SportsCar();			                                                                    // Default constructor (OCF)					
    SportsCar(const std::string& make, const std::string& model, int year, int topSpeed);       // Initalization constructor
    SportsCar(const SportsCar& other);                                                          // Copy constructor (OCF)
    SportsCar& operator=(const SportsCar& other);                                               // Copy assignment operator (OCF) 
    ~SportsCar();                                                                               // Destructor (OCF)

    void drive() const override;                //todo: synta: void <function> const overridex
};

// class SoftwareDefinedVehicle derived from Class Car
class SoftwareDefinedVehicle : public Car
{
private:
    std::string                 softwareVersion;    //
    std::vector<std::string>    sensors;            // todo: syntax: vector of strings
    std::vector<std::string>    actuators;          

public:
    SoftwareDefinedVehicle();                       // Default constructor (OCF)
    // SoftwareDefinedVehicle(const std::string& make, const std::string& model, int year, 
    //                         const std::string &softwareVersion, const std::vector<std::string> &sensors, const std::vector<std::string> &actuators);// Initalization constructor
    // SoftwareDefinedVehicle(const SoftwareDefinedVehicle& other);                                                          // Copy constructor (OCF)
    // SoftwareDefinedVehicle& operator=(const SoftwareDefinedVehicle& other);                                               // Copy assignment operator (OCF) 
    // ~SoftwareDefinedVehicle();                                                                               // Destructor (OCF)

    void updateSoftware(const std::string& newVersion);
    void addSensor(const std::string& sensor);
    void addActuator(const std::string& actuator);
    void computerVision() const;
    void infotainment() const;

    void accelerate() const override;
    void brake() const override;
    void steer() const override;
};

#endif // CAR_HPP
