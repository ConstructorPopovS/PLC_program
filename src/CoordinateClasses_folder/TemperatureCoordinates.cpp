#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates() : _highTemperature(IntConstrainedVariable::createHighTemperature()),
                                                   _lowTemperature(IntConstrainedVariable::createLowTemperature()),
                                                   _nowTemperature(IntConstrainedVariable::createNowTemperature())
{
}
void TemperatureCoordinates::setCoordinates(int highTemperature, int lowTemperature, int nowTemperature)
{
    _highTemperature.setValue(highTemperature);
    _lowTemperature.setValue(lowTemperature);
    _nowTemperature.setValue(nowTemperature);
}
void TemperatureCoordinates::setHighTemperature(int temperature)
{
    _highTemperature.setValue(temperature);
}
void TemperatureCoordinates::setLowTemperature(int temperature)
{
_lowTemperature.setValue(temperature);
}
void TemperatureCoordinates::setNowTemperature(int temperature)
{
    _nowTemperature.setValue(temperature);
}
int TemperatureCoordinates::getHighTemperature()
{
    return _highTemperature.getValue();
}
int TemperatureCoordinates::getLowTemperature()
{
    return _lowTemperature.getValue();
}
int TemperatureCoordinates::getNowTemperature()
{
    return _nowTemperature.getValue();
}
IntConstrainedVariable* TemperatureCoordinates::getPHighTemperature()
{
    return &_highTemperature;
}
IntConstrainedVariable* TemperatureCoordinates::getPLowTemperature()
{
    return &_lowTemperature;
}
IntConstrainedVariable* TemperatureCoordinates::getPNowTemperature()
{
    return &_nowTemperature;
}
