#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
class TemperatureCoordinates
{
private:
    struct TemperatureCoord
    {
        int highTemperature;
        int lowTemperature;
        int nowTemperature;
    };
    TemperatureCoord _coordinate;

public:
    TemperatureCoordinates(int highTemperature, int lowTemperature, int nowTemperature);
    void setCoordinates(int highTemperature, int lowTemperature, int nowTemperature);
    void setHighTemperature(int Temperature);
    void setLowTemperature(int Temperature);
    void setNowTemperature(int Temperature);
    int getHighTemperature();
    int getLowTemperature();
    int getNowTemperature();
    int *getRHighTemperature();
    int *getRLowTemperature();
    int *getRNowTemperature();
};

#endif