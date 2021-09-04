#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates(int targetHTemperature, int targetLTemperature)
{
    target.hTemperature = targetHTemperature;
    target.lTemperature = targetLTemperature;
}
void TemperatureCoordinates::hasCoordinateChanged(int *coordinate, int *targetCoordinate, bool *boolRobflag, bool *flag)
{
    if (coordinate != targetCoordinate)
    {
        *boolRobflag = true;
        *flag = true;
    }
}
bool TemperatureCoordinates::hasAnythingChanged(TemperatureCoord targetRobotCoord)
{
    bool flag = false;
    hasCoordinateChanged(&_current.lTemperature, &target.lTemperature,
                         &_boolUpdateTemperCoord.lTemperature, &flag);
    hasCoordinateChanged(&_current.hTemperature, &target.hTemperature,
                         &_boolUpdateTemperCoord.hTemperature, &flag);
    return (flag);
}
BoolUpdateTemperCoord TemperatureCoordinates::getBoolCoordNeedUpdate()
{
    return (_boolUpdateTemperCoord);
}
void TemperatureCoordinates::updateCoordinates()
{
    _current = target;
}
void TemperatureCoordinates::setCoordinates(TemperatureCoord targetTemperCoord)
{
    target = targetTemperCoord;
}
TemperatureCoord TemperatureCoordinates::getCoordinates()
{
    return(_current);
}
void TemperatureCoordinates::setHighMode(int targetTemperature)
{
    target.hTemperature = targetTemperature;
}
void TemperatureCoordinates::setLowMode(int targetTemperature)
{
    target.lTemperature = targetTemperature;
}
