#include "../../../include/LCD_folder/CoordinateShownOnLCD_folder/BoolCoordinateShownOnLCD.h"

BoolCoordinateShownOnLCD::BoolCoordinateShownOnLCD(String newName, bool newValue, int newSizeOfCoordinateToClearOnLCD,
                                                   int newCoordinateRow, int newCoordinateColumn)
{
    name = newName;
    value = newValue;
    sizeOfCoordinateToClearOnLCD = newSizeOfCoordinateToClearOnLCD;
    coordinateOnLCDRow = newCoordinateRow;
    coordinateOnLCDColumn = newCoordinateColumn;
}
bool BoolCoordinateShownOnLCD::getValue()
{
    return (value);
}
void BoolCoordinateShownOnLCD::setValue(bool newValue)
{
    value = newValue;
}