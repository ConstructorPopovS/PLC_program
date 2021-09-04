#ifndef COORDINATESHOWNONLCD_H
#define COORDINATESHOWNONLCD_H
#include "../../../src/main.h"

class CoordinateShownOnLCD
{
private:
protected:
    String name = "x";
    String sizeOfCoordinateToClearOnLCD = "    ";
    int coordinateRow = 1;
    int coordinateColumn = 2;

public:
    CoordinateShownOnLCD();
    CoordinateShownOnLCD(String newName, String newSizeOfCoordinateToClearOnLCD,
                         int newCoordinateRow, int newCoordinateColumn);
    int getCoordinateRow();
    int getCoordinateColumn();
    String getName();
    String getSizeOfCoordinateToClearOnLCD();
};

#endif