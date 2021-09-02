#ifndef TEMPERATURECOORDINATES_H
#define TEMPERATURECOORDINATES_H

#include "../../src/main.h"
struct TemperatureCoord
{
    int highModeTemperature;
    int lowModeTemperature;
};
struct BoolUpdateTemperCoord
{
    bool highModeTemperature;
    bool lowModeTemperature;
};

class TemperatureCoordinates
{
private:
    TemperatureCoord _temperCoordinates;
    TemperatureCoord _targetTemperCoord;
    BoolUpdateTemperCoord _boolUpdateTemperCoord;
    void hasCoordinateChanged(int *coordinate, int *targetCoordinate, bool *boolRobflag, bool *flag);

public:
    TemperatureCoordinates(TemperatureCoord targetTemterCoord);
    bool hasAnythingChanged(TemperatureCoord targetTemterCoord);
    BoolUpdateTemperCoord getBoolCoordNeedUpdate();
    void updateCoordinates();
    void setCoordinates(TemperatureCoord targetTemperCoord);
    TemperatureCoord getCoordinates();
    void setHighMode(int targetTemperature);
    void setLowMode(int targetTemperature);
};

#endif