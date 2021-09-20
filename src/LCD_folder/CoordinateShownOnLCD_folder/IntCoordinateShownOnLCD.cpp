#include "../../../include/LCD_folder/CoordinateShownOnLCD_folder/IntCoordinateShownOnLCD.h"

IntCoordinateShownOnLCD::IntCoordinateShownOnLCD(String newName, IntVariable* variable, int newSizeOfCoordinateToClearOnLCD,
                                                 int newCoordinateColumn, int newCoordinateRow)
{
    name = newName;
    _variable = variable;
    sizeOfCoordinateToClearOnLCD = newSizeOfCoordinateToClearOnLCD;
    coordinateOnLCDRow = newCoordinateRow;
    coordinateOnLCDColumn = newCoordinateColumn;
}
int IntCoordinateShownOnLCD::getValue()
{
    return _variable->getValue();
}
void IntCoordinateShownOnLCD::setValue(int Value)
{
    _variable->setValue(Value);
}