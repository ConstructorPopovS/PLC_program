#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
struct TemperatureCoord
{
    int hTemperature;
    int lTemperature;
};
struct BoolUpdateTemperCoord
{
    bool hTemperature;
    bool lTemperature;
};

class TemperatureCoordinates
{
private:
    TemperatureCoord _current;
    BoolUpdateTemperCoord _boolUpdateTemperCoord;
    void hasCoordinateChanged(int *coordinate, int *targetCoordinate, bool *boolRobflag, bool *flag);

public:
    TemperatureCoordinates(int targetHTemperature, int targetLTemperature);
    TemperatureCoord target;
    bool hasAnythingChanged(TemperatureCoord targetTemterCoord);
    BoolUpdateTemperCoord getBoolCoordNeedUpdate();
    void updateCoordinates();
    void setCoordinates(TemperatureCoord targetTemperCoord);
    TemperatureCoord getCoordinates();
    void setHighMode(int targetTemperature);
    void setLowMode(int targetTemperature);
};

#endif