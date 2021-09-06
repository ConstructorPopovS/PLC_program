#ifndef INTCOORDINATESHOWNONLCD_H
#define INTCOORDINATESHOWNONLCD_H
#include "../../../src/main.h"
#include "CoordinateShownOnLCD.h"

class IntCoordinateShownOnLCD : public CoordinateShownOnLCD
{
private:
protected:
    int value;

public:
    IntCoordinateShownOnLCD(String newName = "х", int newValue = 100, int newSizeOfCoordinateToClearOnLCD = 4,
                            int newCoordinateRow = 0, int newCoordinateColumn = 0);
    int getValue();
    void setValue(int newValue);
};

#endif