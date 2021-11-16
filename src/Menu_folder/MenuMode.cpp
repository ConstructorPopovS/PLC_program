#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode(MenuOnLCD *menuOnLCD) : pMenuOnLCD(menuOnLCD),
                                           firstKeypad(FirstKeypad::getInstance())
{
}
void MenuMode::initLCD()
{
    pMenuOnLCD->initAndBacklight();
}
