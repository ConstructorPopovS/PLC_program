#include "../../include/LCD_folder/PrintMenuOnLCD.h"

PrintMenuOnLCD::PrintMenuOnLCD() : _xOnLCD("x", 5, 4, 1, 2),
                                   _yOnLCD("y", 2, 4, 1, 7),
                                   _fiOnLCD("fi", 0, 4, 1, 12),
                                   _vOnLSD("v", 10, 4, 1, 18),
                                   _liftOnLCD("lift", 100, 4, 2, 5),
                                   _liftFloorOnLCD("liftFloor", 1, 1, 2, 2),
                                   _highTemperatureOnLCD("hTemperature", 1000, 4, 3, 3),
                                   _lowTemperatureOnLCD("lTemperature", 600, 4, 3, 11),
                                   _doorsOnLCD("doors", false, 2, 2, 12),
                                   _supportOnLCD("support", false, 2, 2, 17)
{
    _rIntCoordinateOnLCD = &_xOnLCD;
    _rBoolCoordinateOnLCD = &_doorsOnLCD;
}
void PrintMenuOnLCD::initAndBacklight()
{
    _lcd.init();
    _lcd.backlight();
    _lcd.clearSetCursorAndPrint(0, 0, "Start");
}
void PrintMenuOnLCD::claer()
{
    _lcd.clear();
}
void PrintMenuOnLCD::_printConstPartOfManualMode()
{
    _lcd.clear();
    for (int i = 0; i < 4; i++)
    {
        _lcd.setCursorAndPrint(0, i, _firstOnLCD[i]);
    }
}
void PrintMenuOnLCD::_printConstPartOfAutopilotMode()
{
    _lcd.clear();
    _lcd.setCursorAndPrint(0, 0, "AUTOPILOT");
}
void PrintMenuOnLCD::_printConstPartOfNoneMode()
{
    _lcd.clear();
    _lcd.setCursorAndPrint(0, 0, "TURN ON THE KEY");
}
void PrintMenuOnLCD::printConstPartOfMode(String mode)
{
    if (mode == "MANUAL")
    {
        _printConstPartOfManualMode();
    }
    else if (mode == "AUTOPILOT")
    {
        _printConstPartOfAutopilotMode();
    }
    else if (mode == "NULL")
    {
        _printConstPartOfNoneMode();
    }
}
void PrintMenuOnLCD::_renewIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value)
{

    valueOnLCD.setValue(value);
    for (int i = 0; i < (valueOnLCD.getSizeOfCoordinateToClearOnLCD() + 1); i++)
    {
        _lcd.setCursorAndPrint(valueOnLCD.getCoordinateColumn(),
                               valueOnLCD.getCoordinateRow(), " ");
    }
    _lcd.setCursorAndPrint(valueOnLCD.getCoordinateColumn(),
                           valueOnLCD.getCoordinateRow(),
                           String(value));
}
void PrintMenuOnLCD::renewX(int x)
{
    _renewIntValue(_xOnLCD, x);
}
void PrintMenuOnLCD::renewY(int y)
{
    _renewIntValue(_yOnLCD, y);
}
void PrintMenuOnLCD::renewFi(int fi)
{
    _renewIntValue(_fiOnLCD, fi);
}
void PrintMenuOnLCD::renewV(int v)
{
    _renewIntValue(_vOnLSD, v);
}
void PrintMenuOnLCD::renewLift(int lift)
{
    _renewIntValue(_liftOnLCD, lift);
}
void PrintMenuOnLCD::renewLiftFloor(int liftFloor)
{
    _renewIntValue(_liftFloorOnLCD, liftFloor);
}
void PrintMenuOnLCD::renewHighTemperature(int highTemperature)
{
    _renewIntValue(_highTemperatureOnLCD, highTemperature);
}
void PrintMenuOnLCD::renewLowTemperature(int lowTemperature)
{
    _renewIntValue(_lowTemperatureOnLCD, lowTemperature);
}
void PrintMenuOnLCD::_renewBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value)
{
    valueOnLCD.setValue(value);
    for (int i = 0; i < (valueOnLCD.getSizeOfCoordinateToClearOnLCD() + 1); i++)
    {
        _lcd.setCursorAndPrint(valueOnLCD.getCoordinateColumn(),
                               valueOnLCD.getCoordinateRow(), " ");
    }
    String openedOrClosed;
    if (value == false)
    {
        openedOrClosed = "cl";
    }
    else if (value == true)
    {
        openedOrClosed = "op";
    }
    _lcd.setCursorAndPrint(valueOnLCD.getCoordinateColumn(),
                           valueOnLCD.getCoordinateRow(),
                           openedOrClosed);
}
void PrintMenuOnLCD::renewDoors(bool doors)
{
    _renewBoolValue(_doorsOnLCD, doors);
}
void PrintMenuOnLCD::renewSupport(bool support)
{
    _renewBoolValue(_supportOnLCD, support);
}
void PrintMenuOnLCD::renewAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                                          bool doors, bool support,
                                          int highTemperature, int lowTemperature)
{
    renewX(x);
    renewY(y);
    renewFi(fi);
    renewV(v);
    renewLift(lift);
    renewLiftFloor(liftFloor);
    renewDoors(doors);
    renewSupport(support);
    renewHighTemperature(highTemperature);
    renewLowTemperature(lowTemperature);
}