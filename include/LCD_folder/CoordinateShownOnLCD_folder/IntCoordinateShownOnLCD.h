#ifndef INTCOORDINATESHOWNONLCD_H
#define INTCOORDINATESHOWNONLCD_H
#include "../../../src/main.h"
#include "CoordinateShownOnLCD.h"
#include "../../CoordinateClasses_folder/IntVariable.h"
#include "CoordinateClasses_folder/IntVariable.h"

class IntCoordinateShownOnLCD : public CoordinateShownOnLCD
{
private:
    IntVariable* _variable;
protected:

public:
    IntCoordinateShownOnLCD(String newName, IntVariable* variable, int newSizeOfCoordinateToClearOnLCD,
                            int newCoordinateColumn, int newCoordinateRow);
    int getValue();

    void setValue(int Value);
};

#endif