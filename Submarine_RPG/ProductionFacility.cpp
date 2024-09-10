#include "ProductionFacility.h"

// Constructor to initialize the production facility with a name, production cost, and production time
ProductionFacility::ProductionFacility(std::string name, double productionCost, double productionTime)
    : name_(std::move(name)), productionCost_(productionCost), productionTime_(productionTime) {
    // Initialize the production facility with the given name, production cost, and production time
}

// Getter function to retrieve the name of the production facility
std::string ProductionFacility::getName()const {
    return name_;
}

// Getter function to retrieve the production cost of a submarine
double ProductionFacility::getProductionCost() const {
    return productionCost_;
}

// Getter function to retrieve the production time of a submarine
double ProductionFacility::getProductionTime() const {
    return productionTime_;
}

// Function to produce a submarine, taking into account the production cost and time
void ProductionFacility::produceSubmarine() {
    try {
        // Check if the production facility has enough resources to produce a submarine
        if (currentResources_ < productionCost_) {
            throw std::runtime_error("Insufficient resources to produce a submarine");
        }

        // Deduct the production cost from the current resources
        currentResources_ -= productionCost_;

        // Add the submarine to the game world
        // ...

        // Update the production facility's state
        update();
    }
    catch (const std::exception& e) {
        // Handle the error
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Function to upgrade the production facility, increasing its production efficiency
void ProductionFacility::upgradeFacility() {
    try {
        // Check if the production facility has enough resources to upgrade
        if (currentResources_ < upgradeCost_) {
            throw std::runtime_error("Insufficient resources to upgrade the production facility");
        }

        // Deduct the upgrade cost from the current resources
        currentResources_ -= upgradeCost_;

        // Increase the production efficiency of the facility
        productionCost_ *= 0.9;
        productionTime_ *= 0.9;

        // Update the production facility's state
        update();
    }
    catch (const std::exception& e) {
        // Handle the error
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void ProductionFacility::update()
{
    // Update the production facility's state
  
    if (isProducing_)
    {
        productionProgress_ += productionTime_;
        if (productionProgress_ >= 1.0)
        {
            // Submarine production complete!
            isProducing_ = false;
            productionProgress_ = 0.0;
            // Add the submarine to the game world
            // ...
        }
    }
}

void ProductionFacility::addResources(double amount) {
    // Add resources to the production facility
    currentResources_ += amount;
}


void ProductionFacility::startProducing() {
    // Start producing a submarine
    isProducing_ = true;
    productionProgress_ = 0.0;
}
// Function to update production progress
void ProductionFacility::updateProductionProgress() {
    // Check if production progress is within valid range (0-100)
    if (productionProgress_ < 0 || productionProgress_ > 100) {
        throw std::runtime_error("Production progress out of range (0-100)");
    }

    // Update production progress by 10 units
    productionProgress_ += 10;

    // Check if production progress has exceeded 100
    if (productionProgress_ > 100) {
        productionProgress_ = 100; // Cap production progress at 100
    }
}