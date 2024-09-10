#pragma once
#ifndef PROPULSIONCOMPONENT_H
#define PROPULSIONCOMPONENT_H

#include "SubmarineComponent.h"

class PropulsionComponent : public SubmarineComponent {
public:
    PropulsionComponent();
    ~PropulsionComponent();

    // Override the performOperation method to provide propulsion-specific behavior
    void performOperation() override;

    // Override the getDescription method to provide a description of the propulsion component
    std::string getDescription() override;       // implementation of the getDescription function
    std::string getName() override; // implementation of the getName function
};

#endif // PROPULSIONCOMPONENT_H
