#include "../../include/CoordinateClasses_folder/FurnaceCoordinates.h"
FurnaceCoordinates::FurnaceCoordinates()
{
}
FurnaceCoordinates *FurnaceCoordinates::_instance = NULL;
FurnaceCoordinates *FurnaceCoordinates::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new FurnaceCoordinates();
    }
    return _instance;
}

void FurnaceCoordinates::setCoordinates(int newLift, int newLiftFloor, bool newDoors, bool newStand)
{
    lift.setValue(newLift);
    liftFloor.setValue(newLiftFloor);
    doors = newDoors;
    stand = newStand;
}