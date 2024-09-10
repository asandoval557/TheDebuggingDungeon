#pragma once
// GameLogic.h
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <vector>
#include <memory>

class Submarine;
class ProductionFacility;
class Country;

class GameLogic {
public:
    GameLogic();
    ~GameLogic();

    // Initialize the game state
    void initGameState();

    // Update the game state based on current game logic
    void updateGameLogic();

    // Check if the game has been won or lost
    bool checkForWinConditions();
    bool checkForLossConditions();

    // Get the list of countries
    std::vector<std::shared_ptr<Country>>& getCountries();

    // Get the list of submarines
    std::vector<std::shared_ptr<Submarine>>& getSubmarines();

    // Get the list of production facilities
    std::vector<std::shared_ptr<ProductionFacility>>& getProductionFacilities();

    SubmarineMemento* createSubmarine(const std::string& hullType, const std::string& propulsionType, const std::string& controlSystemType, const std::string& submarineName, int currentPositionX, int currentDepth, const std::string& hullTypeDescription, const std::string& propulsionSystemType, int maximumDepthRange, int attackPower, int detectionRange, int defenseValue, int movementDistance, const std::string& currentAction, const std::string& submarineOwner, int purchasePrice, int securityClearanceLevel, int monthlyMaintenanceCost);

    void updateSubmarineState(SubmarineMemento* submarine, int currentPositionX, int currentDepth, const std::string& currentAction);

    void saveSubmarineState(SubmarineMemento* submarine);

    void restoreSubmarineState(SubmarineMemento* submarine);
    void displaySubmarineDetails(SubmarineMemento* submarine);

private:
    // List of countries
    std::vector<std::shared_ptr<Country>> countries_;

    // List of submarines
    std::vector<std::shared_ptr<Submarine>> submarines_;

    // List of production facilities
    std::vector<std::shared_ptr<ProductionFacility>> productionFacilities_;
};

#include "Submarine.h"
#include "ProductionFacility.h"
#include "Country.h"
#include "SubmarineMemento.h"
#endif // GAMELOGIC_H

