#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
struct TemperatureCoord
{
    int highTemperature;
    int lowTemperature;
    int nowTemperature;
};
class TemperatureCoordinates
{
private:
    TemperatureCoord _current;
    TemperatureCoord _target;

public:
    TemperatureCoordinates(int targetHighTemperature, int targetLowTemperature, int targetNowTemperature);
    bool hasAnythingChanged();
    void updateCoordinates();
    void setCoordinates(int highTemperature, int lowTemperature, int nowTemperature);
    int getTargetHighTemperature();
    int getTergetLowTemperature();
    int getTergetNowTemperature();
    void setTargetHighTemperature(int targetTemperature);
    void setTargetLowTemperature(int targetTemperature);
    void setTargetNowTemperature(int targetTemperature);
};

#endif