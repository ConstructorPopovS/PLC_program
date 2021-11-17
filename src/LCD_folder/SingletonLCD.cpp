#include "../include/LCD_folder/SingletonLCD.h"

SingletonLCD::SingletonLCD()
{
}
LiquidCrystal_I2C* SingletonLCD::_instanceOfLCD = NULL;
LiquidCrystal_I2C* SingletonLCD::getInstanceOfLCD()
{
    if (_instanceOfLCD == NULL)
    {
        _instanceOfLCD = new LiquidCrystal_I2C(0x27, 20, 4);
    }
    return _instanceOfLCD;
}