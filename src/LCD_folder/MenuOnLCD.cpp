#include "../../include/LCD_folder/MenuOnLCD.h"

MenuOnLCD::MenuOnLCD()
    : _pLcd(SingletonLCD::getInstanceOfLCD()),
      pRobotCoordinates(RobotCoordinates::getInstance()),
      pFurnaceCoordinates(FurnaceCoordinates::getInstance()),
      pTemperatureCoordinates(TemperatureCoordinates::getInstance()),
      _xOnLCD("x", IntConstrainedVariable::createX(), 4, 2, 0),
      _yOnLCD("y", IntConstrainedVariable::createY(), 4, 7, 0),
      _fiOnLCD("fi", IntConstrainedVariable::createFi(), 4, 12, 0),
      _vOnLSD("v", IntConstrainedVariable::createV(), 2, 18, 0),
      _liftOnLCD("lift", IntConstrainedVariable::createLift(), 4, 2, 1),
      _liftFloorOnLCD("liftFloor", IntConstrainedVariable::createLiftFloor(), 2, 14, 1),
      _doorsOnLCD("doors", false, 5, 2, 2),
      _standOnLCD("stand", false, 5, 14, 2),
      _highTemperatureOnLCD("highTemperature", IntConstrainedVariable::createHighTemperature(), 5, 2, 3),
      _lowTemperatureOnLCD("lowTemperature", IntConstrainedVariable::createLowTemperature(), 5, 8, 3),
      _nowTemperatureOnLCD("nowTemperature", IntConstrainedVariable::createNowTemperature(), 5, 15, 3)
//                       nameOfObject("name", value, sizeOfValueToClearOnLCD, column, row)
{
}
void MenuOnLCD::initAndBacklight()
{
    _pLcd->init();
    _pLcd->backlight();
    //--------------------delete--------------
    _pLcd->setCursor(4, 1);
    _pLcd->print("LCD init()");
    delay(200);
    _pLcd->print(".");
    delay(200);
    _pLcd->print(".");
    delay(200);
    _pLcd->print(".");
    delay(500);
    //------------------delete---------------
    _pLcd->clear();
}
void MenuOnLCD::claer()
{
    _pLcd->clear();
}
void MenuOnLCD::printConstPartOfManualMode()
{
    _pLcd->clear();
    for (int i = 0; i < 4; i++)
    {
        _pLcd->setCursor(0, i);
        _pLcd->print(_firstOnLCD[i]);
    }
}
void MenuOnLCD::printConstPartOfAutopilotMode()
{
    _pLcd->clear();
    _pLcd->setCursor(0, 0);
    _pLcd->print("AUTOPILOT");
}
void MenuOnLCD::printConstPartOfLockedMode()
{
    _pLcd->clear();
    _pLcd->setCursor(0, 0);
    _pLcd->print("LOCKED");
}
void MenuOnLCD::_clearValueField(CoordinateShownOnLCD &valueOnLCD)
{
    _pLcd->setCursor(valueOnLCD.getCoordinateColumn(),
                     valueOnLCD.getCoordinateRow());
    for (int i = 0; i < valueOnLCD.getSizeOfCoordinateToClearOnLCD(); i++)
    {
        _pLcd->print(" ");
    }
}
void MenuOnLCD::_printAndSetIntValue(IntCoordinateShownOnLCD &valueOnLCD, IntConstrainedVariable value)
{
    valueOnLCD.setValue(value.getValue());

    _pLcd->setCursor(valueOnLCD.getCoordinateColumn(),
                     valueOnLCD.getCoordinateRow());
    if (value.getValue() > 0)
    {
        _pLcd->print("+");
    }
    _pLcd->print(valueOnLCD.getValue());
}
void MenuOnLCD::_renewIntValue(IntCoordinateShownOnLCD &valueOnLCD, IntConstrainedVariable value)
{
    if (valueOnLCD.getValue() != value.getValue())
    {
        _clearValueField(valueOnLCD);
        _printAndSetIntValue(valueOnLCD, value);
        _pLcd->setCursor(valueOnLCD.getCoordinateColumn(), valueOnLCD.getCoordinateRow());
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
    _pLcd->setCursor(valueOnLCD.getCoordinateColumn(),
                     valueOnLCD.getCoordinateRow());
    _pLcd->print(openedOrClosed);
}
void MenuOnLCD::_renewBoolValue(BoolCoordinateShownOnLCD &valueOnLCD, bool value)
{
    if (valueOnLCD.getValue() != value)
    {
        _clearValueField(valueOnLCD);
        _printAndSetBoolValue(valueOnLCD, value);
        _pLcd->setCursor(valueOnLCD.getCoordinateColumn(), valueOnLCD.getCoordinateRow());
    }
}
void MenuOnLCD::printAllCoordiinates()
{
    _printAndSetIntValue(_xOnLCD, pRobotCoordinates->x);
    _printAndSetIntValue(_yOnLCD, pRobotCoordinates->y);
    _printAndSetIntValue(_fiOnLCD, pRobotCoordinates->fi);
    _printAndSetIntValue(_vOnLSD, pRobotCoordinates->v);
    _printAndSetIntValue(_liftOnLCD, pFurnaceCoordinates->lift);
    _printAndSetIntValue(_liftFloorOnLCD, pFurnaceCoordinates->liftFloor);
    _printAndSetBoolValue(_doorsOnLCD, pFurnaceCoordinates->doors);
    _printAndSetBoolValue(_standOnLCD, pFurnaceCoordinates->stand);
    _printAndSetIntValue(_highTemperatureOnLCD, pTemperatureCoordinates->highTemperature);
    _printAndSetIntValue(_lowTemperatureOnLCD, pTemperatureCoordinates->lowTemperature);
    _printAndSetIntValue(_nowTemperatureOnLCD, pTemperatureCoordinates->nowTemperature);
}
void MenuOnLCD::renewAllCoordiinates()
{
    _renewIntValue(_xOnLCD, pRobotCoordinates->x);
    _renewIntValue(_yOnLCD, pRobotCoordinates->y);
    _renewIntValue(_fiOnLCD, pRobotCoordinates->fi);
    _renewIntValue(_vOnLSD, pRobotCoordinates->v);
    _renewIntValue(_liftOnLCD, pFurnaceCoordinates->lift);
    _renewIntValue(_liftFloorOnLCD, pFurnaceCoordinates->liftFloor);
    _renewBoolValue(_doorsOnLCD, pFurnaceCoordinates->doors);
    _renewBoolValue(_standOnLCD, pFurnaceCoordinates->stand);
    _renewIntValue(_highTemperatureOnLCD, pTemperatureCoordinates->highTemperature);
    _renewIntValue(_lowTemperatureOnLCD, pTemperatureCoordinates->lowTemperature);
    _renewIntValue(_nowTemperatureOnLCD, pTemperatureCoordinates->nowTemperature);

    // Serial.print("x=" + String(pRobotCoordinates->x.getValue()));
    // Serial.print("\ty=" + String(pRobotCoordinates->y.getValue()));
    // Serial.print("\tfi=" + String(pRobotCoordinates->fi.getValue()));
    // Serial.print("\tv=" + String(pRobotCoordinates->v.getValue()));
    // Serial.print("\tlift=" + String(pFurnaceCoordinates->lift.getValue()));
    // Serial.print("\tdoors=" + String(pFurnaceCoordinates->doors));
    // Serial.print("\tstand=" + String(pFurnaceCoordinates->stand));
    // Serial.print("\thT=" + String(pTemperatureCoordinates->highTemperature.getValue()));
    // Serial.print("\tlT=" + String(pTemperatureCoordinates->lowTemperature.getValue()));
    // Serial.print("ON LCD");
    // Serial.println();
}
void MenuOnLCD::setCursorAndBlinc(String name)
{
    for (int i = 0; i < _maxNumberOfCoordinatesShownOnLCD; i++)
    {
        if (_nameOfCoordinateOnLCD[i] == name)
        {
            _nowNumberOfCoordinatesShownOnLCD = i;
            _pCoordinateOnLCD = &_coordinatesOnLCD[i];
            break;
        }
    }

    _pLcd->setCursor(_pCoordinateOnLCD->getCoordinateColumn(), _pCoordinateOnLCD->getCoordinateRow());
    _pLcd->cursor();
    _pLcd->blink();
}