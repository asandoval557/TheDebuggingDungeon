// Game.h
#ifndef GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include "Country.h"
#include "Submarine.h"
#include "ProductionFacility.h"
#include "Upgrade.h"
#include "wx/wx.h"
#include <iostream>
#include <wx/frame.h>
#include <wx/event.h>
#include <list>
#include "GameLogic.h"
#include "SubmarineMemento.h"
#include "UI.h"
class Game {
public:
    Game(); // Constructor to initialize the game
    ~Game(); // Destructor to clean up resources
    static Game& getInstance();
    void gameLoop(); // Main game loop function
    void submarineDestroyed(Submarine* submarine); // Method to handle submarine destruction
    void checkForWinOrLossConditions();
	void intitializeGame(); // Method to initialize the game  with initial
    void updateGame();
    void renderGame();
    void removeSubmarine(Submarine* submarine);
        static Game* instance_; // Declare the instance_ variable as a static member variable

private:
    std::list<Country*> listOfCountries_; // List of country objects
    std::list<Submarine*> listOfSubmarines_; // List of submarine objects
    std::list<ProductionFacility*> listOfProductionFacilities_; // List of production facility objects
    std::list<Upgrade*> listOfUpgrades_; // List of upgrade objects
    std::list<SubmarineMemento*> listOfSubmarineMementos_;// List   
    GameLogic* gameLogic_; // Game logic object
    bool winConditionMet_; // Flag to check if win condition is met
    bool lossConditionMet_; // Flag to check if loss condition is met
    Game(const Game&);
    SubmarineMemento* createSubmarine(const std::string& hullType, const std::string& propulsionType, const std::string& controlSystemType, const std::string& submarineName, int currentPositionX, int currentDepth, const std::string& hullTypeDescription, const std::string& propulsionSystemType, int maximumDepthRange, int attackPower, int detectionRange, int defenseValue, int movementDistance, const std::string& currentAction, const std::string& submarineOwner, int purchasePrice, int securityClearanceLevel, int monthlyMaintenanceCost);
    void updateSubmarineState(SubmarineMemento* submarine, int currentPositionX, int currentDepth, const std::string& currentAction);
    void saveSubmarineState(SubmarineMemento* submarine);
    void restoreSubmarineState(SubmarineMemento* submarine);

    void displaySubmarineDetails(SubmarineMemento* submarine);
    
    void startGame();
    // Private copy constructor to prevent copying
    Game& operator=(const Game&); // Private assignment operator to prevent assignment
   

};

#endif  GAME_H