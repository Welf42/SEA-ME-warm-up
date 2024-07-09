# C++ Smart Pointers and OOP Concepts Documentation

## Table of Contents
1. [Libraries Used](#libraries-used)
2. [Smart Pointers](#smart-pointers)
3. [Virtual Functions and Override](#virtual-functions-and-override)
4. [Inheritance and Polymorphism](#inheritance-and-polymorphism)
5. [Memory Management](#memory-management)
6. [C++ Syntax and Concepts](#c-syntax-and-concepts)
7. [Car Modeling Example](#car-modeling-example)

## Libraries Used

### `<iostream>`
- Provides input/output stream functionality.
- Used for console input/output operations.

### `<memory>`
- Provides smart pointer templates such as `std::unique_ptr` and `std::shared_ptr`.
- Used for automatic memory management.

### `<vector>`
- Provides dynamic array functionality.
- Used for storing collections of objects.

## Smart Pointers

Smart pointers are objects that act like pointers but provide additional features such as automatic memory management and ownership semantics.

### Types of Smart Pointers

1. **std::unique_ptr**
   - Owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.
   - Cannot be copied, only moved.

   ```cpp
   std::unique_ptr<Engine> engine_ = std::make_unique<Engine>();
   ```

2. **std::shared_ptr**
   - Retains shared ownership of an object through a pointer.
   - Several shared_ptr objects may own the same object.

   ```cpp
   std::shared_ptr<Engine> engine_ = std::make_shared<Engine>();
   ```

3. **std::weak_ptr**
   - Holds a non-owning reference to an object that is managed by std::shared_ptr.
   - Used to break circular references of shared_ptr.

   ```cpp
   std::weak_ptr<Engine> weakEngine = engine_;
   ```

### Benefits of Smart Pointers
- Automatic memory management
- Prevention of memory leaks
- Safer exception handling
- Clear ownership semantics

## Virtual Functions and Override

### Virtual Functions
Virtual functions allow derived classes to override the implementation provided by their base class.

```cpp
class Part {
public:
    virtual void print() = 0; // Pure virtual function
    virtual ~Part() = default; // Virtual destructor
};
```

### Override Keyword
The `override` keyword ensures that the function is indeed overriding a virtual function from a base class.

```cpp
class Engine : public Part {
public:
    void print() override {
        std::cout << "Engine part\n";
    }
};
```

### Benefits
- Runtime polymorphism
- Interface-based programming
- Extensibility of code

## Inheritance and Polymorphism

### Inheritance
Inheritance allows a derived class to inherit properties and methods from a base class.

```cpp
class Engine : public Part {
    // Engine-specific implementation
};
```

### Polymorphism
Polymorphism allows objects of different types to be treated as objects of a common base class.

```cpp
std::vector<std::unique_ptr<Part>> parts;
parts.push_back(std::make_unique<Engine>());
parts.push_back(std::make_unique<Wheel>());

for (const auto& part : parts) {
    part->print(); // Calls the appropriate print() method
}
```

## Memory Management

### RAII (Resource Acquisition Is Initialization)
RAII is a programming technique where resource management is tied to object lifetime.

```cpp
class Car {
private:
    std::unique_ptr<Engine> engine_;
    // Other parts...

public:
    Car() : engine_(std::make_unique<Engine>()) {
        // Initialize other parts...
    }
    // No need for explicit destructor
};
```

### Preventing Memory Leaks
Smart pointers automatically manage memory, preventing leaks.

```cpp
void function() {
    auto car = std::make_unique<Car>();
    // No need to delete car
} // car is automatically deleted when function ends
```

## C++ Syntax and Concepts

### auto Keyword
`auto` allows the compiler to deduce the type of a variable.

```cpp
auto engine = std::make_unique<Engine>();
```

### Range-based for Loop
Simplifies iteration over containers.

```cpp
for (const auto& wheel : wheels_) {
    wheel->print();
}
```

### nullptr
A pointer literal representing a null pointer.

```cpp
Engine* rawPtr = nullptr;
```

### std::vector
A dynamic array container.

```cpp
std::vector<std::unique_ptr<Wheel>> wheels_;
```

### Lambda Functions
Anonymous functions that can be used inline.

```cpp
std::for_each(parts.begin(), parts.end(), [](const auto& part) {
    part->print();
});
```

### constexpr
Specifies that the value of a variable or function can be evaluated at compile time.

```cpp
constexpr int NUM_WHEELS = 4;
```

## Car Modeling Example

Here's a complete example demonstrating the concepts discussed:

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Part {
public:
    virtual void print() = 0;
    virtual ~Part() = default;
};

class Engine : public Part {
public:
    void print() override {
        std::cout << "Engine part\n";
    }
};

class Wheel : public Part {
public:
    void print() override {
        std::cout << "Wheel part\n";
    }
};

class Brake : public Part {
public:
    void print() override {
        std::cout << "Brake part\n";
    }
};

class Transmission : public Part {
public:
    void print() override {
        std::cout << "Transmission part\n";
    }
};

class Car {
public:
    Car() {
        engine_ = std::make_unique<Engine>();
        for (int i = 0; i < NUM_WHEELS; ++i) {
            wheels_.emplace_back(std::make_unique<Wheel>());
            brakes_.emplace_back(std::make_unique<Brake>());
        }
        transmission_ = std::make_unique<Transmission>();
    }
    
    void printParts() {
        engine_->print();
        for (const auto& wheel : wheels_) {
            wheel->print();
        }
        for (const auto& brake : brakes_) {
            brake->print();
        }
        transmission_->print();
    }
    
private:
    static constexpr int NUM_WHEELS = 4;
    std::unique_ptr<Engine> engine_;
    std::vector<std::unique_ptr<Wheel>> wheels_;
    std::vector<std::unique_ptr<Brake>> brakes_;
    std::unique_ptr<Transmission> transmission_;
};

int main() {
    Car myCar;
    myCar.printParts();
    
    return 0;
}
