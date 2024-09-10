#include "SubmarineMemento.h"
#include <iostream>
#include "GameLogic.h"
#include "SubmarineMemento.h"

// Constructor implementation to initialize SubmarineMemento object
#include "SubmarineMemento.h"

SubmarineMemento::SubmarineMemento(const std::string& hullType, const std::string& propulsionType, const std::string& controlSystemType,
    const std::string& submarineName, int currentPositionX, int currentDepth,
    const std::string& hullTypeDescription, const std::string& propulsionSystemType,
    int maximumDepthRange, int attackPower, int detectionRange, int defenseValue,
    int movementDistance, const std::string& currentAction, const std::string& submarineOwner,
    int purchasePrice, int securityClearanceLevel, int monthlyMaintenanceCost, GameLogic* gameLogic)
    : hullType_(hullType), propulsionType_(propulsionType), controlSystemType_(controlSystemType),
    submarineName_(submarineName), currentPositionX_(currentPositionX), currentDepth_(currentDepth),
    hullTypeDescription_(hullTypeDescription), propulsionSystemType_(propulsionSystemType),
    maximumDepthRange_(maximumDepthRange), attackPower_(attackPower), detectionRange_(detectionRange),
    defenseValue_(defenseValue), movementDistance_(movementDistance), currentAction_(currentAction),
    submarineOwner_(submarineOwner), purchasePrice_(purchasePrice), securityClearanceLevel_(securityClearanceLevel),
    monthlyMaintenanceCost_(monthlyMaintenanceCost), currentHealth_(0), gameLogic_(gameLogic) 
{
    // Check for invalid input values
    if (hullType.empty() || propulsionType.empty() || controlSystemType.empty() || submarineName.empty() ||
        currentPositionX < 0 || currentDepth < 0 || maximumDepthRange < 0 || attackPower < 0 || detectionRange < 0 ||
        defenseValue < 0 || movementDistance < 0 || purchasePrice < 0 || securityClearanceLevel < 0 || monthlyMaintenanceCost < 0) 
    {
        throw std::invalid_argument("Invalid input values for SubmarineMemento constructor");
    }
}

// Getter function implementation to retrieve submarine name
std::string SubmarineMemento::getSubmarineName() {
    return submarineName_;
}

// Getter function implementation to retrieve current position X
int SubmarineMemento::getCurrentPositionX() {
    return currentPositionX_;
}

// Getter function implementation to retrieve current depth
int SubmarineMemento::getCurrentDepth() {
    return currentDepth_;
}

std::string SubmarineMemento::getHullType() const
{
    return std::string();
}

std::string SubmarineMemento::getPropulsionType() const
{
    return std::string();
}

// Getter function implementation to retrieve hull type description
std::string SubmarineMemento::getHullTypeDescription() {
    return hullTypeDescription_;
}
// Getter function implementation to retrieve propulsion system type
std::string SubmarineMemento::getPropulsionSystemType() {
    return propulsionSystemType_;
}

// Getter function implementation to retrieve maximum depth range
int SubmarineMemento::getMaximumDepthRange() {
    return maximumDepthRange_;
}

// Getter function implementation to retrieve attack power
int SubmarineMemento::getAttackPower() {
    return attackPower_;
}

// Getter function implementation to retrieve detection range
int SubmarineMemento::getDetectionRange() {
    return detectionRange_;
}

// Getter function implementation to retrieve defense value
int SubmarineMemento::getDefenseValue() {
    return defenseValue_;
}

// Getter function implementation to retrieve movement distance
int SubmarineMemento::getMovementDistance() {
    return movementDistance_;
}

// Getter function implementation to retrieve current action
std::string SubmarineMemento::getCurrentAction() {
    return currentAction_;
}

// Getter function implementation to retrieve submarine owner
std::string SubmarineMemento::getSubmarineOwner() {
    return submarineOwner_;
}

// Getter function implementation to retrieve purchase price
int SubmarineMemento::getPurchasePrice() {
    return purchasePrice_;
}

// Getter function implementation to retrieve security clearance level
int SubmarineMemento::getSecurityClearanceLevel() {
    return securityClearanceLevel_;
}

// Getter function implementation to retrieve monthly maintenance cost
int SubmarineMemento::getMonthlyMaintenanceCost() {
    return monthlyMaintenanceCost_;
}

int SubmarineMemento::getCurrentHealth()
{
    return currentHealth_;
}

std::string SubmarineMemento::getControlSystemType()
{
    return controlSystemType_;
}
// Getter function implementation to retrieve action type
std::string SubmarineMemento::getActionType() {
    // Assuming action type is the same as current action
    return currentAction_;
}

// Function implementation to display submarine's details
void SubmarineMemento::displaySubmarineDetails() {
    std::cout << "Submarine Name: " << submarineName_ << std::endl;
    std::cout << "Current Position X: " << currentPositionX_ << std::endl;
    std::cout << "Current Depth: " << currentDepth_ << std::endl;
    std::cout << "Hull Type: " << hullType_ << std::endl;
    std::cout << "Propulsion Type: " << propulsionType_ << std::endl;
    std::cout << "Control System Type: " << controlSystemType_ << std::endl;
    std::cout << "Hull Type Description: " << hullTypeDescription_ << std::endl;
    std::cout << "Propulsion System Type: " << propulsionSystemType_ << std::endl;
    std::cout << "Maximum Depth Range: " << maximumDepthRange_ << std::endl;
    std::cout << "Attack Power: " << attackPower_ << std::endl;
    std::cout << "Detection Range: " << detectionRange_ << std::endl;
    std::cout << "Defense Value: " << defenseValue_ << std::endl;
    std::cout << "Movement Distance: " << movementDistance_ << std::endl;
    std::cout << "Current Action: " << currentAction_ << std::endl;
    std::cout << "Submarine Owner: " << submarineOwner_ << std::endl;
    std::cout << "Purchase Price: " << purchasePrice_ << std::endl;
    std::cout << "Security Clearance Level: " << securityClearanceLevel_ << std::endl;
    std::cout << "Monthly Maintenance Cost: " << monthlyMaintenanceCost_ << std::endl;
    std::cout << "Current Health: " << currentHealth_ << std::endl;
}
// Function implementation to save submarine's state
void SubmarineMemento::saveSubmarineState() {
    // Save submarine's state to a file or database
    // For simplicity, we will just print the state
    displaySubmarineDetails();
}

// Function implementation to restore submarine's state
void SubmarineMemento::restoreSubmarineState() {
    // Restore submarine's state from a file or database
    // For simplicity, we will just print the state
    displaySubmarineDetails();
}

void SubmarineMemento::updateCurrentPositionX(int currentPositionX) {
    if (currentPositionX < 0) {
        throw std::invalid_argument("Invalid current position X");
    }
    currentPositionX_ = currentPositionX;
}