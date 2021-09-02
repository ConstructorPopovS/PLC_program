#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates(TemperatureCoord targetTemterCoord)
{
    _targetTemperCoord = targetTemterCoord;
    _temperCoordinates = _targetTemperCoord;
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
    hasCoordinateChanged(&_temperCoordinates.lowModeTemperature, &_targetTemperCoord.lowModeTemperature,
                         &_boolUpdateTemperCoord.lowModeTemperature, &flag);
    hasCoordinateChanged(&_temperCoordinates.highModeTemperature, &_targetTemperCoord.highModeTemperature,
                         &_boolUpdateTemperCoord.highModeTemperature, &flag);
    return (flag);
}
BoolUpdateTemperCoord TemperatureCoordinates::getBoolCoordNeedUpdate()
{
    return (_boolUpdateTemperCoord);
}
void TemperatureCoordinates::updateCoordinates()
{
    _temperCoordinates = _targetTemperCoord;
}
void TemperatureCoordinates::setCoordinates(TemperatureCoord targetTemperCoord)
{
    _targetTemperCoord = targetTemperCoord;
}
TemperatureCoord TemperatureCoordinates::getCoordinates()
{
    return(_temperCoordinates);
}
void TemperatureCoordinates::setHighMode(int targetTemperature)
{
    _targetTemperCoord.highModeTemperature = targetTemperature;
}
void TemperatureCoordinates::setLowMode(int targetTemperature)
{
    _targetTemperCoord.lowModeTemperature = targetTemperature;
}
