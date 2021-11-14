#ifndef AUTOPILOTMENUMODE_H
#define AUTOPILOTMENUMODE_H
#include "MenuMode.h"

class AutopilotMenuMode : public MenuMode
{
private:

public:
    AutopilotMenuMode();
    virtual void doMenu();
    virtual void printConstPatrOfMode();
};

#endif