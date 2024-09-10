#ifndef SUBMARINE_H
#define SUBMARINE_H
#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <wx/string.h>
#include "SubmarineMemento.h"
#include "Combat.h"
#include "GameLogic.h"
#include "PropulsionSystem.h"
#include "Country.h"
#include"SubmarineAction.h"
class Submarine {
private:
    bool hasFunctionalSonar_; // Declare hasFunctionalSonar_ member variable
    int cost_; // assuming cost_ is a member variable of Submarine
    double sonarRange_; // Declare sonarRange_ member variable
    PropulsionSystem* propulsionSystem_; // declare propulsionSystem_ as a pointer to PropulsionSystem
    double currentDepth_; // Declare currentDepth_ member variable

    // wxString to store the name of the submarine
    wxString submarineName_;

    // Integer to store the current x-coordinate of the submarine
    int currentPositionX_;

    std::string hullType_; // Declare the variable
    std::string propulsionType_; // Declare the variable
    // Double to store the current health of the submarine
    double currentHealth_;

    // String to store the hull type description of the submarine
    std::string hullTypeDescription_;

    // String to store the propulsion system type of the submarine
    std::string propulsionSystemType_;

    // String to store the control system type of the submarine
    std::string controlSystemType_;

    // Double to store the maximum depth range of the submarine
    double maximumDepthRange_;

    double attackPower_; // attack power of the submarine
    double detectionRange_; // detection range of the submarine
    double defenseValue_; // defense value of the submarine
    double movementDistance_; // movement distance of the submarine

    // Pointer to a Country object to store the owner of the submarine
    Country* submarineOwner_;

    // Double to store the price of the submarine
    double purchasePrice_;

    // Integer to store the security clearance of the submarine
    int securityClearanceLevel_;

    // Double to store the monthly maintenance cost of the submarine
    double monthlyMaintenanceCost_;
    std::vector<Submarine*> allSubmarines; // Define a vector to hold all submarines
    std::vector<Submarine*> getNearbySubmarines() ; // Declare getNearbySubmarines function
    static double distanceBetween(Submarine* submarine1, Submarine* submarine2);
    GameLogic* gameLogic_; // Declare gameLogic_ as a member variable

    double yCoordinate_;
    int defaultActionType = 0; // or any other suitable type and value
    // Current action of the submarine (e.g. DIVING, SURFACING, etc.)
    SubmarineAction::SubmarineActionType currentAction_;
    double velocityX_;
    double velocityY_;



public:
    // Constructor to initialize the submarine's properties
    Submarine(const wxString& submarineName, GameLogic* gameLogic);
    bool hasFunctionalSonar() const { return hasFunctionalSonar_; } // Declare hasFunctionalSonar function
    double getSonarRange() const { return sonarRange_; } // Declare getSonarRange function

    void setCurrentDepth(double depth) { currentDepth_ = depth; } // Declare setCurrentDepth function

    // Getter function to return the owner of the submarine
    Country* getSubmarineOwner();

    // Setter function to set a new owner for the submarine
    void setSubmarineOwner(Country* newOwner);

    // Getter function to return the price of the submarine
    double getPurchasePrice();

    double calculateMaintenanceCost();

    // Getter function to return the security clearance of the submarine
    int getSecurityClearanceLevel();

    // Getter function to return the monthly maintenance cost of the submarine
   
    int getCost();
   
    // Function to get the y-coordinate of the submarine
    double getYCoordinate() const;
    wxString getSubmarineName();

    int getXCoordinate() const;

    double getCurrentDepth()const;

    double getCurrentHealth();

    void moveSubmarine(int direction, int speed);

    void takeDamage(double damageValue);

    double getTorpedoDamageValue();

    bool isSubmarineAlive();

    void attackSubmarine(Submarine* targetSubmarine);

    void defendAgainstAttack(double damageValue);

    void surfaceSubmarine();

    void diveSubmarine();

    SubmarineMemento* saveSubmarineState();

    void restoreSubmarineState(SubmarineMemento* memento);

    void emergencyDiveSubmarine();

    double getMaximumDepthRange() const;

    void increaseAttackPower(int amount);

    void increaseDefenseValue(int amount);

    void increaseMovementDistance(int amount);

    void increaseDetectionRange(int amount);

    double getMonthlyMaintenanceCost(); // getter for maintenance cost
    void updateMonthlyMaintenanceCost(); // update maintenance cost method
    void update(); // Add this function declaration
   



    // Getter function to retrieve attack power
    int getAttackPower();


    // Getter function to retrieve defense value
    int getDefenseValue();

};

#endif // SUBMARINE_H