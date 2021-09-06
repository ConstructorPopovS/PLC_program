#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
struct TemperatureCoord
{
    int hTemperature;
    int lTemperature;
};
class TemperatureCoordinates
{
private:
    TemperatureCoord _current;
    TemperatureCoord _target;

public:
    TemperatureCoordinates(int targetHighTemperature, int targetLowTemperature);
    bool hasAnythingChanged();
    void updateCoordinates();
    void setCoordinates(int highTemperature, int lowTemperature);
    int getTargetHighTemperature();
    int getTergetLowTemperature();
    void setTargetHighTemperature(int targetTemperature);
    void setTargetLowTemperature(int targetTemperature);
};

#endif