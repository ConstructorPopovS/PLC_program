#ifndef FURNACECOORDINATES_H
#define FURNACECOORDINATES_H
#include "../../src/main.h"
#include "../../include/CoordinateClasses_folder/IntVariable.h"

class FurnaceCoordinates
{
private:
    IntVariable _lift;
    IntVariable _liftFloor;
    bool _doors;
    bool _stand;

public:
    FurnaceCoordinates();
    void setCoordinates(int lift, int liftFloor, bool doors, bool stand);
    void setLift(int lift);
    void setLiftFloor(int inftFloor);
    void setDoors(bool doors);
    void setStand(bool stand);
    int getLift();
    int getLiftFloor();
    bool getDoors();
    bool getStand();
    IntVariable* getPLift();
    IntVariable* getPLiftFloor();
    bool* getPDoors();
    bool* getPStand();
};

#endif