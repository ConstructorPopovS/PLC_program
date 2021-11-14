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
    int coordinateEnteredFromTheThordKeypad = 0;
    void processTheFirstKeypad();
    void processTheThirdKeypad();
    CoordinateChange *pCoordinateChange = NULL; //указатель
    IntCoordinateChange xCoordinateChange;
    IntCoordinateChange yCoordinateChange;
    IntCoordinateChange fiCoordinateChange;
    IntCoordinateChange vCoordinateChange;
    IntCoordinateChange liftCoordinateChange;
    IntCoordinateChange liftFloorCoordinateChange;
    BoolCoordinateChange doorsCoordinateChange;
    BoolCoordinateChange standCoordinateChange;
    IntCoordinateChange highTemperatureCoordinateChange;
    IntCoordinateChange lowTemperatureCoordinateChange;

public:
    ManualMenuMode(MenuOnLCD* menuOnLCD);
    virtual void doMenu();
    virtual void printConstPartOfMode();
};

#endif