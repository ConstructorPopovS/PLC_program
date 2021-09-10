#include "../../../include/LCD_folder/CoordinateShownOnLCD_folder/IntCoordinateShownOnLCD.h"

IntCoordinateShownOnLCD::IntCoordinateShownOnLCD(String newName, int newValue, int newSizeOfCoordinateToClearOnLCD,
                                                 int newCoordinateColumn, int newCoordinateRow)
{
    name = newName;
    value = newValue;
    sizeOfCoordinateToClearOnLCD = newSizeOfCoordinateToClearOnLCD;
    coordinateOnLCDRow = newCoordinateRow;
    coordinateOnLCDColumn = newCoordinateColumn;
}
int IntCoordinateShownOnLCD::getValue()
{
    return (value);
}
void IntCoordinateShownOnLCD::setValue(int newValue)
{
    value = newValue;
}