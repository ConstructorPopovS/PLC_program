/*
Класс для клавиатуры пульта ПЛК.
Входные в класс параметры, которые он берет из main.cpp и меняет:
====================SHARED VARIABLES FOR ALL COMPONENTS PLC PROGRAMM===================
int x = 150;
int y = 0;
int fi = 0;
int levelOfLift = 1;
bool openDors = 0;
int temperatureTarget = 1000;
 =====================================================================================
*/
#include "KeypadClass.h"

KeypadClass::KeypadClass() : customKeypad(makeKeymap(charKeys), rowPins, colPins, ROWS, COLS)
{
}
char KeypadClass::keyIsPressed()
{
    enteredKeyChar = customKeypad.getKey();
    return enteredKeyChar;
}
int KeypadClass::buttonActions(int *x, int *y, int *fi, int *temperatureTarget, int *levelOfLift, bool *openDors)
{
    nameOfKey = NameOfKey(getEnteredKeypadInt());
    if ((nameOfKey >= 0) && (nameOfKey <= 15))
    {
        return (nameOfKey);
    }
    else if ((nameOfKey > 15) && (nameOfKey <= 39)) //if the key is from command keypads
    {
        switch (nameOfKey)
        {
        case T_MINUS:
            *temperatureTarget -= 1;
            break;
        case T_PLUS:
            *temperatureTarget += 1;
            break;
        case OPEN_DORS:
            *openDors = 1;
            break;
        case CLOSE_DORS:
            *openDors = 0;
            break;
        case L_MINUS_MINUS:
            *levelOfLift -= 1;
            break;
        case L_MINUS:
            *levelOfLift -= 1; //TODO flag for only onse -=
            break;
        case L_PLUS:
            *levelOfLift += 1; //TODO flag for only onse +=
            break;
        case L_PLUS_PLUS:
            *levelOfLift += 1;
            break;
        case L1:
            *levelOfLift = 10; //TODO test right parameter of 1Level and create the constant for it
            break;
        case L2:
            *levelOfLift = 20; //TODO test right parameter of 2Level and create the constant for it
            break;
        case L3:
            *levelOfLift = 30; //TODO test right parameter of 3Level and create the constant for it
            break;
        case L4:
            *levelOfLift = 40; //TODO test right parameter of 4Level and create the constant for it
            break;
        case X_MINUS_MINUS:
            *x -= 1;
            break;
        case X_MINUS:
            *x -= 1; //TODO flag for only onse -=
            break;
        case X_PLUS:
            *x += 1; //TODO flag for only onse +=
            break;
        case X_PLUS_PLUS:
            *x += 1;
            break;
        case Y_MINUS_MINUS:
            *y -= 1;
            break;
        case Y_MINUS:
            *y -= 1; //TODO flag for only onse -=
            break;
        case Y_PLUS:
            *y += 1; //TODO flag for only onse +=
            break;
        case Y_PLUS_PLUS:
            *y += 1;
            break;
        case FI_MINUS_MINUS:
            *fi -= 1;
            break;
        case FI_MINUS:
            *fi -= 1; //TODO flag for only onse -=
            break;
        case FI_PLUS:
            *fi += 1; //TODO flag for only onse +=
            break;
        case FI_PLUS_PLUS:
            *fi += 1;
            break;
        default:
            break;
        }
        return 16; //code, that command button is pressed
    }
    else
    {
        // if everything is ok, then this should not happen
        Serial.println("ERROR:SOMETHING IS WRONG WITH THE KEYPADS");
        return 17;
    }
}
int KeypadClass::getEnteredKeypadInt()
{
    int returnIntKeys;
    bool flag = 0;
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (enteredKeyChar == charKeys[row][col])
            {
                returnIntKeys = intKeys[row][col];
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return (returnIntKeys);
}