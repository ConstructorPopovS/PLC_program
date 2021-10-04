#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode() : pCoordinateChange(NULL),
                       xCoordinateChange("x", robotCoordinates.getPX(), -10, -1, 1, 10),
                       yCoordinateChange("y", robotCoordinates.getPY(), -10, -1, 1, 10),
                       fiCoordinateChange("fi", robotCoordinates.getPFi(), -10, -1, 1, 10),
                       vCoordinateChange("v", robotCoordinates.getPV(), -2, -1, 1, 2),
                       liftCoordinateChange("lift", furnanceCoordinates.getPLift(), -10, -1, 1, 10),
                       liftFloorCoordinateChange("liftFloor", furnanceCoordinates.getPLiftFloor(), -1, -1, 1, 1),
                       doorsCoordinateChange("doors", furnanceCoordinates.getPDoors()),
                       standCoordinateChange("stand", furnanceCoordinates.getPStand()),
                       highTemperatureCoordinateChange("highTemperature", temperatureCoordinates.getPHighTemperature(), -50, -5, 5, 50),
                       lowTemperatureCoordinateChange("lowTemperature", temperatureCoordinates.getPLowTemperature(), -50, -5, 5, 50)
{
}
bool MenuMode::modeExists(String mode)
{
    for (int i = 0; i < _numberOfModes; i++)
    {
        if (mode == _namesOfModes[i])
        {
            return true;
        }
    }
    return false;
}
void MenuMode::initLCD()
{
    lcdMenuPrinting.initAndBacklight();
    Serial.println("Start LCD");
}
void MenuMode::setCurrentMode(String mode)
{
    if (modeExists(mode))
    {
        _currentMode = mode;
    }
}
void MenuMode::setTargetMode(String mode)
{
    if (modeExists(mode))
    {
        _targetMode = mode;
    }
}

String MenuMode::getCurrentMode()
{
    return (_currentMode);
}
String MenuMode::getTargetMode()
{
    return (_targetMode);
}
