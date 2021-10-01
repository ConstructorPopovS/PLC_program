#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"
struct StructTemperatureCoordinates
{
    IntConstrainedVariable highTemperature = IntConstrainedVariable::createHighTemperature();
    IntConstrainedVariable lowTemperature = IntConstrainedVariable::createLowTemperature();
    IntConstrainedVariable nowTemperature = IntConstrainedVariable::createNowTemperature();
};

class TemperatureCoordinates
{
private:
StructTemperatureCoordinates _temperatureCoordinates;
public:
    TemperatureCoordinates();
    void setCoordinates(int highTemperature, int lowTemperature, int nowTemperature);
    void setCoordinates(StructTemperatureCoordinates structTemperatureCoordinates);
    void setHighTemperature(int Temperature);
    void setLowTemperature(int Temperature);
    void setNowTemperature(int Temperature);
    StructTemperatureCoordinates getStructOfCoordinates();
    int getHighTemperature();
    int getLowTemperature();
    int getNowTemperature();
    IntConstrainedVariable* getPHighTemperature();
    IntConstrainedVariable* getPLowTemperature();
    IntConstrainedVariable* getPNowTemperature();
};

#endif