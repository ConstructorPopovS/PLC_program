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
 файлы, необходимые для класса: Key.h, Key.cpp, Keypad.h, Keypad.cpp, KeypadClass.h, KeypadClass.cpp
in your main.h you have to: 
#include "Keypad.h"
#include "KeypadClass.h"
*/

#ifndef KEYPADKLASS_H
#define KEYPADKLASS_H
#include "main.h"

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
// размер клавиатуры
#define ROWS 10
#define COLS 4

class KeypadClass
{
public:
  KeypadClass();
  char enteredKeyChar;
  int enteredKeyInt;
  char keyIsPressed();
  int buttonActions(int *x, int *y, int *fi,int *levelOfLift, bool *openDors, int *temperatureTarget);
  //buttonActions return: 0-9 is numbers; 10-15 is menu commands; 15-39 is commands for manipulator, furnace, lift and doors
private:
  Keypad customKeypad;
  //define the cymbols on the buttons of the keypads
  char charKeys[ROWS][COLS] = {
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
  int intKeys[ROWS][COLS] = {
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
  // Names of Keypad key
  enum NameOfKey
  {
    UP = 10,
    DOWN,
    RIGH,
    LEFT,
    OK,
    ESC,
    T_MINUS,
    T_PLUS,
    OPEN_DORS,
    CLOSE_DORS,
    L_MINUS_MINUS,
    L_MINUS,
    L_PLUS,
    L_PLUS_PLUS,
    L1,
    L2,
    L3,
    L4,
    X_MINUS_MINUS,
    X_MINUS,
    X_PLUS,
    X_PLUS_PLUS,
    Y_MINUS_MINUS,
    Y_MINUS,
    Y_PLUS,
    Y_PLUS_PLUS,
    FI_MINUS_MINUS,
    FI_MINUS,
    FI_PLUS,
    FI_PLUS_PLUS,
  };
  //connect to the column pinouts of the keypad
  byte rowPins[ROWS] = {PIN_R1, PIN_R2, PIN_R3, PIN_R4, PIN_R5, PIN_R6, PIN_R7, PIN_R8, PIN_R9, PIN_R10}; //connect to the row pinouts of the keypad
  byte colPins[COLS] = {PIN_C1, PIN_C2, PIN_C3, PIN_C4};
  NameOfKey nameOfKey;
  int getEnteredKeypadInt();
};

#endif