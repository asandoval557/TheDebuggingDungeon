#include "combat.h"
#include <stdexcept>

// Constructor to initialize the combat engagement
Combat::Combat(Submarine* attacker, Submarine* defender) : attacker_(attacker), defender_(defender) {
    // Check if the attacker and defender are not null
    if (attacker == nullptr || defender == nullptr) {
        // Throw an exception if either the attacker or defender is null
        throw std::invalid_argument("Attacker and defender must not be null");
    }
}

double Combat::calculateDamage() {
    // Calculate the damage dealt based on the attacker's and defender's upgrades and stats
    double damageDealt = attacker_->getAttackPower() - defender_->getDefenseValue();
    if (damageDealt < 0) {
        // Ensure the damage dealt is not negative
        damageDealt = 0;
    }
    return damageDealt;
}

// Method to engage in combat between the attacker and defender
void Combat::engageCombat() {
    // Check if the attacker and defender are alive
    if (!attacker_->isSubmarineAlive() || !defender_->isSubmarineAlive()) {
        // Throw an exception if either the attacker or defender is not alive
        throw std::runtime_error("Both attacker and defender must be alive to engage in combat");
    }

    // Engage in combat between the attacker and defender
    double damageDealt = calculateDamage();
    defender_->takeDamage(damageDealt);
}

// Method to get the damage dealt in the combat
double Combat::getDamageDealt() {
    // Return the damage dealt in the combat
    return damageDealt_;
}