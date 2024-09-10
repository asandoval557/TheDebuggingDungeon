#include "PropulsionComponent.h"
#include <iostream>

PropulsionComponent::PropulsionComponent() : SubmarineComponent("PropulsionComponent") 
    {
    // This constructor is intentionally left empty, as we don't need to initialize
    // any member variables here.
}

PropulsionComponent::~PropulsionComponent() {
    // This destructor is intentionally left empty, as we don't need to release
    // any resources here.
}

void PropulsionComponent::performOperation() {
    std::cout << "Performing propulsion operation..." << std::endl;
}

std::string PropulsionComponent::getDescription() {
    return "High-performance propulsion system for rapid movement and maneuverability";
}

std::string PropulsionComponent::getName()
{
    return name_; // returns the name of the component

}
