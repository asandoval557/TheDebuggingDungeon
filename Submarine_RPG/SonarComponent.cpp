#include "SonarComponent.h"
#include <iostream>

SonarComponent::SonarComponent() : SubmarineComponent("SonarComponent") {
    // This constructor is intentionally left empty, as we don't need to initialize
    // any member variables here.
}

SonarComponent::~SonarComponent() {
    // This destructor is intentionally left empty, as we don't need to release
    // any resources here.
}

void SonarComponent::performOperation() {
    std::cout << "Performing sonar operation..." << std::endl;
}

std::string SonarComponent::getDescription() {
    return "Advanced sonar system for detecting and tracking targets";
}

std::string SonarComponent::getName()
{
    return name_;       // returns the name of the component
}
