#include "../../include/CoordinateClasses_folder/TemperatureCoordinates.h"

TemperatureCoordinates::TemperatureCoordinates()
{
}
TemperatureCoordinates *TemperatureCoordinates::_instance = NULL;
TemperatureCoordinates *TemperatureCoordinates::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new TemperatureCoordinates();
    }
    return _instance;
}
void TemperatureCoordinates::setCoordinates(int newHighTemperature, int newLowTemperature, int newNowTemperature)
{
    highTemperature.setValue(newHighTemperature);
    lowTemperature.setValue(newLowTemperature);
    nowTemperature.setValue(newNowTemperature);
}