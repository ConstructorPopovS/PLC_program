#include "../../include/CoordinateClasses_folder/FurnaceCoordinates.h"
FurnaceCoordinates::FurnaceCoordinates(int lift, bool doors, bool support)
{
    target.lift = lift;
    target.doors = doors;
    target.support = support;
}
void FurnaceCoordinates::hasCoordinateChanged(int *currentCoordinate, int *targetCoordinate,
                                              bool *boolStructFlag, bool *flag)
{
    if (currentCoordinate != targetCoordinate)
    {
        *boolStructFlag = true;
        *flag = true;
    }
}
void FurnaceCoordinates::hasCoordinateChanged(bool *currentCoordinate, bool *targetCoordinate,
                                              bool *boolStructFlag, bool *flag)
{
    if (currentCoordinate != targetCoordinate)
    {
        *boolStructFlag = true;
        *flag = true;
    }
}
bool FurnaceCoordinates::hasAnythingChanged()
{
    bool flag = false;
    hasCoordinateChanged(&_current.lift, &target.lift, &_boolNeedUpdate.lift, &flag);
    hasCoordinateChanged(&_current.doors, &target.doors, &_boolNeedUpdate.doors, &flag);
    hasCoordinateChanged(&_current.support, &target.support, &_boolNeedUpdate.support, &flag);
    return(flag);
}
BoolUpdateFurCoord FurnaceCoordinates::getBoolNeedUpdate()
{
    return(_boolNeedUpdate);
}
void FurnaceCoordinates::updateCoordinates()
{
    _current = target;
}
void FurnaceCoordinates::setTargetCoord(int lift, bool doors, bool support)
{
    target.lift = lift;
    target.doors = doors;
    target.support = support;
}
void FurnaceCoordinates::setTargetLift(int lift)
{
    target.lift = lift;
}
void FurnaceCoordinates::setTargetDoors(bool doors)
{
    target.doors = doors;
}
void FurnaceCoordinates::setTargetSupport(bool support)
{
    target.support = support;
}
int FurnaceCoordinates::getTargetLift()
{
    return(target.lift);
}
bool FurnaceCoordinates::getTargetDoors()
{
    return(target.lift);
}
bool FurnaceCoordinates::getTargetSupport()
{
    return(target.support);
}