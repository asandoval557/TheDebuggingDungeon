#pragma once
#include <string>
#include"iostream"
#ifndef SUBMARINEACTION_H
#define SUBMARINEACTION_H

class SubmarineAction {
public:
    // Constructor that takes a std::string parameter to initialize the SubmarineAction object
    SubmarineAction(const std::string& actionName);

    // Enumeration to represent the different types of submarine actions
    enum class SubmarineActionType 
    {
        ATTACK, // Attack action
        DEFEND, // Defend action
        DIVING, // Diving action
        SURFACING, // Surfacing action
        EMERGENCY_DIVING // Emergency diving action
    };
    SubmarineAction(SubmarineActionType actionType) : actionType_(actionType) {}
   
    void setActionType(SubmarineActionType actionType) {
        actionType_ = actionType;
    }
    // Method to get the type of action
    SubmarineActionType getActionType() const;
    // Method to convert a string to a SubmarineActionType
    static SubmarineActionType stringToActionType(const std::string& actionName);

private:
    // Private variable to store the type of action
    SubmarineActionType actionType_;
   

};

#endif // SUBMARINEACTION_H

