#include "../../../include/CoordinateClasses_folder/CoordinateShownOnLCD_folder/CoordinateShownOnLCD.h"

CoordinateShownOnLCD::CoordinateShownOnLCD()
{
}
CoordinateShownOnLCD::CoordinateShownOnLCD(String newName, String newSizeOfCoordinateToClearOnLCD,
    int newCoordinateRow, int newCoordinateColumn)
    {
        name = newName;
        sizeOfCoordinateToClearOnLCD = newSizeOfCoordinateToClearOnLCD;
        coordinateRow = newCoordinateRow;
        coordinateColumn = newCoordinateColumn;
    }
int CoordinateShownOnLCD::getCoordinateRow()
{
    return (coordinateRow);
}
int CoordinateShownOnLCD::getCoordinateColumn()
{
    return (coordinateColumn);
}
String CoordinateShownOnLCD::getName()
{
    return(name);
}
String CoordinateShownOnLCD::getSizeOfCoordinateToClearOnLCD()
{
    return(sizeOfCoordinateToClearOnLCD);
}