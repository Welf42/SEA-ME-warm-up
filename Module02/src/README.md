## Memory Management in C++: Key Concepts

### Memory Leaks

A memory leak occurs when dynamically allocated memory is not properly deallocated, leading to a gradual loss of available memory over time. In our example without smart pointers, if we forgot to include the destructor in the `Car` class, it would result in a memory leak:

```cpp
class Car {
    // ...
    ~Car() {
        // Without this destructor, all dynamically allocated parts would leak
        delete engine;
        for (auto wheel : wheels) delete wheel;
        // ...
    }
};
```

### Dangling Pointers

A dangling pointer is a pointer that references memory that has been freed or is no longer valid. This can lead to undefined behavior if dereferenced. For example:

```cpp
Engine* engine = new Engine("V8", 400, 5.0);
delete engine;  // engine is now a dangling pointer
engine->print();  // Undefined behavior: accessing deleted memory
```

### Smart Pointers

Smart pointers are objects that act like pointers but provide automatic memory management. They ensure that the objects they point to are properly deleted when no longer needed. The most common types are:

1. `std::unique_ptr`: For exclusive ownership
2. `std::shared_ptr`: For shared ownership
3. `std::weak_ptr`: For non-owning references to `shared_ptr` managed objects

In our smart pointer example:

```cpp
class Car {
private:
    std::unique_ptr<Engine> engine;
    // ...
public:
    Car(std::string m) : model(std::move(m)) {
        engine = std::make_unique<Engine>("4.0L flat-six", 518, 4.0);
        // ...
    }
    // No need for a destructor; smart pointers handle cleanup automatically
};
```

### RAII (Resource Acquisition Is Initialization)

RAII is a programming idiom where resource management is tied to object lifetime. Resources (like memory) are acquired during object construction and released during object destruction. Smart pointers are an implementation of RAII. In our example:

```cpp
class Car {
    std::unique_ptr<Engine> engine;
    // ...
public:
    Car(std::string m) {
        engine = std::make_unique<Engine>(...);  // Resource acquisition
    }
    // Resource release happens automatically when Car is destroyed
};
```

### Benefits of Smart Pointers

1. **Automatic Memory Management**: They handle deallocation automatically, reducing the risk of memory leaks.
2. **Exception Safety**: They ensure resources are properly released even if exceptions are thrown.
3. **Clear Ownership Semantics**: `unique_ptr` makes exclusive ownership explicit, while `shared_ptr` represents shared ownership.

### When to Use Raw Pointers vs Smart Pointers

- Use smart pointers when you need ownership management of dynamically allocated resources.
- Use raw pointers for non-owning references or when working with C APIs.
- In modern C++, prefer smart pointers for most scenarios involving dynamic memory.

### Best Practices

1. Prefer smart pointers over raw pointers for resource management.
2. Use `std::make_unique` and `std::make_shared` to create smart pointers.
3. Be consistent with memory management strategy throughout your codebase.
4. Understand the ownership model of your resources and choose appropriate smart pointers.