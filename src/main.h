#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <Dynamixel_Servo.h>
#include "Keypad.h"
#include "KeypadClass.h"

// -----DEFINE PINS-----
// Toggle with key autopilot/manual
#define PIN_TOGGLE_WITH_KEY_AUTOPILOT 29
#define PIN_TOGGLE_WITH_KEY_MANUAL 27
// Toggle furnace modes
#define PIN_TOGGLE_FURNACE_MODES_HIGH 23
#define PIN_TOGGLE_FURNACE_MODES_LOW 25
// LCD connected to pins SDA, SCL, VCC, GND


enum modes
{
  BLOCKED,
  MANUAL,
  AUTOPILOT
};
struct Flag
{
  modes currentMode;
};

void lcdSetCursorAndPrint(int column, int row, String text);
void manualControlMode();
#endif