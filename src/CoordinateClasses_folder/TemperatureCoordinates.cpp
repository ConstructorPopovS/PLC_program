#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates(int targetHighTemperature,
                                               int targetLowTemperature,
                                               int targetNowTemperature)
{
    _target.highTemperature = targetHighTemperature;
    _target.lowTemperature = targetLowTemperature;
    _target.nowTemperature = targetNowTemperature;
}
bool TemperatureCoordinates::hasAnythingChanged()
{
    if ((_target.highTemperature != _current.highTemperature) ||
        (_target.lowTemperature != _current.lowTemperature) ||
        (_target.nowTemperature != _current.nowTemperature))
    {
        return (true);
    }
    return (false);
}
void TemperatureCoordinates::updateCoordinates()
{
    _current = _target;
}
void TemperatureCoordinates::setCoordinates(int highTemperature, int lowTemperature, int nowTemperature)
{
    _target.highTemperature = highTemperature;
    _target.lowTemperature = lowTemperature;
    _target.nowTemperature - nowTemperature;
}
void TemperatureCoordinates::setTargetHighTemperature(int targetTemperature)
{
    _target.highTemperature = targetTemperature;
}
void TemperatureCoordinates::setTargetLowTemperature(int targetTemperature)
{
    _target.lowTemperature = targetTemperature;
}
void TemperatureCoordinates::setTargetNowTemperature(int targetTemperature)
{
    _target.nowTemperature = targetTemperature;
}
int TemperatureCoordinates::getTargetHighTemperature()
{
    return (_target.highTemperature);
}
int TemperatureCoordinates::getTergetLowTemperature()
{
    return (_target.lowTemperature);
}
int TemperatureCoordinates::getTergetNowTemperature()
{
    return (_target.nowTemperature);
}
int* TemperatureCoordinates::getRTargetHighTemperature()
{
    return (&_target.highTemperature);
}
int* TemperatureCoordinates::getRTergetLowTemperature()
{
    return (&_target.lowTemperature);
}
int* TemperatureCoordinates::getRTergetNowTemperature()
{
    return (&_target.nowTemperature);
}
