#ifndef INTCOORDINATESHOWNONLCD_H
#define INTCOORDINATESHOWNONLCD_H
#include "../../../src/main.h"
#include "CoordinateShownOnLCD.h"
#include "CoordinateClasses_folder/IntConstrainedVariable.h"

class IntCoordinateShownOnLCD : public CoordinateShownOnLCD
{
private:
    IntConstrainedVariable _variable;

protected:
public:
    IntCoordinateShownOnLCD(String newName,
                            IntConstrainedVariable variable,
                            int newSizeOfCoordinateToClearOnLCD,
                            int newCoordinateColumn,
                            int newCoordinateRow);
    int getValue();

    void setValue(int value);
};

#endif