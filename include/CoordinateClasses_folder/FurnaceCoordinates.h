#ifndef FURNACECOORDINATES_H
#define FURNACECOORDINATES_H
#include "../../src/main.h"
#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"
struct StructFurnaceCoordinates
{
    IntConstrainedVariable lift = IntConstrainedVariable::createLift();
    IntConstrainedVariable liftFloor = IntConstrainedVariable::createLiftFloor();
    bool doors = 0;
    bool stand = 0;
};

class FurnaceCoordinates
{
private:
    StructFurnaceCoordinates _furnaceCoordinates;

public:
    FurnaceCoordinates();
    void setCoordinates(int lift, int liftFloor, bool doors, bool stand);
    void setCoordinates(StructFurnaceCoordinates structFurnaceCoordinates);
    void setLift(int lift);
    void setLiftFloor(int inftFloor);
    void setDoors(bool doors);
    void setStand(bool stand);
    StructFurnaceCoordinates getStructOfCoordinates();
    int getLift();
    int getLiftFloor();
    bool getDoors();
    bool getStand();
    IntConstrainedVariable* getPLift();
    IntConstrainedVariable* getPLiftFloor();
    bool* getPDoors();
    bool* getPStand();
};

#endif