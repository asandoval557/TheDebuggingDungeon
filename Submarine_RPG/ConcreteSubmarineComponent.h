#pragma once
// Define a header guard to prevent multiple inclusions of the same header file
#ifndef CONCRETE_SUBMARINE_COMPONENT_H
#define CONCRETE_SUBMARINE_COMPONENT_H

// Include the necessary string library for string operations
#include <string>

// Include the necessary header file for the SubmarineComponent class
#include "SubmarineComponent.h"
#include <iostream>

// Define a concrete class for submarine components
class ConcreteSubmarineComponent : public SubmarineComponent {
private:
    // Declare a private member variable to store the type of the component
    std::string componentType; // Type of the submarine component

public:

    // Declare the performOperation method as pure virtual to make this an abstract base class
    virtual void performOperation() override; // Perform an operation on the component


    // Declare the getDescription method as virtual to allow derived classes to override it
    virtual std::string getDescription() override; // Get a description of the component

    // Declare the getName method as virtual to allow derived classes to override it
    virtual std::string getName()override; // Get the name of the component


    // Declare a constructor to initialize the component type
    ConcreteSubmarineComponent(std::string type); // Constructor to initialize component type
    ~ConcreteSubmarineComponent(); // destructor to cleanup
    // Implement the pure virtual function to perform an operation on the component
 
};

#endif // CONCRETE_SUBMARINE_COMPONENT_H