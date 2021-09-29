#include "../../include/LCD_folder/MenuOnLCD.h"

MenuOnLCD::MenuOnLCD() : _x(IntConstrainedVariable::createX()),
                         _y(IntConstrainedVariable::createY()),
                         _fi(IntConstrainedVariable::createFi()),
                         _v(IntConstrainedVariable::createV()),
                         _lift(IntConstrainedVariable::createLift()),
                         _liftFloor(IntConstrainedVariable::createLiftFloor()),
                         _doors(false),
                         _stand(false),
                         _highTemperature(IntConstrainedVariable::createHighTemperature()),
                         _lowTemperature(IntConstrainedVariable::createLowTemperature()),
                         _nowTemperature(IntConstrainedVariable::createNowTemperature()),

                         _xOnLCD("x", &_x, 4, 2, 0),
                         _yOnLCD("y", &_y, 4, 7, 0),
                         _fiOnLCD("fi", &_fi, 4, 12, 0),
                         _vOnLSD("v", &_v, 2, 18, 0),
                         _liftOnLCD("lift", &_lift, 4, 2, 1),
                         _liftFloorOnLCD("liftFloor", &_liftFloor, 2, 14, 1),
                         _doorsOnLCD("doors", _doors, 5, 2, 2),
                         _standOnLCD("stand", _stand, 5, 14, 2),
                         _highTemperatureOnLCD("highTemperature", &_highTemperature, 5, 2, 3),
                         _lowTemperatureOnLCD("lowTemperature", &_lowTemperature, 5, 8, 3),
                         _nowTemperatureOnLCD("nowTemperature", &_nowTemperature, 5, 15, 3)
//                       nameOfObject("name", value, sizeOfValueToClearOnLCD, column, row)
{
}
void MenuOnLCD::initAndBacklight()
{
    _lcd.init();
    _lcd.backlight();
    _lcd.clear();
}
void MenuOnLCD::claer()
{
    _lcd.clear();
}
void MenuOnLCD::_printConstPartOfManualMode()
{
    _lcd.clear();
    for (int i = 0; i < 4; i++)
    {
        _lcd.setCursorAndPrint(0, i, _firstOnLCD[i]);
    }
}
void MenuOnLCD::_printConstPartOfAutopilotMode()
{
    _lcd.clear();
    _lcd.setCursorAndPrint(0, 0, "AUTOPILOT");
}
void MenuOnLCD::_printConstPartOfNoneMode()
{
    _lcd.clear();
    _lcd.noBacklight(); // or  _lcd.noDisplay();
}
void MenuOnLCD::printConstPartOfMode(String mode)
{
    _lcd.backlight(); // or _lcd.display();
    _lcd.noBlink();
    _lcd.noCursor();
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
void MenuOnLCD::_clearValueField(CoordinateShownOnLCD &valueOnLCD)
{
    _lcd.setCursor(valueOnLCD.getCoordinateColumn(),
                   valueOnLCD.getCoordinateRow());
    for (int i = 0; i < valueOnLCD.getSizeOfCoordinateToClearOnLCD(); i++)
    {
        _lcd.print(" ");
    }
}
void MenuOnLCD::_printAndSetIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value)
{
    valueOnLCD.setValue(value);
    if (value > 0)
    {
        _lcd.setCursorAndPrint(valueOnLCD.getCoordinateColumn(),
                               valueOnLCD.getCoordinateRow(),
                               "+");
    }
    else
    {
        _lcd.setCursor(valueOnLCD.getCoordinateColumn(),
                       valueOnLCD.getCoordinateRow());
    }
    _lcd.print(valueOnLCD.getValue());
}
void MenuOnLCD::_renewIntValue(IntCoordinateShownOnLCD &valueOnLCD, int value)
{
    if (valueOnLCD.getValue() != value)
    {
        Serial.println(valueOnLCD.getName() + "(on LCD)" + "=" + String(valueOnLCD.getValue()));
        _clearValueField(valueOnLCD);
        _printAndSetIntValue(valueOnLCD, value);
        _lcd.setCursor(valueOnLCD.getCoordinateColumn(), valueOnLCD.getCoordinateRow());
        Serial.println("Renew: " + valueOnLCD.getName() + " to " + String(value));
        Serial.println("Now: " + valueOnLCD.getName() + "=" + String(valueOnLCD.getValue()));
    }
}
void MenuOnLCD::_printAndSetBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value)
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
void MenuOnLCD::_renewBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value)
{
    if (valueOnLCD.getValue() != value)
    {
        Serial.println(valueOnLCD.getName() + "(on LCD)"  + "=" + String(valueOnLCD.getValue()));
        _clearValueField(valueOnLCD);
        _printAndSetBoolValue(valueOnLCD, value);
        _lcd.setCursor(valueOnLCD.getCoordinateColumn(), valueOnLCD.getCoordinateRow());
        Serial.println("Renew: " + valueOnLCD.getName() + " to " + String(value));
        Serial.println("Now: " + valueOnLCD.getName() + "=" + String(valueOnLCD.getValue()));
    }
}
void MenuOnLCD::printAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                                     bool doors, bool stand,
                                     int highTemperature, int lowTemperature, int nowTemperature)
{
    _printAndSetIntValue(_xOnLCD, x);
    _printAndSetIntValue(_yOnLCD, y);
    _printAndSetIntValue(_fiOnLCD, fi);
    _printAndSetIntValue(_vOnLSD, v);
    _printAndSetIntValue(_liftOnLCD, lift);
    _printAndSetIntValue(_liftFloorOnLCD, liftFloor);
    _printAndSetBoolValue(_doorsOnLCD, doors);
    _printAndSetBoolValue(_standOnLCD, stand);
    _printAndSetIntValue(_highTemperatureOnLCD, highTemperature);
    _printAndSetIntValue(_lowTemperatureOnLCD, lowTemperature);
    _printAndSetIntValue(_nowTemperatureOnLCD, nowTemperature);
}
void MenuOnLCD::renewAllCoordiinates(int x, int y, int fi, int v, int lift, int liftFloor,
                                     bool doors, bool stand,
                                     int highTemperature, int lowTemperature, int nowTemperature)
{
    _renewIntValue(_xOnLCD, x);
    _renewIntValue(_yOnLCD, y);
    _renewIntValue(_fiOnLCD, fi);
    _renewIntValue(_vOnLSD, v);
    _renewIntValue(_liftOnLCD, lift);
    _renewIntValue(_liftFloorOnLCD, liftFloor);
    _renewBoolValue(_doorsOnLCD, doors);
    _renewBoolValue(_standOnLCD, stand);
    _renewIntValue(_highTemperatureOnLCD, highTemperature);
    _renewIntValue(_lowTemperatureOnLCD, lowTemperature);
    _renewIntValue(_nowTemperatureOnLCD, nowTemperature);
}
void MenuOnLCD::setCursorAndBlinc(String name)
{
    for (int i = 0; i < _maxNumberOfCoordinatesShownOnLCD; i++)
    {
        if (_nameOfCoordinateOnLCD[i] == name)
        {
            Serial.print(_nameOfCoordinateOnLCD[i] + "  ");
            _nowNumberOfCoordinatesShownOnLCD = i;
            _pCoordinateOnLCD = &_coordinatesOnLCD[i];
            break;
        }
    }
    Serial.println(String(_pCoordinateOnLCD->getCoordinateColumn()) + "  " +
                   String(_pCoordinateOnLCD->getCoordinateRow()));
    _lcd.setCursor(_pCoordinateOnLCD->getCoordinateColumn(), _pCoordinateOnLCD->getCoordinateRow());
    // _lcd.setCursorAndPrint(2, 1, "!");//test
    _lcd.cursor();
    _lcd.blink();
}