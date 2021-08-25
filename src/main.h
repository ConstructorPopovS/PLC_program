#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <Dynamixel_Servo.h>

// -----DEFINE PINS-----
// Keypad
#define PIN_C1 3
#define PIN_C2 5
#define PIN_C3 7
#define PIN_C4 10
#define PIN_R1 11
#define PIN_R2 9
#define PIN_R3 11
#define PIN_R4 12
#define PIN_R5 4
#define PIN_R6 6
#define PIN_R7 24
#define PIN_R8 22
#define PIN_R9 16
#define PIN_R10 2
// Toggle with key autopilot/manual
#define PIN_TOGGLE_WITH_KEY_AUTOPILOT 29
#define PIN_TOGGLE_WITH_KEY_MANUAL 27
// Toggle furnace modes
#define PIN_TOGGLE_FURNACE_MODES_HIGH 23
#define PIN_TOGGLE_FURNACE_MODES_LOW 25
// LCD connected to pins SDA, SCL, VCC, GND


enum modes
{
  CLOSED,
  MANUAL,
  AUTOPILOT
};
struct Flag
{
  modes currentMode;
};
#endif