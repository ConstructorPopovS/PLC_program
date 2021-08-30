//подключение функций из других файлов
#include "main.h"
#include "RobotClass.h"

int x = 150;
int y = -10;
int fi = 0;
int levelOfLift = 1;
bool openDors = 0;
int temperatureTarget = 1000;
int temperatureCurrent = 950;

KeypadClass keypad;
LCDClass lcdClass;
Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested

void setup(void)
{
  Serial.begin(9600);
  Serial.setTimeout(50); //установка времени для считывания из порта
  lcdClass.init();
  lcdClass.menu(x, y, fi, levelOfLift, openDors, temperatureTarget, temperatureCurrent);
  pinMode(PIN_TOGGLE_FURNACE_MODES_HIGH, INPUT);
  pinMode(PIN_TOGGLE_FURNACE_MODES_LOW, INPUT);
  pinMode(PIN_TOGGLE_WITH_KEY_AUTOPILOT, INPUT);
  pinMode(PIN_TOGGLE_WITH_KEY_MANUAL, INPUT);
}

/*--------------------------------------------------------------------*/
void loop(void)
{
  if (digitalRead(PIN_TOGGLE_WITH_KEY_MANUAL))
  {
    lcdClass.setTargetMode(MANUAL);
  }
  else if (digitalRead(PIN_TOGGLE_WITH_KEY_AUTOPILOT))
  {
    lcdClass.setTargetMode(AUTOPILOT);
  }
  else
  {
    lcdClass.setTargetMode(BLOCKED);
  }
  lcdClass.menu(x, y, fi, levelOfLift, openDors, temperatureTarget, temperatureCurrent);
  keypad.buttonActions(&x, &y, &fi, &levelOfLift, &openDors, &temperatureTarget);
}
