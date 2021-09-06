#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates(int targetHighTemperature, int targetLowTemperature)
{
    _target.hTemperature = targetHighTemperature;
    _target.lTemperature = targetLowTemperature;
}
bool TemperatureCoordinates::hasAnythingChanged()
{
    if((_target.hTemperature != _current.hTemperature)||
    (_target.lTemperature != _current.lTemperature))
    {
        return(true);
    }
    return(false);
}
void TemperatureCoordinates::updateCoordinates()
{
    _current = _target;
}
void TemperatureCoordinates::setCoordinates(int highTemperature, int lowTemperature)
{
   _target.hTemperature = highTemperature;
   _target.lTemperature = lowTemperature;
}
int TemperatureCoordinates::getTargetHighTemperature()
{
    return(_target.hTemperature);
}
int TemperatureCoordinates::getTergetLowTemperature()
{
    return(_target.lTemperature);
}
void TemperatureCoordinates::setTargetHighTemperature(int targetTemperature)
{
    _target.hTemperature = targetTemperature;
}
void TemperatureCoordinates::setTargetLowTemperature(int targetTemperature)
{
    _target.lTemperature = targetTemperature;
}
