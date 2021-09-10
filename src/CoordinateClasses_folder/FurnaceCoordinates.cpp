#include "../../include/CoordinateClasses_folder/FurnaceCoordinates.h"
FurnaceCoordinates::FurnaceCoordinates(int lift, int liftFloor, bool doors, bool support)
{
    _target.lift = lift;
    _target.liftFloor = liftFloor;
    _target.doors = doors;
    _target.support = support;
}
bool FurnaceCoordinates::hasAnythingChanged()
{
    if ((_target.lift != _current.lift) ||
        (_target.liftFloor != _current.liftFloor) ||
        (_target.doors != _current.doors) ||
        (_target.support != _current.support))
    {
        return (true);
    }
    return (false);
}
void FurnaceCoordinates::updateCoordinates()
{
    _current = _target;
}
void FurnaceCoordinates::setTargetCoord(int lift, int liftFloor, bool doors, bool support)
{
    _target.lift = lift;
    _target.liftFloor = liftFloor;
    _target.doors = doors;
    _target.support = support;
}
void FurnaceCoordinates::setTargetLift(int lift)
{
    _target.lift = lift;
}
void FurnaceCoordinates::setTargetLiftFloor(int liftFloor)
{
    _target.liftFloor = liftFloor;
}
void FurnaceCoordinates::setTargetDoors(bool doors)
{
    _target.doors = doors;
}
void FurnaceCoordinates::setTargetSupport(bool support)
{
    _target.support = support;
}
int FurnaceCoordinates::getTargetLift()
{
    return (_target.lift);
}
int FurnaceCoordinates::getTargetLiftFloor()
{
    return (_target.liftFloor);
}
bool FurnaceCoordinates::getTargetDoors()
{
    return (_target.doors);
}
bool FurnaceCoordinates::getTargetSupport()
{
    return (_target.support);
}
int* FurnaceCoordinates::getRTargetLift()
{
    return (&_target.lift);
}
int* FurnaceCoordinates::getRTargetLiftFloor()
{
    return (&_target.liftFloor);
}
bool* FurnaceCoordinates::getRTargetDoors()
{
    return (&_target.doors);
}
bool* FurnaceCoordinates::getRTargetSupport()
{
    return (&_target.support);
}