#pragma once
#ifndef SUBMARINEMENTO_H
#define SUBMARINEMENTO_H

#include <string>
#include "GameLogic.h"

// Forward declaration of GameLogic class
class GameLogic;

// SubmarineMemento class declaration
class SubmarineMemento {
public:
    // Constructor to initialize SubmarineMemento object
    SubmarineMemento(const std::string& hullType, const std::string& propulsionType, const std::string& controlSystemType, const std::string& submarineName, int currentPositionX, int currentDepth, const std::string& hullTypeDescription, const std::string& propulsionSystemType, int maximumDepthRange, int attackPower, int detectionRange, int defenseValue, int movementDistance, const std::string& currentAction, const std::string& submarineOwner, int purchasePrice, int securityClearanceLevel, int monthlyMaintenanceCost, GameLogic* gameLogic);
    // Getter function to retrieve submarine name
    std::string getSubmarineName();

    // Getter function to retrieve current position X
    int getCurrentPositionX();

    // Getter function to retrieve current depth
    int getCurrentDepth();

    // Getter for hullType
    std::string getHullType() const;

    // Getter for propulsionType
    std::string getPropulsionType() const;

    // Getter function to retrieve hull type description
    std::string getHullTypeDescription();

    // Getter function to retrieve propulsion system type
    std::string getPropulsionSystemType();

    // Getter function to retrieve maximum depth range
    int getMaximumDepthRange();

    // Getter function to retrieve attack power
    int getAttackPower();

    // Getter function to retrieve detection range
    int getDetectionRange();

    // Getter function to retrieve defense value
    int getDefenseValue();

    // Getter function to retrieve movement distance
    int getMovementDistance();

    // Getter function to retrieve current action
    std::string getCurrentAction();

    // Getter function to retrieve submarine owner
    std::string getSubmarineOwner();

    // Getter function to retrieve purchase price
    int getPurchasePrice();

    // Getter function to retrieve security clearance level
    int getSecurityClearanceLevel();

    // Getter function to retrieve monthly maintenance cost
    int getMonthlyMaintenanceCost();
    int getCurrentHealth();
    // Getter function to retrieve control system type
    std::string getControlSystemType();

    // Getter function to retrieve action type
    std::string getActionType();

    void displaySubmarineDetails();

    void saveSubmarineState();

    void restoreSubmarineState();

    void updateCurrentPositionX(int currentPositionX);

private:
    // Member variables to store submarine state
    std::string hullType_;
    std::string propulsionType_;
    std::string submarineName_;
    int currentPositionX_;
    int currentDepth_;
    std::string hullTypeDescription_;
    std::string propulsionSystemType_;
    int maximumDepthRange_;
    int attackPower_;
    int detectionRange_;
    int defenseValue_;
    int movementDistance_;
    std::string currentAction_;
    std::string submarineOwner_;
    int purchasePrice_;
    int securityClearanceLevel_;
    int monthlyMaintenanceCost_;
    int currentHealth_;
    std::string controlSystemType_; // new member variable to store control system type
    GameLogic* gameLogic_;
};

#endif  // SUBMARINEMENTO_H