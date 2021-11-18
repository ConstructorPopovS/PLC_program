#ifndef MENUONLCD_H
#define MENUONLCD_H
#include "../../src/main.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/CoordinateShownOnLCD.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/IntCoordinateShownOnLCD.h"
#include "../include/LCD_folder/CoordinateShownOnLCD_folder/BoolCoordinateShownOnLCD.h"
#include "../CoordinateClasses_folder/RobotCoordinates.h"
#include "../CoordinateClasses_folder/FurnaceCoordinates.h"
#include "../CoordinateClasses_folder/TemperatureCoordinates.h"
#include "CoordinateClasses_folder/IntConstrainedVariable.h"
#include <Wire.h>              // библиотека для работы с I2C
#include <LiquidCrystal_I2C.h> // библиотека для экранчика
#include "SingletonLCD.h"

class MenuOnLCD
{

public:
    MenuOnLCD();
    void initAndBacklight();
    void printConstPartOfManualMode();
    void printConstPartOfAutopilotMode();
    void printConstPartOfLockedMode();
    void claer();
    void printAllCoordiinates();
    void renewAllCoordiinates();
    void setCursorAndBlinc(String name);
    RobotCoordinates *pRobotCoordinates;
    FurnaceCoordinates *pFurnaceCoordinates;
    TemperatureCoordinates *pTemperatureCoordinates;

private:
    const String _firstOnLCD[4] = {"M(    ;    ;    )V  ",
                                   "L(    ) floor(  )   ",
                                   "D(     ) stan(     )",
                                   "t(     /     )      "};

    LiquidCrystal_I2C *_pLcd;
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
    void _printAndSetIntValue(IntCoordinateShownOnLCD &valueOnLCD, IntConstrainedVariable value);
    void _printAndSetBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value);
    void _renewIntValue(IntCoordinateShownOnLCD &valueOnLCD, IntConstrainedVariable value);
    void _renewBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value);
    void _clearValueField(CoordinateShownOnLCD &valueOnLCD);
};

#endif