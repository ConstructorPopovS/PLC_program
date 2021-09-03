#ifndef FURNACECOORDINATES_H
#define FURNACECOORDINATES_H
#include "../../src/main.h"
struct FurnaceCoord
{
    int lift;
    bool doors;
    bool support;
};
struct BoolUpdateFurCoord
{
    bool lift;
    bool doors;
    bool support;
};

class FurnaceCoordinates //TODO make the parrents class for FurnaseCoordinates and RobotCoordinates
{
private:
    FurnaceCoord _current;
    BoolUpdateFurCoord _boolNeedUpdate;
    void hasCoordinateChanged(int *currentCoordinate, int *targetCoordinate, bool *boolStructFlag, bool *flag);
    void hasCoordinateChanged(bool *currentCoordinate, bool *targetCoordinate, bool *boolStructFlag, bool *flag);

public:
    FurnaceCoordinates(int lift, bool doors, bool support);
    FurnaceCoord target;
    bool hasAnythingChanged();
    BoolUpdateFurCoord getBoolNeedUpdate();
    void updateCoordinates();
    void setTargetCoord(int lift, bool doors, bool support);
    void setTargetLift(int lift);
    void setTargetDoors(bool doors);
    void setTargetSupport(bool support);
    int getTargetLift();
    bool getTargetDoors();
    bool getTargetSupport();
};

#endif