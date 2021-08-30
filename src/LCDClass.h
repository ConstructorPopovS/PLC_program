#ifndef LCDCLASS_H
#define LCDCLASS_H
#include "main.h"
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
  // ====================SHARED VARIABLES FOR ALL COMPONENTS PLC PROGRAMM===================
  int _x;
  int _y;
  int _fi;
  int _levelOfLift;
  bool _openDors;
  int _temperatureTarget;
  int _temperatureCurrent;
  // =====================================================================================

public:
  LCDClass();
  LCDClass(int x, int y, int fi, int levelOfLift, bool openDors, int temperatureTarget, int temperatureCurrent);
  modes targetMode;
  Flag flag;
  void menu(int x, int y, int fi, int levelOfLift, bool openDors, int temperatureTarget, int temperatureCurrent);
  void setTargetMode(modes newTargetMode);
  void renewMainCoordinate(int x, int y, int fi, int levelOfLift, bool openDors, int temperatureTarget, int temperatureCurrent);
  void init();      // Инициализация lcd
  void backlight(); // Включаем подсветку
  void clear();
  void clearSetCursorAndPrint(int column, int row, String text);
  void setCursorAndPrint(int column, int row, String text);
};

#endif