//подключение функций из других файлов
#include "main.h"
#include "Robot_folder/RobotClass.h"


MainCoordinate mainCoordinate;
LCDClass lcdClass;
Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested

void setup(void)
{
  Serial.begin(9600);
  Serial.setTimeout(50); //установка времени для считывания из порта
  lcdClass.init();
  lcdClass.menu(mainCoordinate.x, mainCoordinate.y, mainCoordinate.fi,
                mainCoordinate.levelOfLift, mainCoordinate.openDors,
                mainCoordinate.temperatureTarget, mainCoordinate.temperatureCurrent);
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
  lcdClass.menu(mainCoordinate.x, mainCoordinate.y, mainCoordinate.fi,
                mainCoordinate.levelOfLift, mainCoordinate.openDors,
                mainCoordinate.temperatureTarget, mainCoordinate.temperatureCurrent);
}
