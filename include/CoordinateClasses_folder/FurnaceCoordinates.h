#ifndef FURNACECOORDINATES_H
#define FURNACECOORDINATES_H
#include "../../src/main.h"

class FurnaceCoordinates
{
private:
    struct FurnaceCoord
    {
        int lift;
        int liftFloor;
        bool doors;
        bool stand;
    };
    FurnaceCoord _coordinate;

public:
    FurnaceCoordinates(int lift, int liftFloor, bool doors, bool stand);
    void setCoordinates(int lift, int liftFloor, bool doors, bool stand);
    void setLift(int lift);
    void setLiftFloor(int inftFloor);
    void setDoors(bool doors);
    void setStand(bool stand);
    int getLift();
    int getLiftFloor();
    bool getDoors();
    bool getStand();
    int *getRLift();
    int *getRLiftFloor();
    bool *getRDoors();
    bool *getRStand();
};

#endif