#pragma once
#ifndef TORPEDOCOMPONENT_H
#define TORPEDOCOMPONENT_H

#include "SubmarineComponent.h"

class TorpedoComponent : public SubmarineComponent {
public:
    TorpedoComponent(std::string name);
    ~TorpedoComponent();

    // Override the performOperation method to provide torpedo-specific behavior
    void performOperation() ;


    // Override the getDescription method to provide a description of the torpedo component
    std::string getDescription();
    // Override the getName method to provide the name of the torpedo component
    std::string getName() ;
};

#endif // TORPEDOCOMPONENT_H
