#include "SubmarineAction.h"
#include <string>
#include <stdexcept>

// Constructor implementation for the SubmarineAction class
SubmarineAction::SubmarineAction(const std::string& actionName) {
    if (actionName.empty()) {
        throw std::invalid_argument("Action name cannot be empty");
    }

    if (actionName == "attack") {
        actionType_ = SubmarineActionType::ATTACK;
    }
    else if (actionName == "defend") {
        actionType_ = SubmarineActionType::DEFEND;
    }
    else if (actionName == "diving") {
        actionType_ = SubmarineActionType::DIVING;
    }
    else if (actionName == "surfacing") {
        actionType_ = SubmarineActionType::SURFACING;
    }
    else if (actionName == "emergency_diving") {
        actionType_ = SubmarineActionType::EMERGENCY_DIVING;
    }
    else {
        throw std::invalid_argument("Unknown action name");
    }
}

SubmarineAction::SubmarineActionType SubmarineAction::getActionType() const
{
    return actionType_;
}

SubmarineAction::SubmarineActionType SubmarineAction::stringToActionType(const std::string& actionName)
{
    if (actionName == "Attack") {
        return SubmarineActionType::ATTACK;
    }
    else if (actionName == "Defend") {
        return SubmarineActionType::DEFEND;
    }
    else if (actionName == "Diving") {
        return SubmarineActionType::DIVING;
    }
    else if (actionName == "Surfacing") {
        return SubmarineActionType::SURFACING;
    }
    else if (actionName == "Emergency Diving") {
        return SubmarineActionType::EMERGENCY_DIVING;
    }
    else {
        // Handle unknown action name
        return SubmarineActionType::ATTACK; // default to ATTACK
    }
}
   


