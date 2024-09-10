#pragma once
#ifndef MARKET_H
#define MARKET_H

#include <map>
#include <string>
#include <algorithm>
#include "Country.h"
#include "Submarine.h"
#include "Treaty.h"

class Market {
public:
    Market();
    ~Market();

    // Add a country to the market
    void addCountryToMarket(Country* country);

    // Add a submarine for sale to the market
    void addSubmarineForSaleToMarket(Submarine* submarine, std::string countryName);

    // Add an international treaty to the market
    void addTreatyToMarket(Treaty* treaty);

    // Buy a submarine from the market
    void buySubmarineFromMarket(std::string countryName, Submarine* submarine);

    // Sell a submarine to the market
    void sellSubmarineToMarket(std::string countryName, Submarine* submarine);

    // Update maintenance costs for all countries
    void updateMaintenanceCostsForAllCountries();

private:
    // Map of countries in the market
    std::map<std::string, Country*> countryList;

    // Map of submarines for sale in the market
    std::map<std::string, Submarine*> submarinesForSaleList;

    // Map of international treaties in the market
    std::map<std::string, Treaty*> treatyList;
};

#endif // MARKET_H