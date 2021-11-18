#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"

class TemperatureCoordinates
{
private:
    TemperatureCoordinates();
    static TemperatureCoordinates *_instance;

public:
    static TemperatureCoordinates *getInstance();
    void setCoordinates(int highTemperature, int lowTemperature, int nowTemperature);
    IntConstrainedVariable highTemperature = IntConstrainedVariable::createHighTemperature();
    IntConstrainedVariable lowTemperature = IntConstrainedVariable::createLowTemperature();
    IntConstrainedVariable nowTemperature = IntConstrainedVariable::createNowTemperature();
};

#endif