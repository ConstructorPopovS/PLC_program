#include "../../include/Menu_folder/LockedMenuMode.h"

LockedMenuMode::LockedMenuMode(MenuOnLCD* menuOnLCD) : MenuMode(menuOnLCD)
{
}
void LockedMenuMode::printConstPartOfMode()
{
    pMenuOnLCD->printConstPartOfLockedMode();
}
void LockedMenuMode::doMenu()
{
}