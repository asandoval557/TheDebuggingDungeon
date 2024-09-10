#pragma once
#ifndef COMBAT_H
#define COMBAT_H

// Include the submarine.h file to use the Submarine class
#include "submarine.h"

// Define the Combat class to represent a combat engagement
class Combat {
public:
    // Constructor to initialize the combat engagement
    Combat(Submarine* attacker, Submarine* defender);
        double calculateDamage();

    // Method to engage in combat between the attacker and defender
    void engageCombat();

    // Method to get the damage dealt in the combat
    double getDamageDealt();

private:
    // Pointer to the attacker submarine
    Submarine* attacker_;

    // Pointer to the defender submarine
    Submarine* defender_;
    double damageDealt_;
};

#endif // COMBAT_H
