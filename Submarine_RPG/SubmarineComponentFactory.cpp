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

// Define the constructor for the SubmarineComponentFactory class
SubmarineComponentFactory::SubmarineComponentFactory() {
    // This constructor is intentionally left empty, as we don't need to initialize
    // any member variables here.
}

// Define the destructor for the SubmarineComponentFactory class
SubmarineComponentFactory::~SubmarineComponentFactory() {
  
    
}

// Define the getComponent method to get a component of a specific type
SubmarineComponent* SubmarineComponentFactory::getComponent(const std::string& type) {
    // Check if the component type is empty
    if (type.empty()) {
        // If so, throw an exception
        throw std::invalid_argument("Component type cannot be empty");
    }
    // Check if the component type is already in the map
    if (componentMap.find(type) == componentMap.end()) {
        // If not, create a new component of the specified type and add it to the map
        if (type == "Sonar") {
            componentMap[type] = std::make_unique<SonarComponent>();
        }
        else if (type == "Propulsion") {
            componentMap[type] = std::make_unique<PropulsionComponent>();
        }
        else if (type == "Torpedo") {
            componentMap[type] = std::make_unique<TorpedoComponent>();
        }
        else {
            // If the type is not recognized, throw an exception
            throw std::invalid_argument("Unrecognized component type");
        }
        // Log a message indicating that the component was created
        std::cout << "Created component of type " << type << std::endl;
    }
    else {
        // Log a message indicating that the component was retrieved
        std::cout << "Retrieved component of type " << type << std::endl;
    }
    // Return the component of the specified type
    return componentMap[type].get();
}
