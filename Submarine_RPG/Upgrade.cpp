// Upgrade.cpp
#include "Upgrade.h"
#include "Submarine.h"

Upgrade::Upgrade(UpgradeType upgradeType, int level, int cost)
    : upgradeType_(upgradeType), upgradeLevel_(level), upgradeCost_(cost) {}

Upgrade::UpgradeType Upgrade::getUpgradeType() const {
    return upgradeType_;
}

int Upgrade::getUpgradeLevel() const {
    return upgradeLevel_;
}

int Upgrade::getUpgradeCost() const {
    return upgradeCost_;
}

void Upgrade::applyUpgradeToSubmarine(Submarine* submarine) {
    switch (upgradeType_) {
    case UpgradeType::ATTACK_UPGRADE:
        // Increase submarine's attack power by the upgrade level
        submarine->increaseAttackPower(upgradeLevel_);
        break;
    case UpgradeType::DEFENSE_UPGRADE:
        // Increase submarine's defense value by the upgrade level
        submarine->increaseDefenseValue(upgradeLevel_);
        break;
    case UpgradeType::SPEED_UPGRADE:
        // Increase submarine's movement distance by the upgrade level
        submarine->increaseMovementDistance(upgradeLevel_);
        break;
    case UpgradeType::DETECTION_UPGRADE:
        // Increase submarine's detection range by the upgrade level
        submarine->increaseDetectionRange(upgradeLevel_);
        break;
    }
}