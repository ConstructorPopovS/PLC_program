#ifndef PRINTMENUONLCD_H
#define PRINTMENUONLCD_H
#include "../../src/main.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/IntCoordinateShownOnLCD.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/BoolCoordinateShownOnLCD.h"
#include "../include/LCD_folder/LCDClass.h"
#define NUMBER_OF_INT_COORDINATES_ON_LCD 7
class PrintMenuOnLCD
{

public:
    PrintMenuOnLCD();
    void printConstPartOfMode(String mode);
    void initAndBacklight();
    void claer();
    void printAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                              bool doors, bool support,
                              int highTemperature, int lowTemperature, int nowTemperature);
    void renewAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                              bool doors, bool support,
                              int highTemperature, int lowTemperature, int nowTemperature);

private:
    LCDClass _lcd;
    const String _firstOnLCD[4] = {"M(    ;    ;    )V  ",
                                   "L(    ) floor( )    ",
                                   "D(     ) supp(     )",
                                   "t(    /    )tnow    "};
    void _printConstPartOfManualMode();
    void _printConstPartOfAutopilotMode();
    void _printConstPartOfNoneMode();

    IntCoordinateShownOnLCD *_rIntCoordinateOnLCD;
    IntCoordinateShownOnLCD _xOnLCD;
    IntCoordinateShownOnLCD _yOnLCD;
    IntCoordinateShownOnLCD _fiOnLCD;
    IntCoordinateShownOnLCD _vOnLSD;
    IntCoordinateShownOnLCD _liftOnLCD;
    IntCoordinateShownOnLCD _liftFloorOnLCD;
    IntCoordinateShownOnLCD _highTemperatureOnLCD;
    IntCoordinateShownOnLCD _lowTemperatureOnLCD;
    IntCoordinateShownOnLCD _nowTemperatureOnLCD;
    IntCoordinateShownOnLCD _coordinatesOnLCD[NUMBER_OF_INT_COORDINATES_ON_LCD] =
        {_xOnLCD, _yOnLCD, _fiOnLCD, _vOnLSD, _liftOnLCD, _liftFloorOnLCD, _nowTemperatureOnLCD};

    BoolCoordinateShownOnLCD *_rBoolCoordinateOnLCD;
    BoolCoordinateShownOnLCD _doorsOnLCD;
    BoolCoordinateShownOnLCD _supportOnLCD;
    void _printIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value);
    void _printBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value);
    void _renewIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value);
    void _renewBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value);
    void _clearValueField(CoordinateShownOnLCD &valueOnLCD);
};

#endif