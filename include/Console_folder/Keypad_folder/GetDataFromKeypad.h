#ifndef GETDATAFROMKEYPAD_H
#define GETDATAFROMKEYPAD_H

#include "../../../src/main.h"
#include "Keypad.h"

// Keypad
#define PIN_C1 3
#define PIN_C2 5
#define PIN_C3 7
#define PIN_C4 10
#define PIN_R1 8
#define PIN_R2 9
#define PIN_R3 11
#define PIN_R4 12
#define PIN_R5 4
#define PIN_R6 6
#define PIN_R7 24
#define PIN_R8 22
#define PIN_R9 16
#define PIN_R10 2
#define ROWS 10
#define COLS 4

struct ParametersOfKey
{
    int row;
    int column;
    int keyInt;
    bool keyIsPressed;
};

class GetDataFromKeypad
{
public:
    GetDataFromKeypad();
    ParametersOfKey getParametersOfKey();

private:
    char _keyIsPressed();
    ParametersOfKey _parametersOfKey;
    char _enteredKeyChar;
    Keypad _customKeypad;
    //define the cymbols on the buttons of the keypads
    char _charKeys[ROWS][COLS] = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L'},
        {'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T'},
        {'U', 'V', 'W', 'X'},
        {'1', '2', '3', '!'},
        {'4', '5', '6', '@'},
        {'7', '8', '9', '#'},
        {'^', '0', '%', '$'}};
    // define the names of the buttons of the keypad
    int _intKeys[ROWS][COLS] = {
        {16, 17, 18, 19},
        {20, 21, 22, 23},
        {24, 25, 26, 27},
        {28, 29, 30, 31},
        {32, 33, 34, 35},
        {36, 37, 38, 39},
        {1, 2, 3, 10},
        {4, 5, 6, 11},
        {7, 8, 9, 12},
        {15, 0, 14, 13}};
    //connect to the column pinouts of the keypad
    byte _rowPins[ROWS] = {PIN_R1, PIN_R2, PIN_R3, PIN_R4, PIN_R5, PIN_R6, PIN_R7, PIN_R8, PIN_R9, PIN_R10}; //connect to the row pinouts of the keypad
    byte _colPins[COLS] = {PIN_C1, PIN_C2, PIN_C3, PIN_C4};
};

#endif