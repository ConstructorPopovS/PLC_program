#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode() : pCoordinateChange(NULL),
                       xCoordinateChange(robotCoordinatesInMenu.getPX(), -10, -1, 1, 10),
                       yCoordinateChange(robotCoordinatesInMenu.getPY(), -10, -1, 1, 10),
                       fiCoordinateChange(robotCoordinatesInMenu.getPFi(), -10, -1, 1, 10),
                       vCoordinateChange(robotCoordinatesInMenu.getPV(), -2, -1, 1, 2),
                       liftCoordinateChange(furnanceCoordinates.getPLift(), -10, -1, 1, 10),
                       liftFloorCoordinateChange(furnanceCoordinates.getPLiftFloor(), -1, -1, 1, 1),
                       doorsCoordinateChange(furnanceCoordinates.getPDoors()),
                       standCoordinateChange(furnanceCoordinates.getPStand()),
                       highTemperatureCoordinateChange(temperatureCoordinates.getPHighTemperature(), -50, -5, 5, 50),
                       lowTemperatureCoordinateChange(temperatureCoordinates.getPLowTemperature(), -50, -5, 5, 50)
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
    Serial.println("Start");
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
