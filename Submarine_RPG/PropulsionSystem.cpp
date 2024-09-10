#include "PropulsionSystem.h"

PropulsionSystem::PropulsionSystem(const std::string& propulsionSystemType)
    : propulsionSystemType_(propulsionSystemType), propulsionSystemPower_(0.0), propulsionSystemEfficiency_(0.0) {
    // initialize propulsion system power and efficiency based on type
    if (propulsionSystemType_ == "diesel") {
        propulsionSystemPower_ = 1000.0; // kW
        propulsionSystemEfficiency_ = 0.8; // 80% efficient
    }
    else if (propulsionSystemType_ == "nuclear") {
        propulsionSystemPower_ = 5000.0; // kW
        propulsionSystemEfficiency_ = 0.9; // 90% efficient
    }
    else {
        // default values for unknown propulsion system type
        propulsionSystemPower_ = 500.0; // kW
        propulsionSystemEfficiency_ = 0.7; // 70% efficient
    }
}

std::string PropulsionSystem::getPropulsionSystemType() const {
    return propulsionSystemType_;
}

double PropulsionSystem::getPropulsionSystemPower() const {
    return propulsionSystemPower_;
}

double PropulsionSystem::getPropulsionSystemEfficiency() const {
    return propulsionSystemEfficiency_;
}