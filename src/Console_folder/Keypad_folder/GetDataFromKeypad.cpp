#include "../../../include/Console_folder/Keypad_folder/GetDataFromKeypad.h"

GetDataFromKeypad::GetDataFromKeypad() : _customKeypad(makeKeymap(_charKeys), _rowPins, _colPins, ROWS, COLS)
{
}
char GetDataFromKeypad::_keyIsPressed()
{
    _enteredKeyChar = _customKeypad.getKey();
    return _enteredKeyChar;
}
KeysData GetDataFromKeypad::getKeysData()
{
    if (_keyIsPressed())
    {
        _keysData.keyIsPressed = true;
        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (_enteredKeyChar == _charKeys[row][col])
                {
                    _keysData.keyInt = _intKeys[row][col];
                    _keysData.row = row;
                    _keysData.column = col;
                    _keysData.keyIsPressed = true;
                    return (_keysData);
                }
            }
        }
    }
    else
    {
        _keysData.keyIsPressed = false;
    }
    return (_keysData);
}