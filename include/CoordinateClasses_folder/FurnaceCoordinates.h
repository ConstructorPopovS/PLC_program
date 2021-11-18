#ifndef FURNACECOORDINATES_H
#define FURNACECOORDINATES_H
#include "../../src/main.h"
#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"

class FurnaceCoordinates
{
private:
    FurnaceCoordinates();
    static FurnaceCoordinates *_instance;

public:
    static FurnaceCoordinates *getInstance();
    void setCoordinates(int newLift, int newLiftFloor, bool newDoors, bool newStand);
    IntConstrainedVariable lift = IntConstrainedVariable::createLift();
    IntConstrainedVariable liftFloor = IntConstrainedVariable::createLiftFloor();
    bool doors = 0;
    bool stand = 0;
};

#endif