#pragma once
#ifndef SONARCOMPONENT_H
#define SONARCOMPONENT_H

#include "SubmarineComponent.h"

class SonarComponent : public SubmarineComponent {
public:
    SonarComponent();
    ~SonarComponent();

    // Override the performOperation method to provide sonar-specific behavior
    void performOperation() override;

    // Override the getDescription method to provide a description of the sonar component
   
    std::string getDescription() override;
    std::string getName() override;
};

#endif // SONARCOMPONENT_H
