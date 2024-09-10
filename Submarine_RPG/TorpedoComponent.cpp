#include "TorpedoComponent.h"
#include <iostream>

TorpedoComponent::TorpedoComponent(std::string name) : SubmarineComponent(name) {
    // This constructor is intentionally left empty, as we don't need to initialize
    // any member variables here.
}

TorpedoComponent::~TorpedoComponent() {
    // This destructor is intentionally left empty, as we don't need to release
    // any resources here.
}

void TorpedoComponent::performOperation() {
    std::cout << "Performing torpedo operation..." << std::endl;
}

std::string TorpedoComponent::getDescription() {
    return "Advanced torpedo system for engaging and destroying enemy targets";
}

// Method to get the name of the torpedo component
std::string TorpedoComponent::getName() {
    // Return the name of the torpedo component
    return SubmarineComponent::getName();
}