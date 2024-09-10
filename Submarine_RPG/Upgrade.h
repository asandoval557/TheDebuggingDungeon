#pragma once
// Upgrade.h
#ifndef UPGRADE_H
#define UPGRADE_H

// Forward declaration of Submarine class
class Submarine;

class Upgrade {
public:
    /**
     * Enum to represent different types of upgrades
     * ATTACK_UPGRADE: Increases submarine's attack power
     * DEFENSE_UPGRADE: Increases submarine's defense value
     * SPEED_UPGRADE: Increases submarine's movement distance
     * DETECTION_UPGRADE: Increases submarine's detection range
     */
    enum class UpgradeType {
        ATTACK_UPGRADE,
        DEFENSE_UPGRADE,
        SPEED_UPGRADE,
        DETECTION_UPGRADE
    };

    /**
     * Constructor to create an Upgrade object
     * @param upgradeType: Type of upgrade (attack, defense, speed, or detection)
     * @param level: Level of the upgrade (1, 2, 3, etc.)
     * @param cost: Cost of the upgrade in game currency
     */
    Upgrade(UpgradeType upgradeType, int level, int cost);

    /**
     * Getter method to retrieve the type of upgrade
     * @return: UpgradeType enum value representing the type of upgrade
     */
    UpgradeType getUpgradeType() const;

    /**
     * Getter method to retrieve the level of the upgrade
     * @return: int value representing the level of the upgrade
     */
    int getUpgradeLevel() const;

    /**
     * Getter method to retrieve the cost of the upgrade
     * @return: int value representing the cost of the upgrade
     */
    int getUpgradeCost() const;

    /**
     * Method to apply the upgrade to a submarine
     * @param submarine: Pointer to the Submarine object to apply the upgrade to
     */
    void applyUpgradeToSubmarine(Submarine* submarine);

private:
    // Member variables
    UpgradeType upgradeType_; // Type of upgrade (attack, defense, speed, or detection)
    int upgradeLevel_; // Level of the upgrade (1, 2, 3, etc.)
    int upgradeCost_; // Cost of the upgrade in game currency
};

#endif  // UPGRADE_H
