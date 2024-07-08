# Types of Smart Pointers

C++ libraries provide implementations of smart pointers in the following types:
    auto_ptr
    unique_ptr
    shared_ptr
    weak_ptr

## auto_ptr
Using auto_ptr, you can manage objects obtained from new expressions and delete them when auto_ptr itself is destroyed. When an object is described through auto_ptr it stores a pointer to a single allocated object.

## unique_ptr
unique_ptr stores one pointer only. We can assign a different object by removing the current object from the pointer. 

## shared_ptr
By using shared_ptr more than one pointer can point to this one object at a time and it’ll maintain a Reference Counter using the use_count() method. 

## weak_ptr 
Weak_ptr is a smart pointer that holds a non-owning reference to an object. It’s much more similar to shared_ptr except it’ll not maintain a Reference Counter. In this case, a pointer will not have a stronghold on the object. The reason is if suppose pointers are holding the object and requesting for other objects then they may form a Deadlock. 
