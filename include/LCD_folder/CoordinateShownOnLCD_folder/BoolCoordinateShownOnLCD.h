#ifndef BOOLCOORDINATESHOWNONLCD_H
#define BOOLCOORDINATESHOWNONLCD_H
#include "../../../src/main.h"
#include "CoordinateShownOnLCD.h"

class BoolCoordinateShownOnLCD : public CoordinateShownOnLCD
{
private:
protected:
    bool value;

public:
    BoolCoordinateShownOnLCD(String newName, bool newValue, int newSizeOfCoordinateToClearOnLCD,
                            int newCoordinateRow, int newCoordinateColumn);

    bool getValue();
    void setValue(bool newValue);
};

#endif