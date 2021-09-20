#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
#include "../../include/CoordinateClasses_folder/IntVariable.h"

class TemperatureCoordinates
{
private:
    IntVariable _highTemperature;
    IntVariable _lowTemperature;
    IntVariable _nowTemperature;

public:
    TemperatureCoordinates();
    void setCoordinates(int highTemperature, int lowTemperature, int nowTemperature);
    void setHighTemperature(int Temperature);
    void setLowTemperature(int Temperature);
    void setNowTemperature(int Temperature);
    int getHighTemperature();
    int getLowTemperature();
    int getNowTemperature();
    IntVariable* getPHighTemperature();
    IntVariable* getPLowTemperature();
    IntVariable* getPNowTemperature();
};

#endif