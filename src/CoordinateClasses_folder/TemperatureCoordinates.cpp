#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates(int HighTemperature,
                                               int LowTemperature,
                                               int NowTemperature)
{
    _coordinate.highTemperature = HighTemperature;
    _coordinate.lowTemperature = LowTemperature;
    _coordinate.nowTemperature = NowTemperature;
}
void TemperatureCoordinates::setCoordinates(int highTemperature, int lowTemperature, int nowTemperature)
{
    _coordinate.highTemperature = highTemperature;
    _coordinate.lowTemperature = lowTemperature;
    _coordinate.nowTemperature - nowTemperature;
}
void TemperatureCoordinates::setHighTemperature(int temperature)
{
    _coordinate.highTemperature = temperature;
}
void TemperatureCoordinates::setLowTemperature(int temperature)
{
    _coordinate.lowTemperature = temperature;
}
void TemperatureCoordinates::setNowTemperature(int temperature)
{
    _coordinate.nowTemperature = temperature;
}
int TemperatureCoordinates::getHighTemperature()
{
    return (_coordinate.highTemperature);
}
int TemperatureCoordinates::getLowTemperature()
{
    return (_coordinate.lowTemperature);
}
int TemperatureCoordinates::getNowTemperature()
{
    return (_coordinate.nowTemperature);
}
int* TemperatureCoordinates::getRHighTemperature()
{
    return (&_coordinate.highTemperature);
}
int* TemperatureCoordinates::getRLowTemperature()
{
    return (&_coordinate.lowTemperature);
}
int* TemperatureCoordinates::getRNowTemperature()
{
    return (&_coordinate.nowTemperature);
}
