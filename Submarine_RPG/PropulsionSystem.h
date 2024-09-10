#pragma once
#ifndef PROPULSIONSYSTEM_H
#define PROPULSIONSYSTEM_H
#include"iostream"
#include <string>
class PropulsionSystem {
private:
    std::string propulsionSystemType_; // type of propulsion system (e.g. diesel, nuclear, etc.)
    double propulsionSystemPower_; // power output of the propulsion system
    double propulsionSystemEfficiency_; // efficiency of the propulsion system

public:
    /**
     * Constructor for PropulsionSystem
     * @param propulsionSystemType type of propulsion system
     */
    PropulsionSystem(const std::string& propulsionSystemType);

    /**
     * Get the type of propulsion system
     * @return propulsion system type
     */
    std::string getPropulsionSystemType() const;

    /**
     * Get the power output of the propulsion system
     * @return propulsion system power
     */
    double getPropulsionSystemPower() const;

    /**
     * Get the efficiency of the propulsion system
     * @return propulsion system efficiency
     */
    double getPropulsionSystemEfficiency() const;
};

#endif // PROPULSIONSYSTEM_H

