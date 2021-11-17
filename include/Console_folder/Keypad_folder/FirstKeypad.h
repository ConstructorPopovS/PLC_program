#ifndef FIRSTKEYPAD_H
#define FIRSTKEYPAD_H

#include "../../../src/main.h"
#include "Keypad.h"

enum NamesOfFirstKeypadsKeys
{
    X,
    Y,
    FI,
    V,
    LIFT,
    DOORS,
    STAND,
    TEMPERATURE,
    MINUS_MINUS,
    MINUS,
    PLUS,
    PLUS_PLUS
};

class FirstKeypad
{
public:
    FirstKeypad();
    NamesOfFirstKeypadsKeys getNameOfKey();
    bool keyIsPressed();

private:
    //----------------BEGINE of necessary part for using "Keypad.h" (library)--------------------------
    static const int _PIN_R1 = 8;
    static const int _PIN_R2 = 9;
    static const int _PIN_R3 = 11;
    static const int _PIN_C1 = 3;
    static const int _PIN_C2 = 5;
    static const int _PIN_C3 = 7;
    static const int _PIN_C4 = 10;
    static const int ROWS = 3;
    static const int COLS = 4;
    Keypad _firstCustomKeypad;
    char _enteredKeyChar;
    //define the cymbols on the buttons of the keypads
    char _charKeys[ROWS][COLS] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'}};
    //connect to the column pinouts of the keypad
    byte _rowPins[ROWS] = {_PIN_R1, _PIN_R2, _PIN_R3};
    byte _colPins[COLS] = {_PIN_C1, _PIN_C2, _PIN_C3, _PIN_C4};
    //----------------THE END of necessary part for using "Keypad.h" (library)--------------------------

    NamesOfFirstKeypadsKeys nameOfKey;
    NamesOfFirstKeypadsKeys _namesOfKeys[ROWS][COLS] = {
        {X, Y, FI, V},
        {LIFT, DOORS, STAND, TEMPERATURE},
        {MINUS_MINUS, MINUS, PLUS, PLUS_PLUS}};
    struct KeysData
    {
        char isPressed;
        int row;
        int column;
    } _keysData;
};

#endif