# Car Class Hierarchy Documentation

## Libraries Used

1. `<iostream>`: For input/output operations.
2. `<string>`: For string manipulation.
3. `<vector>`: For dynamic array functionality.

## Orthodox Canonical Form (OCF)

The Orthodox Canonical Form is a C++ class design pattern that includes:

1. **Default Constructor**: Creates an object with default values.
   Syntax: `ClassName();`

2. **Copy Constructor**: Creates a new object as a copy of an existing object.
   Syntax: `ClassName(const ClassName& other);`

3. **Copy Assignment Operator**: Assigns the contents of one object to another.
   Syntax: `ClassName& operator=(const ClassName& other);`

4. **Destructor**: Cleans up resources when an object is destroyed.
   Syntax: `virtual ~ClassName();`

## OOP Concepts

### Inheritance
- Syntax: `class DerivedClass : public BaseClass`
- Example: `class SportsCar : public Car`

### Encapsulation
- Use of `private`, `protected`, and `public` access specifiers.
- Example: `protected: std::string make;`

### Polymorphism
- Use of `virtual` functions in base class and `override` in derived classes.
- Syntax: `virtual void functionName() const;`
- Example: `virtual void drive() const;`

## Class Descriptions

### Car (Base Class)

#### Member Variables
- `make`: string
- `model`: string
- `year`: int

#### Methods
- Constructors and destructor (OCF)
- Virtual methods: `drive()`, `accelerate()`, `brake()`, `steer()`

### SportsCar (Derived from Car)

#### Additional Member Variable
- `topSpeed`: int

#### Methods
- Constructors and destructor (OCF)
- Overridden method: `drive()`

### SoftwareDefinedVehicle (Derived from Car)

#### Additional Member Variables
- `softwareVersion`: string
- `sensors`: vector<string>
- `actuators`: vector<string>

#### Methods
- Default constructor
- SDV-specific methods: `updateSoftware()`, `addSensor()`, `addActuator()`, `computerVision()`, `infotainment()`
- Overridden methods: `accelerate()`, `brake()`, `steer()`

## Key C++ Concepts and Syntax

1. **Virtual Functions**
   - Syntax: `virtual returnType functionName() const;`
   - Purpose: Enable runtime polymorphism

2. **Override Keyword**
   - Syntax: `returnType functionName() const override;`
   - Purpose: Explicitly indicate function overriding

3. **Const Member Functions**
   - Syntax: `returnType functionName() const;`
   - Purpose: Indicate that the function doesn't modify object state

4. **Vector of Strings**
   - Syntax: `std::vector<std::string> variableName;`
   - Purpose: Dynamic array of strings

5. **Member Initialization List**
   - Syntax: `ClassName() : member1(value1), member2(value2) {}`
   - Purpose: Initialize class members efficiently

6. **Vector Operations**
   - `push_back()`: Add element to the end of vector
   - Syntax: `vectorName.push_back(element);`

7. **Scope Resolution Operator**
   - Syntax: `ClassName::methodName`
   - Purpose: Specify the class a method belongs to

8. **This Pointer**
   - Syntax: `this->`
   - Purpose: Refer to the current object

