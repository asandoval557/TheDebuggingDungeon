#include "Game.h"
#include "SubmarineMemento.h"


// Singleton instance
Game* Game::instance_ = nullptr;
Game::Game(): gameLogic_ (new GameLogic())
{
    // Initialize the game logic
    winConditionMet_ = false;
    lossConditionMet_ = false;

    // Initialize lists of countries, submarines, production facilities, and upgrades
    listOfCountries_ = std::list<Country*>();
    listOfSubmarines_ = std::list<Submarine*>();
    listOfProductionFacilities_ = std::list<ProductionFacility*>();
    listOfUpgrades_ = std::list<Upgrade*>();

  
    // Create a Submarine object with a GameLogic object
    Submarine* submarine = new Submarine("Submarine 1", gameLogic_);

    // Create a SubmarineMemento object with all 19 required arguments
    SubmarineMemento* submarineMemento = new SubmarineMemento(
        "Hull Type",
        "Propulsion Type",
        "Control System Type",
        "Submarine 1",
        10,
        20,
        "Hull Type Description",
        "Propulsion System Type",
        100,
        50,
        200,
        30,
        40,
        "Idle",
        "Player 1",
        1000,
        5,
        100,
        gameLogic_
    );
    // Add the Submarine object to the list of submarines
    listOfSubmarines_.push_back(submarine);

    // Add the SubmarineMemento object to the list of submarines (or wherever you want to store it)
    listOfSubmarineMementos_.push_back(submarineMemento);
}

Game::~Game() 
{
    // Clean up resources
    delete gameLogic_;
    for (auto& country : listOfCountries_) {
        delete country;
    }
    for (auto& submarine : listOfSubmarines_) {
        delete submarine;
    }
    for (auto& productionFacility : listOfProductionFacilities_) {
        delete productionFacility;
    }
    for (auto& upgrade : listOfUpgrades_) {
        delete upgrade;
    }
    for (auto& submarineMemento : listOfSubmarineMementos_) {
        delete submarineMemento;
    }
}

Game& Game::getInstance()
{
    if (!instance_) {
        instance_ = new Game();
    }
    return *instance_;
	// This ensures that the singleton instance is created only once.
}

void Game::gameLoop() {
    while (!winConditionMet_ && !lossConditionMet_)
    {
        // Update game state
        gameLogic_->updateGameLogic();
        // Check for win or loss conditions
        checkForWinOrLossConditions();
    }
}

void Game::submarineDestroyed(Submarine* submarine)
{
    // Method to handle submarine destruction
    if (submarine == nullptr) {
        std::cerr << "Error: Null submarine pointer." << std::endl;
        return;
    }
    // Remove the submarine from the list of submarines
    listOfSubmarines_.remove(submarine);
    // Delete the submarine object
    delete submarine;
}

void Game::checkForWinOrLossConditions()
{
    // Check for win or loss conditions
    if (gameLogic_->checkForWinConditions()) {
        winConditionMet_ = true;
    }
    else if (gameLogic_->checkForLossConditions()) {
        lossConditionMet_ = true;
    }
}

void Game::initializeGame() {
    // Initialize game variables and settings
    gameTitle_ = "Submarine Game";
    gameDifficultyLevel_ = 1;

    // Load game resources (e.g., images, sounds, fonts)
    loadResources();

    // Initialize the game window and graphics
    initWindow();
    initGraphics();

    // Initialize the game loop
    gameLoopRunning_ = true;

    // Initialize the list of submarines
    listOfSubmarines_.clear();

    // Add some initial submarines to the game
    addSubmarine(new Submarine());
    addSubmarine(new Submarine());
}

void Game::updateGame() {
    // Update the game logic
    gameLogic_->updateGameLogic();

    // Update the submarines
    for (auto& submarine : listOfSubmarines_) {
        submarine->update();
    }

    // Update the UI
    UI* ui = new UI(gameLogic_, "Combat Simulator");
    ui->createCombatSimulatorUI();
    ui->Show(true);
}

void Game::renderGame() {
    // Render the game elements
    for (auto& submarine : listOfSubmarines_) {
        // Render the submarine
        submarine->render();
    }

    // Render the UI
    UI* ui = new UI(gameLogic_, "Combat Simulator");
    ui->createCombatSimulatorUI();
    ui->Show(true);
}

void Game::removeSubmarine(Submarine* submarine)
{
    // Remove the submarine from the list of submarines
    listOfSubmarines_.remove(submarine);
    // Delete the submarine object
    delete submarine;
}


// Function implementation to create a new submarine
SubmarineMemento* Game::createSubmarine(const std::string& hullType, const std::string& propulsionType, const std::string& controlSystemType,
    const std::string& submarineName, int currentPositionX, int currentDepth,
    const std::string& hullTypeDescription, const std::string& propulsionSystemType,
    int maximumDepthRange, int attackPower, int detectionRange, int defenseValue,
    int movementDistance, const std::string& currentAction, const std::string& submarineOwner,
    int purchasePrice, int securityClearanceLevel, int monthlyMaintenanceCost) {
    return gameLogic_->createSubmarine(hullType, propulsionType, controlSystemType, submarineName, currentPositionX, currentDepth,
        hullTypeDescription, propulsionSystemType, maximumDepthRange, attackPower, detectionRange, defenseValue,
        movementDistance, currentAction, submarineOwner, purchasePrice, securityClearanceLevel, monthlyMaintenanceCost);
}

// Function implementation to update submarine's state
void Game::updateSubmarineState(SubmarineMemento* submarine, int currentPositionX, int currentDepth, const std::string& currentAction) {
    gameLogic_->updateSubmarineState(submarine, currentPositionX, currentDepth, currentAction);
}

// Function implementation to save submarine's state
void Game::saveSubmarineState(SubmarineMemento* submarine) {
    gameLogic_->saveSubmarineState(submarine);
}

// Function implementation to restore submarine's state
void Game::restoreSubmarineState(SubmarineMemento* submarine) {
    gameLogic_->restoreSubmarineState(submarine);
}

// Function implementation to display submarine's details
void Game::displaySubmarineDetails(SubmarineMemento* submarine) {
    gameLogic_->displaySubmarineDetails(submarine);
}

// Function implementation to start the game
void Game::startGame() {
    // Create a new submarine
    SubmarineMemento* submarine = createSubmarine("Hull Type 1", "Propulsion Type 1", "Control System Type 1", "Submarine 1", 0, 0,
        "Hull Type Description 1", "Propulsion System Type 1", 100, 10, 50, 20, 5, "Idle", "Player 1", 1000, 1, 100);

    // Update submarine's state
    updateSubmarineState(submarine, 10, 20, "Moving");

    // Save submarine's state
    saveSubmarineState(submarine);

    // Restore submarine's state
    restoreSubmarineState(submarine);

    // Display submarine's details
    displaySubmarineDetails(submarine);
}

Game& Game::operator=(const Game& other)
{
  
    if (this != &other) {
        // Copy game logic and other game components
        gameLogic_ = new GameLogic(*other.gameLogic_);
        listOfCountries_ = other.listOfCountries_;
        listOfSubmarines_ = other.listOfSubmarines_;
        listOfProductionFacilities_ = other.listOfProductionFacilities_;
        listOfUpgrades_ = other.listOfUpgrades_;
        listOfSubmarineMementos_ = other.listOfSubmarineMementos_;
        winConditionMet_ = other.winConditionMet_;
        lossConditionMet_ = other.lossConditionMet_;
    }
    return *this;
}

