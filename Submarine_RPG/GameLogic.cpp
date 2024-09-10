// GameLogic.cpp
#include "GameLogic.h"


GameLogic::GameLogic() {
    // Initialize the game state
    initGameState();
}

GameLogic::~GameLogic() {
    // Deallocate memory for game objects
    countries_.clear();
    submarines_.clear();
    productionFacilities_.clear();
}

void GameLogic::initGameState() {
    // Create initial game objects
    countries_.emplace_back(std::make_shared<Country>("USA"));
    countries_.emplace_back(std::make_shared<Country>("Russia"));
    submarines_.emplace_back(std::make_shared<Submarine>("Submarine 1", countries_[0]));
    productionFacilities_.emplace_back(std::make_shared<ProductionFacility>("Production Facility 1", countries_[0]));
}

void GameLogic::updateGameLogic() {
    // Update the game state based on current game logic
    try {
        for (auto& submarine : submarines_) {
            submarine->update();
        }
        for (auto& productionFacility : productionFacilities_) {
            productionFacility->update();
        }
    }
    catch (const std::exception& e) {
        // Handle the error
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

bool GameLogic::checkForWinConditions() {
    // Check if the game has been won
    for (auto& country : countries_) {
        if (country->getHealth() <= 0) {
            // Game over, player wins
            std::cout << "Player wins!" << std::endl;
            return true;
        }
    }
    return false;
}

bool GameLogic::checkForLossConditions()
{
    // Check for win conditions
    for (auto& country : countries_) {
        if (country->getPlayerControlled() && country->getHealth() <= 0) {
            // Game over, player loses
            std::cout << "Player loses!" << std::endl;
            return true;
        }
    }
    return false;
}

std::vector<std::shared_ptr<Country>>& GameLogic::getCountries() {
    return countries_;
}

std::vector<std::shared_ptr<Submarine>>& GameLogic::getSubmarines() {
    return submarines_;
}

std::vector<std::shared_ptr<ProductionFacility>>& GameLogic::getProductionFacilities() {
    return productionFacilities_;
}
// Function implementation to create a new submarine
SubmarineMemento* GameLogic::createSubmarine(const std::string& hullType, const std::string& propulsionType, const std::string& controlSystemType,
    const std::string& submarineName, int currentPositionX, int currentDepth,
    const std::string& hullTypeDescription, const std::string& propulsionSystemType,
    int maximumDepthRange, int attackPower, int detectionRange, int defenseValue,
    int movementDistance, const std::string& currentAction, const std::string& submarineOwner,
    int purchasePrice, int securityClearanceLevel, int monthlyMaintenanceCost) {
    return new SubmarineMemento(hullType, propulsionType, controlSystemType, submarineName, currentPositionX, currentDepth,
        hullTypeDescription, propulsionSystemType, maximumDepthRange, attackPower, detectionRange, defenseValue,
        movementDistance, currentAction, submarineOwner, purchasePrice, securityClearanceLevel, monthlyMaintenanceCost, this);
}

// Function implementation to update submarine's state
void GameLogic::updateSubmarineState(SubmarineMemento* submarine, int currentPositionX, int currentDepth, const std::string& currentAction) {
    submarine->updateCurrentPosition(currentPositionX, currentDepth);
    submarine->updateCurrentAction(currentAction);
}

// Function implementation to save submarine's state
void GameLogic::saveSubmarineState(SubmarineMemento* submarine) {
    submarine->saveSubmarineState();
}

// Function implementation to restore submarine's state
void GameLogic::restoreSubmarineState(SubmarineMemento* submarine) {
    submarine->restoreSubmarineState();
}

void GameLogic::displaySubmarineDetails(SubmarineMemento* submarine) {
    std::cout << "Submarine Name: " << submarine->getSubmarineName() << std::endl;
    std::cout << "Hull Type: " << submarine->getHullType() << std::endl;
    std::cout << "Propulsion Type: " << submarine->getPropulsionType() << std::endl;
    std::cout << "Control System Type: " << submarine->getControlSystemType() << std::endl;
    std::cout << "Current Position X: " << submarine->getCurrentPositionX() << std::endl;
    std::cout << "Current Depth: " << submarine->getCurrentDepth() << std::endl;
    std::cout << "Current Action: " << submarine->getCurrentAction() << std::endl;
}
