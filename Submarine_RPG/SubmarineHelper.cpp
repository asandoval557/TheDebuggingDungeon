// SubmarineHelper.cpp
#include "SubmarineHelper.h"
#include "Submarine.h"

bool isCurrentDepthDifferentFromNewDepth(const Submarine& currentSubmarine, double newDepthValue)
{
    // Check if the new depth is different from the current depth
    return currentSubmarine.getCurrentDepth() != newDepthValue;
}

double calculateNewDepthValue(const Submarine& currentSubmarine, double depthChangeValue)
{
    // Calculate the new depth based on the current depth and the change
    return currentSubmarine.getCurrentDepth() + depthChangeValue;
}

void updateCurrentDepth(Submarine& currentSubmarine, double newDepthValue)
{
    // Update the submarine's depth to the new depth
    currentSubmarine.setCurrentDepth(newDepthValue);
}

bool isValidDepthRange(double depthValue)
{
    // Check if the depth is within the valid range
    return depthValue >= 0 && depthValue <= 1000;
}

double getMaximumDepthRange(const Submarine& currentSubmarine)
{
    // Get the submarine's maximum depth range
    return currentSubmarine.getMaximumDepthRange();
}