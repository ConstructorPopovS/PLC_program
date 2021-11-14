#include "../../include/Menu_folder/MenuMode.h"

MenuMode::MenuMode()
{
}
void MenuMode::initLCD()
{
    lcdMenuPrinting.initAndBacklight();
    Serial.println("Start LCD");
}

