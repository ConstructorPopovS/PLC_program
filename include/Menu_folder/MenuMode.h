#ifndef MENUMODE_H
#define MENUMODE_H
#include "../src/main.h"
#include "../Console_folder/Keypad_folder/FirstKeypad.h"
#include "../Console_folder/Toggle_folder/ToggleFurnaceModes.h"
#include "LCD_folder/MenuOnLCD.h"
#include "CoordinateChange_folder/CoordinateChange.h"
#include "CoordinateChange_folder/IntCoordinateChange.h"
#include "CoordinateChange_folder/BoolCoordinateChange.h"
#include "../CoordinateClasses_folder/RobotCoordinates.h"
#include "../CoordinateClasses_folder/FurnaceCoordinates.h"
#include "../CoordinateClasses_folder/TemperatureCoordinates.h"

class MenuMode
{

public:
    void initLCD();
    virtual void printConstPatrOfMode() = 0;
    virtual void doMenu() = 0;

protected:
    MenuMode();
    RobotCoordinates robotCoordinates;
    FurnaceCoordinates furnanceCoordinates;
    TemperatureCoordinates temperatureCoordinates;


    ToggleFurnaceModes toggleFurnaceMode;
    FirstKeypad firstKeypad;
    MenuOnLCD menuOnLCD;
    // Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested
private:

};

#endif