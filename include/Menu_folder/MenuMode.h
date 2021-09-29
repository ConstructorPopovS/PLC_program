#ifndef MENUMODE_H
#define MENUMODE_H
#include "../src/main.h"
#include "../Console_folder/Keypad_folder/GetDataFromKeypad.h"
#include "CoordinateChange_folder/CoordinateChange.h"
#include "CoordinateChange_folder/IntCoordinateChange.h"
#include "CoordinateChange_folder/BoolCoordinateChange.h"
#include "../Console_folder/Toggle_folder/ToggleWithKey.h"
#include "../Console_folder/Toggle_folder/ToggleFurnaceModes.h"
#include "LCD_folder/MenuOnLCD.h"
#include "../CoordinateClasses_folder/RobotCoordinates.h"
#include "../CoordinateClasses_folder/FurnaceCoordinates.h"
#include "../CoordinateClasses_folder/TemperatureCoordinates.h"

class MenuMode
{

public:
    void initLCD();

protected:
    MenuMode();
    void setCurrentMode(String mode);
    String getCurrentMode();
    void setTargetMode(String mode);
    String getTargetMode();

    ToggleWithKey toggleKey;
    ToggleFurnaceModes toggleFurnaceMode;
    GetDataFromKeypad dataFromKeypad;
    MenuOnLCD lcdMenuPrinting;

    RobotCoordinates robotCoordinatesInMenu;
    FurnaceCoordinates furnanceCoordinates;
    TemperatureCoordinates temperatureCoordinates;

    CoordinateChange *pCoordinateChange = NULL; //указатель
    IntCoordinateChange xCoordinateChange;
    IntCoordinateChange yCoordinateChange;
    IntCoordinateChange fiCoordinateChange;
    IntCoordinateChange vCoordinateChange;
    IntCoordinateChange liftCoordinateChange;
    IntCoordinateChange liftFloorCoordinateChange;
    BoolCoordinateChange doorsCoordinateChange;
    BoolCoordinateChange standCoordinateChange;
    IntCoordinateChange highTemperatureCoordinateChange;
    IntCoordinateChange lowTemperatureCoordinateChange;
    // Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested

private:
    String _currentMode;
    String _targetMode;
    static const int _numberOfModes = 3;
    String _namesOfModes[_numberOfModes] = {"AUTOPILOT", "NULL", "MANUAL"};
    bool modeExists(String mode);
};

#endif