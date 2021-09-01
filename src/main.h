#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "LCDClass.h"

// -----DEFINE PINS-----
// Toggle with key autopilot/manual
#define PIN_TOGGLE_WITH_KEY_AUTOPILOT 29
#define PIN_TOGGLE_WITH_KEY_MANUAL 27
// Toggle furnace modes
#define PIN_TOGGLE_FURNACE_MODES_HIGH 23
#define PIN_TOGGLE_FURNACE_MODES_LOW 25
// LCD connected to pins SDA, SCL, VCC, GND

struct MainCoordinate
{
    int x = 150;
    int y = -10;
    int fi = 0;
    int levelOfLift = 1;
    bool openDors = 0;
    int temperatureTarget = 1000;
    int temperatureCurrent = 950;
};
#endif