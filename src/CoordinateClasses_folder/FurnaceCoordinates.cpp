#include "../../include/CoordinateClasses_folder/FurnaceCoordinates.h"
FurnaceCoordinates::FurnaceCoordinates()
{
}

void FurnaceCoordinates::setCoordinates(int lift, int liftFloor, bool doors, bool stand)
{
    _furnaceCoordinates.lift.setValue(lift);
    _furnaceCoordinates.liftFloor.setValue(liftFloor);
    _furnaceCoordinates.doors = doors;
    _furnaceCoordinates.stand = stand;
}
void FurnaceCoordinates::setCoordinates(StructFurnaceCoordinates structFurnaceCoordinates)
{
    _furnaceCoordinates = structFurnaceCoordinates;
}
void FurnaceCoordinates::setLift(int lift)
{
    _furnaceCoordinates.lift.setValue(lift);
}
void FurnaceCoordinates::setLiftFloor(int liftFloor)
{
    _furnaceCoordinates.liftFloor.setValue(liftFloor);
}
void FurnaceCoordinates::setDoors(bool doors)
{
    _furnaceCoordinates.doors = doors;
}
void FurnaceCoordinates::setStand(bool stand)
{
    _furnaceCoordinates.stand = stand;
}
StructFurnaceCoordinates FurnaceCoordinates::getStructOfCoordinates()
{
    return _furnaceCoordinates;
}
int FurnaceCoordinates::getLift()
{
    return _furnaceCoordinates.lift.getValue();
}
int FurnaceCoordinates::getLiftFloor()
{
    return _furnaceCoordinates.liftFloor.getValue();
}
bool FurnaceCoordinates::getDoors()
{
    return _furnaceCoordinates.doors;
}
bool FurnaceCoordinates::getStand()
{
    return _furnaceCoordinates.stand;
}
IntConstrainedVariable* FurnaceCoordinates::getPLift()
{
    return &_furnaceCoordinates.lift;
}
IntConstrainedVariable *FurnaceCoordinates::getPLiftFloor()
{
    return &_furnaceCoordinates.liftFloor;
}
bool *FurnaceCoordinates::getPDoors()
{
    return &_furnaceCoordinates.doors;
}
bool *FurnaceCoordinates::getPStand()
{
    return &_furnaceCoordinates.stand;
}