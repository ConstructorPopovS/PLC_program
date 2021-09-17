#include "../../include/LCD_folder/LCDClass.h"

LCDClass::LCDClass() : LiquidCrystal_I2C(0x27, 20, 4)
{
}
void LCDClass::clearSetCursorAndPrint(int column, int row, String text)
{
    clear();
    setCursor(column, row);
    print(text);
}
void LCDClass::setCursorAndPrint(int column, int row, String text)
{
    setCursor(column, row);
    print(text);
}