#include "SubmarineComponent.h"
#include <iostream>

// Constructor for the SubmarineComponent class
// This constructor takes a std::string argument 'name' which represents the name of the submarine component
SubmarineComponent::SubmarineComponent(std::string name) : name_(name) {
    // The constructor initializes the 'name_' member variable with the provided 'name' argument
    // This is done using an initialization list, which is a more efficient way to initialize member variables
    // compared to assigning values inside the constructor body
}

// Destructor for the SubmarineComponent class
// This is a virtual destructor, which is necessary when working with polymorphism and derived classes
SubmarineComponent::~SubmarineComponent() {
    // The destructor doesn't do anything in this case, but it's necessary to provide a virtual destructor
    // to ensure that derived classes can properly clean up resources when objects are deleted
}

// This is a pure virtual function, which means it must be implemented by any derived classes
// The purpose of this function is to perform some operation specific to the submarine component
// The exact behavior will depend on the derived class that implements this function
void SubmarineComponent::performOperation() {
    std::cout << "Performing torpedo operation..." << std::endl;

}

// This is another pure virtual function, which means it must be implemented by any derived classes
// The purpose of this function is to provide a description of the submarine component
// The exact behavior will depend on the derived class that implements this function
std::string SubmarineComponent::getDescription() {
    return "Advanced torpedo system for engaging and destroying enemy targets";
}

// This is a virtual function, which means it can be overridden by derived classes
// The purpose of this function is to provide the name of the submarine component
std::string SubmarineComponent::getName() {
    // This implementation simply returns the 'name_' member variable
    // Derived classes can override this function to provide their own implementation if needed
    return name_;
}