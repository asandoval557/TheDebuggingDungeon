#include "Treaty.h"

Treaty::Treaty(std::string treatyName, std::string country1, std::string country2, double effect)
    : name_(treatyName), country1_(country1), country2_(country2), effect_(effect) {}

std::string Treaty::getTreatyName() {
    return name_; // Return the treaty name
}

bool Treaty::appliesTo(std::string country1, std::string country2) {
    // Check if the treaty applies to the specified country pair
    return (country1_ == country1 && country2_ == country2) || (country1_ == country2 && country2_ == country1);
}

double Treaty::getEffect() {
    return effect_; // Return the treaty effect
}