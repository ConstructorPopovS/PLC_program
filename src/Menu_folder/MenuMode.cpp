#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode(MenuOnLCD *menuOnLCD)
    : pMenuOnLCD(menuOnLCD),
      firstKeypad(FirstKeypad::getInstance()),
      pToggleFurnaceModes(ToggleFurnaceModes::getInstance()),
      pRobotCoordinates(RobotCoordinates::getInstance()),
      pFurnaceCoordinates(FurnaceCoordinates::getInstance()),
      pTemperatureCoordinates(TemperatureCoordinates::getInstance())
{
}
void MenuMode::initLCD()
{
    pMenuOnLCD->initAndBacklight();
}
