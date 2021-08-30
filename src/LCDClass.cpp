#include "LCDClass.h"

LCDClass::LCDClass() : _lcd(0x27, 20, 4)
{
    _x = 100;
    _y = 0;
    _fi = 0;
    _levelOfLift = 1;
    _openDors = 0;
    _temperatureTarget = 1000;
    _temperatureCurrent = 950;
}
LCDClass::LCDClass(int x, int y, int fi, int levelOfLift, bool openDors, int temperatureTarget, int temperatureCurrent) : _lcd(0x27, 20, 4)
{
    _x = x;
    _y = y;
    _fi = fi;
    _levelOfLift = levelOfLift;
    _openDors = openDors;
    _temperatureTarget = temperatureTarget;
    _temperatureCurrent = temperatureCurrent;
}
void LCDClass::renewMainCoordinate(int x, int y, int fi, int levelOfLift, bool openDors, int temperatureTarget, int temperatureCurrent)
{
}
void LCDClass::menu(int x, int y, int fi, int levelOfLift, bool openDors, int temperatureTarget, int temperatureCurrent)
{
    targetMode = targetMode;
    if (targetMode != flag.currentMode)
    {
        switch (targetMode)
        {
        case BLOCKED:
            clearSetCursorAndPrint(2, 1, "Turn on the mode");
            setCursorAndPrint(5, 2, "use the key");
            flag.currentMode = targetMode;
            break;
        case MANUAL:
            clearSetCursorAndPrint(7, 0, "Manual");
            setCursorAndPrint(0, 1, String(x));
            setCursorAndPrint(4, 1, ";");
            setCursorAndPrint(6, 1, String(y));
            setCursorAndPrint(9, 1, ";");
            setCursorAndPrint(10, 1, String(fi));
            setCursorAndPrint(15, 1, "SK");
            setCursorAndPrint(18, 1, "V");
            flag.currentMode = targetMode;
            break;
        case AUTOPILOT:
            clearSetCursorAndPrint(3, 1, "AUTOPILOT MODE");
            flag.currentMode = targetMode;
            break;
        default:
            break;
        }
    }
}
void LCDClass::setTargetMode(modes newTargetMode)
{
    targetMode = newTargetMode;
}

void LCDClass::init()
{
    _lcd.init();
    backlight();
}
void LCDClass::backlight()
{
    _lcd.backlight();
}
void LCDClass::clear()
{
    _lcd.clear();
}
void LCDClass::clearSetCursorAndPrint(int column, int row, String text)
{
    _lcd.clear();
    _lcd.setCursor(column, row);
    _lcd.print(text);
}
void LCDClass::setCursorAndPrint(int column, int row, String text)
{
    _lcd.setCursor(column, row);
    _lcd.print(text);
}