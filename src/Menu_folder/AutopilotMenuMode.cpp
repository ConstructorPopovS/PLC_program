#include "../../include/Menu_folder/AutopilotMenuMode.h"

AutopilotMenuMode::AutopilotMenuMode(MenuOnLCD* menuOnLCD) : MenuMode(menuOnLCD)
{
}
void AutopilotMenuMode::printConstPartOfMode()
{
    pMenuOnLCD->printConstPartOfAutopilotMode();
}
void AutopilotMenuMode::doMenu()
{
}