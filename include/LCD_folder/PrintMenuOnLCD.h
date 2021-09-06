#ifndef PRINTMENUONLCD_H
#define PRINTMENUONLCD_H
#include "../../src/main.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/IntCoordinateShownOnLCD.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/BoolCoordinateShownOnLCD.h"
#include "../include/LCD_folder/LCDClass.h"
#define NUMBER_OF_INT_COORDINATES_ON_LCD 6
class PrintMenuOnLCD
{

public:
    PrintMenuOnLCD();
    void printConstPartOfMode(String mode);
    void initAndBacklight();
    void claer();
    void renewX(int x);
    void renewY(int y);
    void renewFi(int fi);
    void renewV(int v);
    void renewLift(int lift);
    void renewLiftFloor(int liftFloor);
    void renewDoors(bool doors);
    void renewSupport(bool support);
    void renewHighTemperature(int highTemperature);
    void renewLowTemperature(int lowTemperature);
    void renewAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                              bool doors, bool support,
                              int highTemperature, int lowTemperature);

private:
    LCDClass _lcd;
    const String _firstOnLCD[4] = {"       MANUAL       ",
                                   "M(    ;    ;    )v  ",
                                   "L( ):    ;D:  ;S:  ;",
                                   "Ht:    ;Lt:    ;    "};
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
    IntCoordinateShownOnLCD _coordinatesOnLCD[NUMBER_OF_INT_COORDINATES_ON_LCD] =
        {_xOnLCD, _yOnLCD, _fiOnLCD, _vOnLSD, _liftOnLCD, _liftFloorOnLCD};

    BoolCoordinateShownOnLCD *_rBoolCoordinateOnLCD;
    BoolCoordinateShownOnLCD _doorsOnLCD;
    BoolCoordinateShownOnLCD _supportOnLCD;
    void _renewIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value);
    void _renewBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value);
};

#endif