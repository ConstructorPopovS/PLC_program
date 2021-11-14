#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode()
{
}
void MenuMode::initLCD()
{
    menuOnLCD.initAndBacklight();
    Serial.println("Start LCD");
}

