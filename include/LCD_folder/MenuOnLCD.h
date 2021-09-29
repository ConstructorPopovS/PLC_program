#ifndef MENUONLCD_H
#define MENUONLCD_H
#include "../../src/main.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/CoordinateShownOnLCD.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/IntCoordinateShownOnLCD.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/BoolCoordinateShownOnLCD.h"
#include "../include/LCD_folder/LCDClass.h"
#include "CoordinateClasses_folder/IntConstrainedVariable.h"

class MenuOnLCD
{

public:
    MenuOnLCD();
    void initAndBacklight();
    void printConstPartOfMode(String mode);
    void claer();
    void setCursorAndBlinc(String name);
    void printAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                              bool doors, bool stand,
                              int highTemperature, int lowTemperature, int nowTemperature);
    void renewAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                              bool doors, bool stand,
                              int highTemperature, int lowTemperature, int nowTemperature);

private:
    LCDClass _lcd;
    const String _firstOnLCD[4] = {"M(    ;    ;    )V  ",
                                   "L(    ) floor(  )   ",
                                   "D(     ) stan(     )",
                                   "t(     /     )      "};
    void _printConstPartOfManualMode();
    void _printConstPartOfAutopilotMode();
    void _printConstPartOfNoneMode();

    IntConstrainedVariable _x;
    IntConstrainedVariable _y;
    IntConstrainedVariable _fi;
    IntConstrainedVariable _v;
    IntConstrainedVariable _lift;
    IntConstrainedVariable _liftFloor;
    bool _doors;
    bool _stand;
    IntConstrainedVariable _highTemperature;
    IntConstrainedVariable _lowTemperature;
    IntConstrainedVariable _nowTemperature;

    IntCoordinateShownOnLCD *_pIntCoordinateOnLCD;
    IntCoordinateShownOnLCD _xOnLCD;
    IntCoordinateShownOnLCD _yOnLCD;
    IntCoordinateShownOnLCD _fiOnLCD;
    IntCoordinateShownOnLCD _vOnLSD;
    IntCoordinateShownOnLCD _liftOnLCD;
    IntCoordinateShownOnLCD _liftFloorOnLCD;
    IntCoordinateShownOnLCD _highTemperatureOnLCD;
    IntCoordinateShownOnLCD _lowTemperatureOnLCD;
    IntCoordinateShownOnLCD _nowTemperatureOnLCD;

    BoolCoordinateShownOnLCD *_pBoolCoordinateOnLCD;
    BoolCoordinateShownOnLCD _doorsOnLCD;
    BoolCoordinateShownOnLCD _standOnLCD;

    CoordinateShownOnLCD *_pCoordinateOnLCD;
    static const int _maxNumberOfCoordinatesShownOnLCD = 11;
    int _nowNumberOfCoordinatesShownOnLCD = 0;
    CoordinateShownOnLCD _coordinatesOnLCD[_maxNumberOfCoordinatesShownOnLCD] =
        {_xOnLCD, _yOnLCD, _fiOnLCD, _vOnLSD,
         _liftOnLCD, _liftFloorOnLCD,
         _doorsOnLCD, _standOnLCD,
         _highTemperatureOnLCD, _lowTemperatureOnLCD, _nowTemperatureOnLCD};
    String _nameOfCoordinateOnLCD[_maxNumberOfCoordinatesShownOnLCD] =
        {"x", "y", "fi", "v",
         "lift", "liftFloor",
         "doors", "stand",
         "highTemperature", "lowTemperature", "nowTemperature"};
    void _printAndSetIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value);
    void _printAndSetBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value);
    void _renewIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value);
    void _renewBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value);
    void _clearValueField(CoordinateShownOnLCD &valueOnLCD);
};

#endif