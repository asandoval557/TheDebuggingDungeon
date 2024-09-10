#pragma once
#ifndef COUNTRY_H
#define COUNTRY_H
#include <string>
#include <vector>
#include "Submarine.h"

// Forward declaration of the Market class
class Market;

class Country {
private:
    // Member variables
    std::string countryName; // The name of the country
    std::vector<Submarine*> submarines; // A vector of pointers to Submarine objects owned by the country
    double budget; // The country's budget
    double health; // The country's health (newly added)
    
    bool playerControlled_; // Flag to indicate if the country is player-controlled
   


public:
   
    static Country createFromName(const std::string& countryName);


   
    std::string getCountryName();

    // Getter function to retrieve a vector of Submarine objects owned by the country
    std::vector<Submarine*> getSubmarines();

    // Getter function to retrieve the country's budget
    double getBudget();

    // Setter function to set the country's budget
    void setBudget(double newBudget);

    // Function to buy a Submarine object from the market
    void buySubmarine(Submarine* submarine);

    // Function to sell a Submarine object to the market
    void sellSubmarine(Submarine* submarine);

    void updateMaintenanceCosts();
    // Friend class declaration to allow the Market class to access Country's private members
    
    void initSubmarines();
    double getHealth(); // Add this function declaration
    bool ownsSubmarine(Submarine* submarine);
    bool getPlayerControlled(); // Add this function declaration
    Country createCountryFromName(const std::string& name);
    Country(std::string countryName, double budget /* = 0.0 */);
    friend class Market;
};

#endif
