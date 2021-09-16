#include "../../include/CoordinateClasses_folder/FurnaceCoordinates.h"
FurnaceCoordinates::FurnaceCoordinates(int lift, int liftFloor, bool doors, bool stand)
{
    _coordinate.lift = lift;
    _coordinate.liftFloor = liftFloor;
    _coordinate.doors = doors;
    _coordinate.stand = stand;
}

void FurnaceCoordinates::setCoordinates(int lift, int liftFloor, bool doors, bool stand)
{
    _coordinate.lift = lift;
    _coordinate.liftFloor = liftFloor;
    _coordinate.doors = doors;
    _coordinate.stand = stand;
}
void FurnaceCoordinates::setLift(int lift)
{
    _coordinate.lift = lift;
}
void FurnaceCoordinates::setLiftFloor(int liftFloor)
{
    _coordinate.liftFloor = liftFloor;
}
void FurnaceCoordinates::setDoors(bool doors)
{
    _coordinate.doors = doors;
}
void FurnaceCoordinates::setStand(bool stand)
{
    _coordinate.stand = stand;
}
int FurnaceCoordinates::getLift()
{
    return (_coordinate.lift);
}
int FurnaceCoordinates::getLiftFloor()
{
    return (_coordinate.liftFloor);
}
bool FurnaceCoordinates::getDoors()
{
    return (_coordinate.doors);
}
bool FurnaceCoordinates::getStand()
{
    return (_coordinate.stand);
}
int* FurnaceCoordinates::getRLift()
{
    return (&_coordinate.lift);
}
int* FurnaceCoordinates::getRLiftFloor()
{
    return (&_coordinate.liftFloor);
}
bool* FurnaceCoordinates::getRDoors()
{
    return (&_coordinate.doors);
}
bool* FurnaceCoordinates::getRStand()
{
    return (&_coordinate.stand);
}