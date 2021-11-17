#ifndef SINGLETONLCD_H
#define SINGLETONLCD_H
#include "../src/main.h"
#include <Wire.h>              // библиотека для работы с I2C
#include <LiquidCrystal_I2C.h> // библиотека для экранчика

class SingletonLCD
{
public:
    static LiquidCrystal_I2C *getInstanceOfLCD();

private:
    SingletonLCD();
    static LiquidCrystal_I2C *_instanceOfLCD;
};

#endif