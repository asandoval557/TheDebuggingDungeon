// Define a header guard to prevent multiple inclusions of the same header file
#ifndef SUBMARINE_COMPONENT_FACTORY_H
#define SUBMARINE_COMPONENT_FACTORY_H
#include <stdexcept>
// Include the necessary header file for the SubmarineComponentFactory class
#include "SubmarineComponentFactory.h"

// Include the necessary header file for the ConcreteSubmarineComponent class
#include "ConcreteSubmarineComponent.h"

// Include the necessary header file for the SonarComponent class
#include "SonarComponent.h"

// Include the necessary header file for the PropulsionComponent class
#include "PropulsionComponent.h"

// Include the necessary header file for the TorpedoComponent class
#include "TorpedoComponent.h"

// Include the necessary map library for map operations
#include <map>

// Include the necessary header file for the SubmarineComponent class
#include "SubmarineComponent.h"

// Define a factory class for creating submarine components
class SubmarineComponentFactory {
private:
    // Declare a private member variable to store a map of component types to components
    std::map<std::string, std::unique_ptr<SubmarineComponent>> componentMap; // Map of component types to components

public:
    // Declare a function to get a component of a specific type
    SubmarineComponent* getComponent(const std::string& type);
    ~SubmarineComponentFactory();
};

#endif // SUBMARINE_COMPONENT_FACTORY_H
