#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode(MenuOnLCD* menuOnLCD) : pMenuOnLCD(menuOnLCD)
{
}
void MenuMode::initLCD()
{
    pMenuOnLCD->initAndBacklight();
}
