#ifndef LCDCLASS_H
#define LCDCLASS_H
#include "../../src/main.h"
#include <Wire.h>              // библиотека для работы с I2C
#include <LiquidCrystal_I2C.h> // библиотека для экранчика

class LCDClass
{
private:
  LiquidCrystal_I2C _lcd;

public:
  LCDClass();
  void init();      // Инициализация lcd
  void backlight(); // Включаем подсветку
  void clear();
  void setCursor(int column, int row);
  void print(String text);
  void clearSetCursorAndPrint(int column, int row, String text);
  void setCursorAndPrint(int column, int row, String text);
};

#endif