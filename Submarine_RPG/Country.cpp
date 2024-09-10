#include "Country.h"
#include "Market.h"




Country::Country(std::string countryName, double budget /* = 0.0 */)
    : countryName(countryName), budget(budget), health(100.0), playerControlled_(false) {
    // Initialize the vector of submarines
    submarines = std::vector<Submarine*>();
}

// Getter function implementation to retrieve the country's name
std::string Country::getCountryName() 
{
    return countryName;
}

// Getter function implementation to retrieve a vector of Submarine objects owned by the country
std::vector<Submarine*> Country::getSubmarines() 
{
    return submarines;
}

// Getter function implementation to retrieve the country's budget
double Country::getBudget()
{
    return budget;
}

// Setter function implementation to set the country's budget
void Country::setBudget(double newBudget) {
    budget = newBudget;
}

// Function implementation to buy a Submarine object from the market
void Country::buySubmarine(Submarine* submarine)
{
    // Check if the country has enough budget to buy the submarine
    if (budget >= submarine->getSubmarineOwner()->getBudget()) 
    {
        // Set the submarine's owner to the current country
        submarine->setSubmarineOwner(this);
        // Add the submarine to the country's vector of submarines
        submarines.push_back(submarine);
        // Deduct the submarine's cost from the country's budget
        budget -= submarine->getSubmarineOwner()->getBudget();
        // Set the previous owner's budget to 0
        submarine->getSubmarineOwner()->setBudget(0);
    }
    else 
    {
        // Error handling: not enough budget to buy the submarine
        std::cerr << "Error: Not enough budget to buy the submarine." << std::endl;
    }
}

// Function implementation to sell a Submarine object to the market
void Country::sellSubmarine(Submarine* submarine)
{
    // Check if the country owns the submarine
    if (ownsSubmarine(submarine)) 
    {
        // Remove the submarine from the country's vector of submarines
        submarines.erase(std::remove(submarines.begin(), submarines.end(), submarine), submarines.end());
        // Add the submarine's cost to the country's budget
        budget += submarine->getSubmarineOwner()->getBudget();
        // Set the submarine's owner to nullptr
        submarine->setSubmarineOwner(nullptr);
        // Set the previous owner's budget to 0
        submarine->getSubmarineOwner()->setBudget(0);
    }
    else
    {
        // Error handling: country does not own the submarine
        std::cerr << "Error: Country does not own the submarine." << std::endl;
    }
}

void Country::updateMaintenanceCosts()
{ // Update the maintenance costs for all submarines
    for (Submarine* submarine : submarines) 
    {
        submarine->updateMonthlyMaintenanceCost();
    }
}

void Country::initSubmarines()
{
    this->submarines = std::vector<Submarine*>();
}

double Country::getHealth()
{
    return health; // Retrieve the country's health
}

bool Country::ownsSubmarine(Submarine* submarine)
{
    // Check if the submarine is in the country's submarines vector
    return std::find(submarines.begin(), submarines.end(), submarine) != submarines.end();

}
bool Country::getPlayerControlled()
{
    // Return the player-controlled flag
    return playerControlled_;
}
Country Country::createCountryFromName(const std::string& name)
{
    if (name.empty()) {
        throw std::invalid_argument("Country name cannot be empty");
    }

    Country country(name, 0.0); // Create a new country object with the given name and default budget
    return country;
}
