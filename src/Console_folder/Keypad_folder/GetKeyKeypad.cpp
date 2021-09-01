#include "../../../include/Console_folder/Keypad_folder/GetKeyKeypad.h"

GetKeyKeypad::GetKeyKeypad() : _customKeypad(makeKeymap(_charKeys), _rowPins, _colPins, ROWS, COLS)
{
}
char GetKeyKeypad::_keyIsPressed()
{
    _enteredKeyChar = _customKeypad.getKey();
    return _enteredKeyChar;
}
ParametersOfKey GetKeyKeypad::getParametersOfKey()
{
    if (_keyIsPressed())
    {
        _parametersOfKey.keyIsPressed = true;
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (_enteredKeyChar == _charKeys[row][col])
                {
                    _parametersOfKey.keyInt = _intKeys[row][col];
                    _parametersOfKey.row = row;
                    _parametersOfKey.column = col;
                    _parametersOfKey.keyIsPressed = true;
                    return (_parametersOfKey);
                }
            }
        }
    }
    else {
        _parametersOfKey.keyIsPressed = false;
        return (_parametersOfKey);
    }
}