#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"

class TemperatureCoordinates
{
private:
    IntConstrainedVariable _highTemperature;
    IntConstrainedVariable _lowTemperature;
    IntConstrainedVariable _nowTemperature;

public:
    TemperatureCoordinates();
    void setCoordinates(int highTemperature, int lowTemperature, int nowTemperature);
    void setHighTemperature(int Temperature);
    void setLowTemperature(int Temperature);
    void setNowTemperature(int Temperature);
    int getHighTemperature();
    int getLowTemperature();
    int getNowTemperature();
    IntConstrainedVariable* getPHighTemperature();
    IntConstrainedVariable* getPLowTemperature();
    IntConstrainedVariable* getPNowTemperature();
};

#endif