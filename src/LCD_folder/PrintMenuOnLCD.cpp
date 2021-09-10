#include "../../include/LCD_folder/PrintMenuOnLCD.h"

PrintMenuOnLCD::PrintMenuOnLCD() : _xOnLCD("x", 100, 4, 2, 0),
                                   _yOnLCD("y", 0, 4, 7, 0),
                                   _fiOnLCD("fi", 0, 4, 12, 0),
                                   _vOnLSD("v", 10, 2, 18, 0),
                                   _liftOnLCD("lift", 112, 4, 2, 1),
                                   _liftFloorOnLCD("liftFloor", 1, 1, 14, 1),
                                   _doorsOnLCD("doors", false, 5, 2, 2),
                                   _supportOnLCD("support", false, 5, 14, 2),
                                   _highTemperatureOnLCD("hTemperature", 1000, 4, 2, 3),
                                   _lowTemperatureOnLCD("lTemperature", 600, 4, 7, 3),
                                   _nowTemperatureOnLCD("tNow", 980, 4, 16, 3)
{
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
void PrintMenuOnLCD::_clearValueField(CoordinateShownOnLCD &valueOnLCD)
{
    _lcd.setCursor(valueOnLCD.getCoordinateColumn(),
                   valueOnLCD.getCoordinateRow());
    for (int i = 0; i < valueOnLCD.getSizeOfCoordinateToClearOnLCD(); i++)
    {
        _lcd.print(" ");
    }
}
void PrintMenuOnLCD::_printIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value)
{
    valueOnLCD.setValue(value);
    _lcd.setCursorAndPrint(valueOnLCD.getCoordinateColumn(),
                           valueOnLCD.getCoordinateRow(),
                           String(valueOnLCD.getValue()));
}
void PrintMenuOnLCD::_renewIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value)
{
    if (valueOnLCD.getValue() != value)
    {
        _clearValueField(valueOnLCD);
        _printIntValue(valueOnLCD, value);
    }
}
void PrintMenuOnLCD::_printBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value)
{
    valueOnLCD.setValue(value);
    String openedOrClosed;
    if (value == false)
    {
        openedOrClosed = "close";
    }
    else if (value == true)
    {
        openedOrClosed = "open";
    }
    _lcd.setCursorAndPrint(valueOnLCD.getCoordinateColumn(),
                           valueOnLCD.getCoordinateRow(),
                           openedOrClosed);
}
void PrintMenuOnLCD::_renewBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value)
{
    if (valueOnLCD.getValue() != value)
    {
        _clearValueField(valueOnLCD);
        _printBoolValue(valueOnLCD, value);
    }
}
void PrintMenuOnLCD::printAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                                          bool doors, bool support,
                                          int highTemperature, int lowTemperature, int nowTemperature)
{
    _printIntValue(_xOnLCD, x);
    _printIntValue(_yOnLCD, y);
    _printIntValue(_fiOnLCD, fi);
    _printIntValue(_vOnLSD, v);
    _printIntValue(_liftOnLCD, lift);
    _printIntValue(_liftFloorOnLCD, liftFloor);
    _printBoolValue(_doorsOnLCD, doors);
    _printBoolValue(_supportOnLCD, support);
    _printIntValue(_highTemperatureOnLCD, highTemperature);
    _printIntValue(_lowTemperatureOnLCD, lowTemperature);
    _printIntValue(_nowTemperatureOnLCD, nowTemperature);
}
void PrintMenuOnLCD::renewAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                                          bool doors, bool support,
                                          int highTemperature, int lowTemperature, int nowTemperature)
{
    _renewIntValue(_xOnLCD, x);
    _renewIntValue(_yOnLCD, y);
    _renewIntValue(_fiOnLCD, fi);
    _renewIntValue(_vOnLSD, v);
    _renewIntValue(_liftOnLCD, lift);
    _renewIntValue(_liftFloorOnLCD, liftFloor);
    _renewBoolValue(_doorsOnLCD, doors);
    _renewBoolValue(_supportOnLCD, support);
    _renewIntValue(_highTemperatureOnLCD, highTemperature);
    _renewIntValue(_lowTemperatureOnLCD, lowTemperature);
    _renewIntValue(_nowTemperatureOnLCD, nowTemperature);
}