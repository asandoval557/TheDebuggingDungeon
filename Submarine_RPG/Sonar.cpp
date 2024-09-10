#include "sonar.h"
#include <stdexcept>
#include <cmath> // Include the cmath library for sqrt and pow functions
#include <vector> // Include the vector library for std::vector

// Constructor to initialize the sonar system
Sonar::Sonar(Submarine* submarine) : submarine(submarine) {
    // Check if the submarine is not null
    if (submarine == nullptr) {
        // Throw an exception if the submarine is null
        throw std::invalid_argument("Submarine must not be null");
    }
}

// Method to use sonar to detect nearby submarines
wxString Sonar::detect() {
    // Check if the submarine is alive and has a functional sonar system
    if (!submarine->isSubmarineAlive() || !submarine->hasFunctionalSonar()) {
        // If the submarine is not alive or the sonar system is not functional, return an error message
        return "Sonar system is not functional.";
    }

    // Calculate the sonar range based on the submarine's sonar upgrade level
    double sonarRange = submarine->getSonarRange();

    // Get a list of nearby submarines
    std::vector<Submarine*> nearbySubmarines = getNearbySubmarines();

    // Iterate over the nearby submarines
    for (Submarine* otherSubmarinePtr : nearbySubmarines) {
        // Calculate the distance between the current submarine and the other submarine
        double distance = calculateDistance(submarine, otherSubmarinePtr);

        // Check if the other submarine is within the sonar range
        if (distance <= sonarRange) {
            // Check if the other submarine is at a different depth due to underwater mountains
            if (isDepthDifferent(submarine, otherSubmarinePtr)) {
                // If the other submarine is at a different depth, return a detection message
                return "Submarine detected at a different depth.";
            }
            else {
                // If the other submarine is at the same depth, return a detection message
                return "Submarine detected at the same depth.";
            }
        }
    }

    // If no other submarines are detected, return a default message
    return "No submarines detected.";
}

double Sonar::calculateDistance(Submarine* submarine1, Submarine* submarine2) {
    // Check if either submarine is null
    if (submarine1 == nullptr || submarine2 == nullptr) {
        // Throw an exception if either submarine is null
        throw std::invalid_argument("Submarines must not be null");
    }

    // Calculate the difference in x and y coordinates between the two submarines
    double deltaX = submarine1->getXCoordinate() - submarine2->getXCoordinate();
    double deltaY = submarine1->getYCoordinate() - submarine2->getYCoordinate();

    // Calculate the Euclidean distance between the two submarines
    double distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    return distance;
}

std::vector<Submarine*> Sonar::getNearbySubmarines() {
    // TO DO: Implement logic to get nearby submarines
    return std::vector<Submarine*>();
}

// Helper function to check if two submarines are at different depths
bool Sonar::isDepthDifferent(Submarine* submarine1, Submarine* submarine2) {
    // Check if either submarine is null
    if (submarine1 == nullptr || submarine2 == nullptr) {
        // Throw an exception if either submarine is null
        throw std::invalid_argument("Submarines must not be null");
    }

    // Get the current depths of the two submarines
    int depth1 = submarine1->getCurrentDepth();
    int depth2 = submarine2->getCurrentDepth();

    // Check if the depths are different
    if (depth1 != depth2) {
        return true; // Depths are different
    }
    else {
        return false; // Depths are the same
    }
}