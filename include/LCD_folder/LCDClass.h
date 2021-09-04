#ifndef LCDCLASS_H
#define LCDCLASS_H
#include "../../src/main.h"
#include <Wire.h>              // библиотека для работы с I2C
#include <LiquidCrystal_I2C.h> // библиотека для экранчика

enum modes
{
  TURN_ON,
  BLOCKED,
  MANUAL,
  AUTOPILOT
};
struct Flag
{
  modes currentMode = TURN_ON;
};

class LCDClass
{
private:
  LiquidCrystal_I2C _lcd;

public:
  LCDClass();
  void setTargetMode(modes newTargetMode);
  void init();      // Инициализация lcd
  void backlight(); // Включаем подсветку
  void clear();
  void clearSetCursorAndPrint(int column, int row, String text);
  void setCursorAndPrint(int column, int row, String text);
};

#endif