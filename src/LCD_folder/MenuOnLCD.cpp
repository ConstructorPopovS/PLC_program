#include "../../include/LCD_folder/MenuOnLCD.h"

MenuOnLCD::MenuOnLCD() : _xOnLCD("x", _robotCoordinates.getPX(), 4, 2, 0),
                         _yOnLCD("y", _robotCoordinates.getPY(), 4, 7, 0),
                         _fiOnLCD("fi", _robotCoordinates.getPFi(), 4, 12, 0),
                         _vOnLSD("v", _robotCoordinates.getPV(), 2, 18, 0),
                         _liftOnLCD("lift", _furnaceCoordinates.getPLift(), 4, 2, 1),
                         _liftFloorOnLCD("liftFloor", _furnaceCoordinates.getPLiftFloor(), 2, 14, 1),
                         _doorsOnLCD("doors", _furnaceCoordinates.getPDoors(), 5, 2, 2),
                         _standOnLCD("stand", _furnaceCoordinates.getPStand(), 5, 14, 2),
                         _highTemperatureOnLCD("highTemperature", _temperatureCOordinates.getPHighTemperature(), 5, 2, 3),
                         _lowTemperatureOnLCD("lowTemperature", _temperatureCOordinates.getPLowTemperature(), 5, 8, 3),
                         _nowTemperatureOnLCD("nowTemperature", _temperatureCOordinates.getPNowTemperature(), 5, 15, 3)
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
void MenuOnLCD::printConstPartOfManualMode()
{
    _lcd.clear();
    for (int i = 0; i < 4; i++)
    {
        _lcd.setCursorAndPrint(0, i, _firstOnLCD[i]);
    }
}
void MenuOnLCD::printConstPartOfAutopilotMode()
{
    _lcd.clear();
    _lcd.setCursorAndPrint(0, 0, "AUTOPILOT");
}
void MenuOnLCD::printConstPartOfLockedMode()
{
    _lcd.clear();
    _lcd.setCursorAndPrint(0, 0, "LOCKED");
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
        _clearValueField(valueOnLCD);
        _printAndSetIntValue(valueOnLCD, value);
        _lcd.setCursor(valueOnLCD.getCoordinateColumn(), valueOnLCD.getCoordinateRow());
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
        _clearValueField(valueOnLCD);
        _printAndSetBoolValue(valueOnLCD, value);
        _lcd.setCursor(valueOnLCD.getCoordinateColumn(), valueOnLCD.getCoordinateRow());
    }
}
void MenuOnLCD::printAllCoordiinates(RobotCoordinates* robotCoordinates,
                                     FurnaceCoordinates* furnaceCoordinates,
                                     TemperatureCoordinates* temperatureCoordinates)
{
    _printAndSetIntValue(_xOnLCD, robotCoordinates->getX());
    _printAndSetIntValue(_yOnLCD, robotCoordinates->getY());
    _printAndSetIntValue(_fiOnLCD, robotCoordinates->getFi());
    _printAndSetIntValue(_vOnLSD, robotCoordinates->getV());
    _printAndSetIntValue(_liftOnLCD, furnaceCoordinates->getLift());
    _printAndSetIntValue(_liftFloorOnLCD, furnaceCoordinates->getLiftFloor());
    _printAndSetBoolValue(_doorsOnLCD, furnaceCoordinates->getDoors());
    _printAndSetBoolValue(_standOnLCD, furnaceCoordinates->getStand());
    _printAndSetIntValue(_highTemperatureOnLCD, temperatureCoordinates->getHighTemperature());
    _printAndSetIntValue(_lowTemperatureOnLCD, temperatureCoordinates->getLowTemperature());
    _printAndSetIntValue(_nowTemperatureOnLCD, temperatureCoordinates->getNowTemperature());
}
void MenuOnLCD::renewAllCoordiinates(RobotCoordinates* robotCoordinates,
                                     FurnaceCoordinates* furnaceCoordinates,
                                     TemperatureCoordinates* temperatureCoordinates)
{
    _renewIntValue(_xOnLCD, robotCoordinates->getX());
    _renewIntValue(_yOnLCD, robotCoordinates->getY());
    _renewIntValue(_fiOnLCD, robotCoordinates->getFi());
    _renewIntValue(_vOnLSD, robotCoordinates->getV());
    _renewIntValue(_liftOnLCD, furnaceCoordinates->getLift());
    _renewIntValue(_liftFloorOnLCD, furnaceCoordinates->getLiftFloor());
    _renewBoolValue(_doorsOnLCD, furnaceCoordinates->getDoors());
    _renewBoolValue(_standOnLCD, furnaceCoordinates->getStand());
    _renewIntValue(_highTemperatureOnLCD, temperatureCoordinates->getHighTemperature());
    _renewIntValue(_lowTemperatureOnLCD, temperatureCoordinates->getLowTemperature());
    _renewIntValue(_nowTemperatureOnLCD, temperatureCoordinates->getNowTemperature());
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

    _lcd.setCursor(_pCoordinateOnLCD->getCoordinateColumn(), _pCoordinateOnLCD->getCoordinateRow());
    _lcd.cursor();
    _lcd.blink();
}