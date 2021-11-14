#ifndef AUTOPILOTMENUMODE_H
#define AUTOPILOTMENUMODE_H
#include "MenuMode.h"

class AutopilotMenuMode : public MenuMode
{
private:
public:
    AutopilotMenuMode(MenuOnLCD* menuOnLCD);
    virtual void doMenu();
    virtual void printConstPartOfMode();
};

#endif