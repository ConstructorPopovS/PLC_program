#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode() : pUpdateCoordinate(NULL),
                       xUpdateCoordinate(robotCoordinatesInMenu.getPX(), -10, -1, 1, 10),
                       yUpdateCoordinate(robotCoordinatesInMenu.getPY(), -10, -1, 1, 10),
                       fiUpdateCoordinate(robotCoordinatesInMenu.getPFi(), -10, -1, 1, 10),
                       vUpdateCoordinate(robotCoordinatesInMenu.getPV(), -2, -1, 1, 2),
                       liftUpdateCoordinate(furnanceCoordinates.getPLift(), -10, -1, 1, 10),
                       liftFloorUpdateCoordinate(furnanceCoordinates.getPLiftFloor(), -1, -1, 1, 1),
                       doorsUpdateCoordinate(furnanceCoordinates.getPDoors()),
                       standUpdateCoordinate(furnanceCoordinates.getPStand()),
                       highTemperatureUpdateCoordinate(temperatureCoordinates.getPHighTemperature(), -50, -5, 5, 50),
                       lowTemperatureUpdateCoordinate(temperatureCoordinates.getPLowTemperature(), -50, -5, 5, 50)
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
void MenuMode::init()
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
