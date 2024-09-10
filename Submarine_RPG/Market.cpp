#include "Market.h"

Market::Market() {
    // Initialize the countryList, submarinesForSaleList, and treatyList maps
    countryList = std::map<std::string, Country*>();
    submarinesForSaleList = std::map<std::string, Submarine*>();
    treatyList = std::map<std::string, Treaty*>();
}

Market::~Market() {
    // Destructor
}

void Market::addCountryToMarket(Country* country) {
    // Check if the country is null
    if (country == nullptr) {
        throw std::invalid_argument("Country cannot be null");
    }

    // Check if the country already exists in the market
    if (countryList.find(country->getCountryName()) != countryList.end()) {
        throw std::runtime_error("Country already exists in the market");
    }

    // Add the country to the countryList map with its name as the key
    countryList[country->getCountryName()] = country;
    // Initialize the country's submarines vector
    country->initSubmarines();
}

void Market::addSubmarineForSaleToMarket(Submarine* submarine, std::string countryName) {
    // Check if the submarine is null
    if (submarine == nullptr) {
        throw std::invalid_argument("Submarine cannot be null");
    }

    // Check if the country exists in the market
    if (countryList.find(countryName) == countryList.end()) {
        throw std::runtime_error("Country does not exist in the market");
    }

    // Check if the submarine is already for sale
    if (submarinesForSaleList.find(countryName) != submarinesForSaleList.end()) {
        throw std::runtime_error("Submarine is already for sale");
    }

    // Add the submarine to the submarinesForSaleList map with the country name as the key
    submarinesForSaleList[countryName] = submarine;
}

void Market::addTreatyToMarket(Treaty* treaty) {
    // Check if the treaty is null
    if (treaty == nullptr) {
        throw std::invalid_argument("Treaty cannot be null");
    }

    // Check if the treaty already exists in the market
    if (treatyList.find(treaty->getTreatyName()) != treatyList.end()) {
        throw std::runtime_error("Treaty already exists in the market");
    }

    // Add the treaty to the treatyList map with its name as the key
    treatyList[treaty->getTreatyName()] = treaty;
}

void Market::buySubmarineFromMarket(std::string countryName, Submarine* submarine) {
    // Check if the submarine is null
    if (submarine == nullptr) {
        throw std::invalid_argument("Submarine cannot be null");
    }

    // Check if the country exists in the market
    if (countryList.find(countryName) == countryList.end()) {
        throw std::runtime_error("Country does not exist in the market");
    }

    // Retrieve the Country object from the countryList map
    Country* country = countryList[countryName];

    // Check if the country has enough budget to buy the submarine
    if (country->getBudget() < submarine->getCost()) {
        throw std::runtime_error("Country does not have enough budget to buy the submarine");
    }

    // Check if the submarine is already owned by the country
    if (country->ownsSubmarine(submarine)) {
        throw std::runtime_error("Country already owns the submarine");
    }

    // Remove the submarine from the submarinesForSaleList map
    submarinesForSaleList.erase(countryName);

    // Add the submarine to the country's submarines vector
    country->buySubmarine(submarine);

    // Update the country's budget
    country->setBudget(country->getBudget() - submarine->getCost());
}

void Market::sellSubmarineToMarket(std::string countryName, Submarine* submarinePointer) {
    // Check if the submarine is null
    if (submarinePointer == nullptr) {
        throw std::invalid_argument("Submarine cannot be null");
    }

    // Check if the country exists in the market
    if (countryList.find(countryName) == countryList.end()) {
        throw std::runtime_error("Country does not exist in the market");
    }

    // Check if the country owns the submarine
    Country* country = countryList[countryName];
    auto submarineIterator = std::find(country->getSubmarines().begin(), country->getSubmarines().end(), submarinePointer);
    if (submarineIterator == country->getSubmarines().end())
    {
        throw std::runtime_error("Country does not own the submarine");

        // Remove the submarine from the country's submarines vector
        country->sellSubmarine(submarinePointer);

        // Add the submarine to the submarinesForSaleList map with the country name as the key
        submarinesForSaleList[countryName] = submarinePointer;

        // Update the country's budget
        country->setBudget(country->getBudget() + submarinePointer->getCost());
    }
}

void Market::updateMaintenanceCostsForAllCountries() 
{
    // Iterate over all countries in the countryList map
    for (auto& countryPair : countryList) 
    {
        Country* country = countryPair.second;
        // Update the country's maintenance costs
        country->updateMaintenanceCosts();
    }
}