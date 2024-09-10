#ifndef SONAR_H
#define SONAR_H

// Include the submarine.h file to use the Submarine class
#include "submarine.h"
// Include the wx/string.h file to use the wxString class
#include <wx/string.h>

// Define the Sonar class to represent a sonar system
class Sonar {
public:
    // Constructor to initialize the sonar system
    Sonar(Submarine* submarine);
    // Method to use sonar to detect nearby submarines
    wxString detect();
    // Helper function to calculate the distance between two submarines
    double calculateDistance(Submarine* submarine1, Submarine* submarine2);
    // Helper function to get nearby submarines
    std::vector<Submarine*> getNearbySubmarines();
    // Helper function to check if two submarines are at different depths
    bool isDepthDifferent(Submarine* submarine1, Submarine* submarine2);
private:
    // Pointer to the submarine
    Submarine* submarine;
};

#endif // SONAR_H