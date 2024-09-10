#include "ConcreteSubmarineComponent.h"
#include <iostream>

// Constructor for the ConcreteSubmarineComponent class
ConcreteSubmarineComponent::ConcreteSubmarineComponent(std::string name) : SubmarineComponent(name) {
    // We're calling the base class constructor (SubmarineComponent) with the provided name
    // This sets the name of the component, which can be used later for identification or display purposes
}

// Destructor for the ConcreteSubmarineComponent class
ConcreteSubmarineComponent::~ConcreteSubmarineComponent() {
    // This destructor is intentionally left empty, as we don't need to release any resources here
    // The base class destructor (SubmarineComponent) will be called automatically, which is sufficient for our needs
}

// Implementation of the performOperation method, which is specific to this component
void ConcreteSubmarineComponent::performOperation() {
    // This method is where the magic happens for this specific component
    // In this case, we're simulating a concrete submarine component performing an operation
    std::cout << "Performing operation on " << getName() << "..." << std::endl;
    // We're using the getName method inherited from the base class to get the name of the component
    // This allows us to display a message that's specific to this component
}

// Implementation of the getDescription method, which is specific to this component
std::string ConcreteSubmarineComponent::getDescription() {
    // This method returns a string that describes the component
    // In this case, we're returning a string that's specific to this concrete submarine component
    return "Concrete submarine component with advanced sonar capabilities";
    // This description can be used in the game to display information about the component to the player
}

std::string ConcreteSubmarineComponent::getName()
{
    return std::string();
}
