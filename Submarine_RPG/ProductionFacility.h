#ifndef PRODUCTIONFACILITY_H
#define PRODUCTIONFACILITY_H
#include "iostream"
#include <string>

class ProductionFacility {
private:
    // Member variable to store the name of the production facility
    std::string name_;

    // Member variable to store the cost of producing a submarine
    double productionCost_;

    // Member variable to store the time required to produce a submarine
    double productionTime_;

    // Member variable to store the current resources available for production
    double currentResources_;

    double upgradeCost_;

    // Member variable to store whether the production facility is currently producing a submarine
    bool isProducing_;

    // Member variable to store the production progress of the submarine
    double productionProgress_;

public:
    // Constructor to initialize the production facility with a name, production cost, and production time
    ProductionFacility(std::string name, double productionCost, double productionTime);

    // Getter function to retrieve the name of the production facility
    std::string getName()const;

    // Getter function to retrieve the production cost of a submarine
    double getProductionCost()const;

    // Getter function to retrieve the production time of a submarine
    double getProductionTime()const;

    // Function to produce a submarine, taking into account the production cost and time
    void produceSubmarine();

    // Function to upgrade the production facility, increasing its production efficiency
    void upgradeFacility();// Function to update the production facility's state
    void update();// Function to update the production facility's state
    // Function to add resources to the production facility
    void addResources(double amount);
    // Function to start producing a submarine
    void startProducing();
    void updateProductionProgress(); // Function to update production progress


};

#endif // PRODUCTIONFACILITY_H