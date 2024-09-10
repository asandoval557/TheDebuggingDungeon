// Include the Submarine.h header file to access the Submarine class
#include "Submarine.h"
#include "Game.h"
#include "UI.h"


// Constructor to initialize the submarine's properties
Submarine::Submarine(const wxString& submarineName, GameLogic* gameLogic)
    : submarineName_(submarineName), submarineOwner_(nullptr), purchasePrice_(0.0), securityClearanceLevel_(0), currentHealth_(100.0), currentPositionX_(0), currentDepth_(0.0), maximumDepthRange_(500.0), attackPower_(10.0), detectionRange_(200.0), defenseValue_(5.0), movementDistance_(50.0), currentAction_(SubmarineAction::SubmarineActionType::DIVING), gameLogic_(gameLogic), monthlyMaintenanceCost_(0.0), cost_(0), yCoordinate_(0), sonarRange_(100.0), velocityX_(0), velocityY_(0) {}

wxString Submarine::getSubmarineName() {
    return submarineName_;
}

// Method to get the submarine's name
Country* Submarine::getSubmarineOwner() {
    return submarineOwner_;
}
// Return the submarine's name

// Method to get the submarine's x-coordinate
void Submarine::setSubmarineOwner(Country* newOwner) {
    submarineOwner_ = newOwner;
}
// Return the submarine's x-coordinate

// Method to get the submarine's y-coordinate

int Submarine::getSecurityClearanceLevel()
{
    return securityClearanceLevel_;
}
// Return the submarine's y-coordinate

wxString Submarine::getSubmarineName()
{
    return submarineName_;
}

int Submarine::getXCoordinate() const
{
    return currentPositionX_;
}

double Submarine::getCurrentDepth() const
{
    return currentDepth_;
}

// Method to get the submarine's health
double Submarine::getCurrentHealth()
{
    return currentHealth_;
}
// Return the submarine's health

// Method to move the submarine in a specified direction and speed
void Submarine::moveSubmarine(int direction, int speed)
{
    // Check for invalid direction and speed values
    if (direction < 0 || direction > 360 || speed < 0) {
        throw std::invalid_argument("Invalid direction or speed value");
    }
    // Update the submarine's position
    currentPositionX_ += direction * speed;

}

// Method to apply damage to the submarine
void Submarine::takeDamage(double damageValue)
{
    // Check for invalid damage value
    if (damageValue <= 0) {
        throw std::invalid_argument("Invalid damage value");
    }
    // Reduce the submarine's health by the damage value
    currentHealth_ -= damageValue;
    // Check if the submarine's health has reached 0 or below
    if (currentHealth_ <= 0) {
        currentHealth_ = 0; // Ensure health is exactly 0
        // Notify the game that the submarine has been destroyed
        Game::getInstance().submarineDestroyed(this);
    }
}

// Method to get the submarine's torpedo damage
double Submarine::getTorpedoDamageValue()
{ // Return the torpedo damage value based on the submarine's attack power
    return attackPower_ * 10;
}
// Return a fixed value for torpedo damage

// Method to check if the submarine is alive
bool Submarine::isSubmarineAlive()
{
    return currentHealth_ > 0;
}
// Return true if the submarine's health is greater than 0, indicating it is alive

// Method to attack another submarine
void Submarine::attackSubmarine(Submarine* targetSubmarine)
{
    // Calculate the damage value based on the submarine's attack power and the target's defense value
    double damageValue = attackPower_ - targetSubmarine->defenseValue_;
    // Apply the damage to the target submarine
    targetSubmarine->takeDamage(damageValue);
}

// Method to defend against an attack
void Submarine::defendAgainstAttack(double damageValue)
{
    // Reduce the damage value based on the submarine's defense value
    damageValue -= defenseValue_;
    // Apply the reduced damage to the submarine
    takeDamage(damageValue);
}

// Method to surface the submarine
void Submarine::surfaceSubmarine() {
    // Update the submarine's action to SURFACING
    currentAction_ = SubmarineAction::SubmarineActionType::SURFACING;
}

// Method to dive the submarine
void Submarine::diveSubmarine()
{
    // Update the submarine's action to DIVING
    currentAction_ = SubmarineAction::SubmarineActionType::DIVING;
}

// Method to save the submarine's state
SubmarineMemento* Submarine::saveSubmarineState()
{  // Check if gameLogic_ is null before creating a SubmarineMemento object
    try {
        // Create a new SubmarineMemento object to store the submarine's state
        std::shared_ptr<GameLogic> gameLogicPtr = std::shared_ptr<GameLogic>(gameLogic_);
        SubmarineMemento* memento = new SubmarineMemento(
            hullType_, propulsionType_, controlSystemType_, submarineName_, currentPositionX_, currentDepth_,
            hullTypeDescription_, propulsionSystemType_, maximumDepthRange_, attackPower_, detectionRange_,
            defenseValue_, movementDistance_, currentAction_, submarineOwner_, purchasePrice_,
            securityClearanceLevel_, monthlyMaintenanceCost_, gameLogicPtr
        );
        return memento;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error creating SubmarineMemento: " << e.what() << std::endl;
        return nullptr;
    }
}

// Method to restore the submarine's state
void Submarine::restoreSubmarineState(SubmarineMemento* memento)
{
    // Restore the submarine's state from the memento
    submarineName_ = memento->getSubmarineName();
    currentPositionX_ = memento->getCurrentPositionX();
    currentDepth_ = memento->getCurrentDepth();
    currentHealth_ = memento->getCurrentHealth();
    hullTypeDescription_ = memento->getHullTypeDescription();
    propulsionSystemType_ = memento->getPropulsionSystemType();
    controlSystemType_ = memento->getControlSystemType();
    maximumDepthRange_ = memento->getMaximumDepthRange();
    attackPower_ = memento->getAttackPower();
    detectionRange_ = memento->getDetectionRange();
    defenseValue_ = memento->getDefenseValue();
    movementDistance_ = memento->getMovementDistance();

    try {
        // Create a new SubmarineAction object from the current action string
        // This could throw an exception if the action string is invalid
        // Convert the action string to the correct type (e.g., an enum)
        SubmarineAction::SubmarineActionType actionType = memento->getActionType();

      
    }
    catch (const std::invalid_argument& e) {
        // Handle the error case where the current action string is invalid
        // This could involve setting a default action or logging an error message
        std::cerr << "Error: " << e.what() << std::endl;
        SubmarineAction::SubmarineActionType actionType = SubmarineAction::SubmarineActionType::DIVING;
        currentAction_ = SubmarineAction(actionType);
    }

    submarineOwner_ = Country::createFromName(memento->getSubmarineOwner());
    purchasePrice_ = memento->getPurchasePrice();
    securityClearanceLevel_ = memento->getSecurityClearanceLevel();
    monthlyMaintenanceCost_ = memento->getMonthlyMaintenanceCost();
}

// Method to perform an emergency dive
void Submarine::emergencyDiveSubmarine()
{
    // Update the submarine's action to EMERGENCY DIVING
    currentAction_ = SubmarineAction::SubmarineActionType::DIVING;
    // Reduce the submarine's health by 10
    currentHealth_ -= 10;
}
double Submarine::getMaximumDepthRange()const
{
    return maximumDepthRange_;
}
void Submarine::increaseAttackPower(int amount)
{
    attackPower_ += amount;
}
void Submarine::increaseDefenseValue(int amount) {
    defenseValue_ += amount;
}
void Submarine::increaseMovementDistance(int amount)
{
    movementDistance_ += amount;
}
void Submarine::increaseDetectionRange(int amount)
{
    detectionRange_ += amount;
}
double Submarine::getMonthlyMaintenanceCost()
{
    return monthlyMaintenanceCost_;
}
int Submarine::getCost()
{
    return cost_;;
}
void Submarine::updateMonthlyMaintenanceCost()
{ 
    // Update the monthly maintenance cost based on the submarine's properties
    monthlyMaintenanceCost_ = purchasePrice_ * 0.1;

}

// Method to get the purchase price
double Submarine::getPurchasePrice() {
    return purchasePrice_;
}double Submarine::getYCoordinate() const {
    return yCoordinate_;
}

// Method to calculate the submarine's monthly maintenance cost
double Submarine::calculateMaintenanceCost() {
    // Calculate the maintenance cost based on the submarine's current state
    double maintenanceCost = 0.0;
    maintenanceCost += purchasePrice_ * 0.01; // 1% of purchase price
    maintenanceCost += securityClearanceLevel_ * 10.0; // security clearance level x 10
    maintenanceCost += monthlyMaintenanceCost_ * 0.05; // 5% of current maintenance cost
    return maintenanceCost;
}
// This function returns a vector of pointers to Submarine objects that are within a certain radius of the current submarine.
std::vector<Submarine*> Submarine::getNearbySubmarines()  {
    // Create an empty vector to store the nearby submarines.
    std::vector<Submarine*> nearbySubmarines;

    // Iterate over all submarines in the game.
    for (Submarine* otherSubmarine : allSubmarines) {
        // Check if the current submarine is not the same as the other submarine (to avoid counting itself as nearby).
        if (otherSubmarine != this) {
            // Calculate the distance between the current submarine and the other submarine.
            // The distanceBetween function is not shown here, but it would take two Submarine objects as parameters and return the distance between them.
            if (otherSubmarine != this && distanceBetween(this, otherSubmarine) <= sonarRange_) {

                // If the distance is less than the specified radius, add the other submarine to the vector of nearby submarines.
                nearbySubmarines.push_back(otherSubmarine);
            }
        }
    }

    // Return the vector of nearby submarines.
    return nearbySubmarines;
}

double Submarine::distanceBetween(Submarine* submarine1, Submarine* submarine2)
{
    if (submarine1 == nullptr || submarine2 == nullptr) {
        std::cerr << "Error: Null submarine pointer." << std::endl;
        return -1.0; // Return an error value
    }

    double deltaX = submarine1->getXCoordinate() - submarine2->getXCoordinate();
    double deltaY = submarine1->getCurrentDepth() - submarine2->getCurrentDepth();

    double distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    return distance;
}

void Submarine::update()
{// Update the submarine's position based on its velocity
    currentPositionX_ += velocityX_;
    currentPositionX_ += velocityY_;

    // Check for boundary collisions (e.g., with the ocean floor or surface)
    if (yCoordinate_ < 0) {
        yCoordinate_ = 0; // Prevent the submarine from going below the ocean floor
    }
    else if (yCoordinate_ > 100) {
        yCoordinate_ = 100; // Prevent the submarine from going above the ocean surface
    }

    // Update the submarine's health (e.g., due to damage or repairs)
    currentHealth_ -= 0.1; // Simulate gradual health loss over time

    // Check for game-over conditions (e.g., if the submarine's health reaches 0)
    if (currentHealth_ <= 0) {
        std::cout << "Submarine " << submarineName_ << " has been destroyed!" << std::endl;
        // Game over! Handle the consequences (e.g., reset the game or display a game-over screen)
    }
}

// Getter function to retrieve attack power
int Submarine::getAttackPower() {
    // Return the submarine's attack power
    return attackPower_;
}
// Getter function to retrieve defense value
int Submarine::getDefenseValue() {
    // Return the submarine's defense value
    return defenseValue_;
}
