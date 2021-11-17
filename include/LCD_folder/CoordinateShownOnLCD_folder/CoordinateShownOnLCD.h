#ifndef COORDINATESHOWNONLCD_H
#define COORDINATESHOWNONLCD_H
#include "../../../src/main.h"

class CoordinateShownOnLCD
{
private:
protected:
    String name;
    int sizeOfCoordinateToClearOnLCD;
    int coordinateOnLCDRow;
    int coordinateOnLCDColumn;

public:
    CoordinateShownOnLCD();
    int getCoordinateRow();
    int getCoordinateColumn();
    String getName();
    int getSizeOfCoordinateToClearOnLCD();
};

#endif