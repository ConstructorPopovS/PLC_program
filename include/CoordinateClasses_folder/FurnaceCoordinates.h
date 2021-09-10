#ifndef FURNACECOORDINATES_H
#define FURNACECOORDINATES_H
#include "../../src/main.h"
struct FurnaceCoord
{
    int lift;
    int liftFloor;
    bool doors;
    bool support;
};

class FurnaceCoordinates
{
private:
    FurnaceCoord _current;
    FurnaceCoord _target;

public:
    FurnaceCoordinates(int lift, int liftFloor, bool doors, bool support);
    bool hasAnythingChanged();
    void updateCoordinates();
    void setTargetCoord(int lift, int liftFloor, bool doors, bool support);
    void setTargetLift(int lift);
    void setTargetLiftFloor(int inftFloor);
    void setTargetDoors(bool doors);
    void setTargetSupport(bool support);
    int getTargetLift();
    int getTargetLiftFloor();
    bool getTargetDoors();
    bool getTargetSupport();
    int* getRTargetLift();
    int* getRTargetLiftFloor();
    bool* getRTargetDoors();
    bool* getRTargetSupport();
};

#endif