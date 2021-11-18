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
    virtual void printConstPartOfMode() = 0;
    virtual void doMenu() = 0;

protected:
    MenuMode(MenuOnLCD *menuOnLCD);
    RobotCoordinates *pRobotCoordinates;
    FurnaceCoordinates *pFurnaceCoordinates;
    TemperatureCoordinates *pTemperatureCoordinates;

    ToggleFurnaceModes *pToggleFurnaceModes;
    FirstKeypad *firstKeypad;
    MenuOnLCD *pMenuOnLCD;

private:
};

#endif