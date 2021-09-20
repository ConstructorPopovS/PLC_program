#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates() : _highTemperature(IntVariable::createHighTemperature()),
                                                   _lowTemperature(IntVariable::createLowTemperature()),
                                                   _nowTemperature(IntVariable::createNowTemperature())
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
IntVariable* TemperatureCoordinates::getPHighTemperature()
{
    return &_highTemperature;
}
IntVariable* TemperatureCoordinates::getPLowTemperature()
{
    return &_lowTemperature;
}
IntVariable* TemperatureCoordinates::getPNowTemperature()
{
    return &_nowTemperature;
}
