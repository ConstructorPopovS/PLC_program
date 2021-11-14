#ifndef LCDCLASS_H
#define LCDCLASS_H
#include "../../src/main.h"
#include <Wire.h>              // библиотека для работы с I2C
#include <LiquidCrystal_I2C.h> // библиотека для экранчика
//TODO delete this class. its metods remove to MenuOnLCD
class LCDClass : public LiquidCrystal_I2C
{
private:
public:
  LCDClass();
  void clearSetCursorAndPrint(int column, int row, String text);
  void setCursorAndPrint(int column, int row, String text);
};

#endif