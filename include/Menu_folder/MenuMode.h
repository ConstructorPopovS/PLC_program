#ifndef MENUMODE_H
#define MENUMODE_H
#include "../src/main.h"
#include "../Console_folder/Keypad_folder/GetDataFromKeypad.h"
#include "UpdateCoord_folder/UpdateCoord.h"
#include "UpdateCoord_folder/IntUpdateCoord.h"
#include "UpdateCoord_folder/BoolUpdateCoord.h"
#include "../Console_folder/Toggle_folder/ToggleWithKey.h"
#include "../Console_folder/Toggle_folder/ToggleFurnaceModes.h"
#include "LCD_folder/PrintMenuOnLCD.h"
#include "../CoordinateClasses_folder/RobotCoordinates.h"
#include "../CoordinateClasses_folder/FurnaceCoordinates.h"
#include "../CoordinateClasses_folder/TemperatureCoordinates.h"

class MenuMode
{

public:
    void init();
protected:
    MenuMode();
    void setCurrentMode(String mode);
    String getCurrentMode();
    void setTargetMode(String mode);
    String getTargetMode();
    

    ToggleWithKey toggleKey;
    ToggleFurnaceModes toggleFurnaceMode;
    GetDataFromKeypad dataFromKeypad;
    PrintMenuOnLCD lcdMenuPrinting;

    RobotCoordinates robotCoordinatesInMenu;
    FurnaceCoordinates furnanceCoordinates;
    TemperatureCoordinates temperatureCoordinates;

    UpdateCoord *pUpdateCoordinate = NULL; //указатель
    IntUpdateCoord xUpdateCoordinate;
    IntUpdateCoord yUpdateCoordinate;
    IntUpdateCoord fiUpdateCoordinate;
    IntUpdateCoord vUpdateCoordinate;
    IntUpdateCoord liftUpdateCoordinate;
    IntUpdateCoord liftFloorUpdateCoordinate;
    BoolUpdateCoord doorsUpdateCoordinate;
    BoolUpdateCoord standUpdateCoordinate;
    IntUpdateCoord highTemperatureUpdateCoordinate;
    IntUpdateCoord lowTemperatureUpdateCoordinate;
    // Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested

private:
    String _currentMode;
    String _targetMode;
    static const int _numberOfModes = 3;
    String _namesOfModes[_numberOfModes] = {"AUTOPILOT", "NULL", "MANUAL"};
};

#endif