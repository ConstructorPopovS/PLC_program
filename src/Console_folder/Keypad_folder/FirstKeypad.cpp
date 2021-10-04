#include "../../../include/Console_folder/Keypad_folder/FirstKeypad.h"

FirstKeypad::FirstKeypad() : _firstCustomKeypad(makeKeymap(_charKeys), _rowPins, _colPins, ROWS, COLS)
{
}
bool FirstKeypad::keyIsPressed()
{
    _keysData.isPressed = _firstCustomKeypad.getKey();
    if (_keysData.isPressed)
    {
        Serial.println("key is " + String(_keysData.isPressed));
        return true;
    }
    return false;
}
NamesOfFirstKeypadsKeys FirstKeypad::getNameOfKey()
{

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (_keysData.isPressed == _charKeys[row][col])
            {
                nameOfKey = _namesOfKeys[row][col];
                Serial.println("struct name of key is " + String(nameOfKey));
                _keysData.row = row;
                _keysData.column = col;
            }
        }
    }
    return nameOfKey;
}