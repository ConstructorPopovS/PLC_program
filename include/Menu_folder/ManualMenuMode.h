#ifndef MANUALMENUMODE_H
#define MANUALMENUMODE_H
#include "MenuMode.h"

class ManualMenuMode : public MenuMode
{
private:
    enum LevelsOfManualMode
    {
        NONE,
        CHANGE_COORDINATE
    } _levelOfManualMode;
    int coordinateEnteredInNumbers = 0;
    void processTheFirstKeypad();

public:
    ManualMenuMode();
    void doMenu();
};

#endif