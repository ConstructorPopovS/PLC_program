#include "../../../include/Console_folder/Keypad_folder/GetDataFromKeypad.h"

GetDataFromKeypad::GetDataFromKeypad() : _customKeypad(makeKeymap(_charKeys), _rowPins, _colPins, ROWS, COLS)
{
}
bool GetDataFromKeypad::keyIsPressed()
{
    _enteredKeyChar = _customKeypad.getKey();
    if (_enteredKeyChar)
    {
        return true;
    }
    return false;
}
NamesOfKeys GetDataFromKeypad::getNameOfKey()
{

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (_enteredKeyChar == _charKeys[row][col])
            {
                nameOfKey = _namesOfKeys[row][col];
            }
        }
    }

    return nameOfKey;
}
