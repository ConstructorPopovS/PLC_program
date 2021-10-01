#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates()
{
}
void TemperatureCoordinates::setCoordinates(int highTemperature, int lowTemperature, int nowTemperature)
{
    _temperatureCoordinates.highTemperature.setValue(highTemperature);
    _temperatureCoordinates.lowTemperature.setValue(lowTemperature);
    _temperatureCoordinates.nowTemperature.setValue(nowTemperature);
}
void TemperatureCoordinates::setCoordinates(StructTemperatureCoordinates structTemperatureCoordinates)
{
    _temperatureCoordinates = structTemperatureCoordinates;
}
void TemperatureCoordinates::setHighTemperature(int temperature)
{
    _temperatureCoordinates.highTemperature.setValue(temperature);
}
void TemperatureCoordinates::setLowTemperature(int temperature)
{
_temperatureCoordinates.lowTemperature.setValue(temperature);
}
void TemperatureCoordinates::setNowTemperature(int temperature)
{
    _temperatureCoordinates.nowTemperature.setValue(temperature);
}
StructTemperatureCoordinates TemperatureCoordinates::getStructOfCoordinates()
{
    return _temperatureCoordinates;
}
int TemperatureCoordinates::getHighTemperature()
{
    return _temperatureCoordinates.highTemperature.getValue();
}
int TemperatureCoordinates::getLowTemperature()
{
    return _temperatureCoordinates.lowTemperature.getValue();
}
int TemperatureCoordinates::getNowTemperature()
{
    return _temperatureCoordinates.nowTemperature.getValue();
}
IntConstrainedVariable* TemperatureCoordinates::getPHighTemperature()
{
    return &_temperatureCoordinates.highTemperature;
}
IntConstrainedVariable* TemperatureCoordinates::getPLowTemperature()
{
    return &_temperatureCoordinates.lowTemperature;
}
IntConstrainedVariable* TemperatureCoordinates::getPNowTemperature()
{
    return &_temperatureCoordinates.nowTemperature;
}
