#ifndef LOCKEDMENUMODE_H
#define LOCKEDMENUMODE_H
#include "MenuMode.h"

class LockedMenuMode : public MenuMode
{
private:
public:
    LockedMenuMode(MenuOnLCD* menuOnLCD);
    virtual void doMenu();
    virtual void printConstPartOfMode();
};

#endif