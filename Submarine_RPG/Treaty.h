#pragma once
#ifndef TREATY_H
#define TREATY_H
#include <string>
#include "iostream"
class Treaty {
public:
    // Constructor to create a new Treaty object
    Treaty(std::string treatyName, std::string country1, std::string country2, double effect);

    // Getter method to retrieve the treaty name
    std::string getTreatyName();

    // Method to check if the treaty applies to a specific country pair
    bool appliesTo(std::string country1, std::string country2);

    // Getter method to retrieve the treaty effect
    double getEffect();

private:
    std::string name_; // Treaty name
    std::string country1_; // Country 1 involved in the treaty
    std::string country2_; // Country 2 involved in the treaty
    double effect_; // Treaty effect
};

#endif // TREATY_H

