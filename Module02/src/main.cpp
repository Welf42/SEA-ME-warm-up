#include "Car.hpp"

// int main() {
//     Car myCar("911 GT3 RS");
//     myCar.printDetails();
//     return 0;
// }

// void demonstrateRawPointers() {
//     std::cout << "\n--- Raw Pointer Demonstration ---\n";
    
//     // Part 1: This is how it should be done.
//     // Proper use of raw pointer
//     // Car* car1 = new Car("Porsche 911");
//     // car1->printDetails();
//     // delete car1;  // Properly deallocated

//     // // Part 2: if not deleted (free memory), then you create memory leaks
//     // // Memory leak: forgot to delete
//     // Car* car2 = new Car("Ferrari 488");
//     // car2->printDetails();
//     // // delete car2;  // Uncomment to fix the leak

//     // // Part3: using pointer after freeing it
//     // // Dangling pointer
//     // Car* car3 = new Car("Lamborghini Huracan");
//     // delete car3;
//     // car3->printDetails();  // Dangling pointer: Undefined behavior if uncommented
// }



void demonstrateSmartPointers() {
    std::cout << "\n--- Smart Pointer Demonstration ---\n";
    
    // unique_ptr: exclusive ownership
    std::unique_ptr<Car> u_ptr = std::make_unique<Car>("McLaren 720S");
    u_ptr->printDetails();
    // No need to delete, unique_ptr handles it

    // shared_ptr: shared ownership
    std::shared_ptr<Car> s_ptr1 = std::make_shared<Car>("Aston Martin Vantage");
    {
        auto s_ptr2 = s_ptr1;  // Both pointers now own the car
        s_ptr2->printDetails();
    }  // s_ptr2 goes out of scope, but car is not deleted yet
    s_ptr1->printDetails();  // Car still exists
    // Car will be deleted when s_ptr1 goes out of scope

    // weak_ptr: non-owning reference
    std::weak_ptr<Car> w_ptr = s_ptr1;
    if (auto shared = w_ptr.lock()) {
        shared->printDetails();
    } else {
        std::cout << "Car no longer exists\n";
    }
}


int main() {
    // demonstrateRawPointers();
    demonstrateSmartPointers();

    std::cout << "\n--- Program Ending ---\n";
    // Note: Any cars not properly deleted will show up here
    // as they'll be destroyed when the program exits

    return 0;
}
