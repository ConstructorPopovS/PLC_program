#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode() : robotCoordinatesInMenu(100, 0, 0, 10),
                       furnanceCoordinates(120, 1, false, false),
                       temperatureCoordinates(1000, 600, 985),
                       pUpdateCoordinate(NULL),
                       xUpdateCoordinate(robotCoordinatesInMenu.getRX(), 10, 1, 1, 10),
                       yUpdateCoordinate(robotCoordinatesInMenu.getRY(), 10, 1, 1, 10),
                       fiUpdateCoordinate(robotCoordinatesInMenu.getRFi(), 10, 1, 1, 10),
                       vUpdateCoordinate(robotCoordinatesInMenu.getRV(), 2, 1, 1, 2),
                       liftUpdateCoordinate(furnanceCoordinates.getRLift(), 10, 1, 1, 10),
                       liftFloorUpdateCoordinate(furnanceCoordinates.getRLiftFloor(), 1, 1, 1, 1),
                       doorsUpdateCoordinate(furnanceCoordinates.getRDoors()),
                       standUpdateCoordinate(furnanceCoordinates.getRStand()),
                       highTemperatureUpdateCoordinate(temperatureCoordinates.getRHighTemperature(), 50, 5, 5, 50),
                       lowTemperatureUpdateCoordinate(temperatureCoordinates.getRLowTemperature(), 50, 5, 5, 50)
{
}
void MenuMode::init()
{
    lcdMenuPrinting.initAndBacklight();
    Serial.println("Start");
}
void MenuMode::setCurrentMode(String mode)
{
    for (int i = 0; i < _numberOfModes; i++)
    {
        if (mode == _namesOfModes[i])
        {
            _currentMode = mode;
            break;
        }
    }
}
void MenuMode::setTargetMode(String mode)
{
    for (int i = 0; i < _numberOfModes; i++)
    {
        if (mode == _namesOfModes[i])
        {
            _targetMode = mode;
            break;
        }
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
