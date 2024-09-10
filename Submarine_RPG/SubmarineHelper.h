// SubmarineHelper.h
#ifndef SUBMARINEHELPER_H
#define SUBMARINEHELPER_H

class Submarine;

bool isCurrentDepthDifferentFromNewDepth(const Submarine& currentSubmarine, double newDepthValue);
double calculateNewDepthValue(const Submarine& currentSubmarine, double depthChangeValue);
void updateCurrentDepth(Submarine& currentSubmarine, double newDepthValue);
bool isValidDepthRange(double depthValue);
double getMaximumDepthRange(const Submarine& currentSubmarine);

#endif // SUBMARINEHELPER_H