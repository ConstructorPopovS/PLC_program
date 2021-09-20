#include "../../include/CoordinateClasses_folder/FurnaceCoordinates.h"
FurnaceCoordinates::FurnaceCoordinates() : _lift(IntVariable::createLift()),
                                           _liftFloor(IntVariable::createLiftFloor()),
                                           _doors(false),
                                           _stand(false)
{
}

void FurnaceCoordinates::setCoordinates(int lift, int liftFloor, bool doors, bool stand)
{
    _lift.setValue(lift);
    _liftFloor.setValue(liftFloor);
    _doors = doors;
    _stand = stand;
}
void FurnaceCoordinates::setLift(int lift)
{
    _lift.setValue(lift);
}
void FurnaceCoordinates::setLiftFloor(int liftFloor)
{
    _liftFloor.setValue(liftFloor);
}
void FurnaceCoordinates::setDoors(bool doors)
{
    _doors = doors;
}
void FurnaceCoordinates::setStand(bool stand)
{
    _stand = stand;
}
int FurnaceCoordinates::getLift()
{
    return _lift.getValue();
}
int FurnaceCoordinates::getLiftFloor()
{
    return _liftFloor.getValue();
}
bool FurnaceCoordinates::getDoors()
{
    return _doors;
}
bool FurnaceCoordinates::getStand()
{
    return _stand;
}
IntVariable* FurnaceCoordinates::getPLift()
{
    return (&_lift);
}
IntVariable *FurnaceCoordinates::getPLiftFloor()
{
    return &_liftFloor;
}
bool *FurnaceCoordinates::getPDoors()
{
    return &_doors;
}
bool *FurnaceCoordinates::getPStand()
{
    return &_stand;
}