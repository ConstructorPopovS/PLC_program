#include "../../../include/LCD_folder/CoordinateShownOnLCD_folder/CoordinateShownOnLCD.h"

CoordinateShownOnLCD::CoordinateShownOnLCD()
{
}
int CoordinateShownOnLCD::getCoordinateRow()
{
    return (coordinateOnLCDRow);
}
int CoordinateShownOnLCD::getCoordinateColumn()
{
    return (coordinateOnLCDColumn);
}
String CoordinateShownOnLCD::getName()
{
    return(name);
}
int CoordinateShownOnLCD::getSizeOfCoordinateToClearOnLCD()
{
    return(sizeOfCoordinateToClearOnLCD);
}