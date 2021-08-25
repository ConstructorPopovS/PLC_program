//подключение функций из других файлов
#include "main.h"
#include "RobotClass.h"
#include <Wire.h>              // библиотека для работы с I2C
#include <LiquidCrystal_I2C.h> // библиотека для экранчика

int x = 150;
int y = 0;
int fi = 0;
modes targetMode;
Flag flag;

Robot robot(1, 2, 3, &Serial1, 4, 1000000L);
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup(void)
{
  lcd.init();      // Инициализация lcd
  lcd.backlight(); // Включаем подсветку
  Serial.begin(9600);
  Serial.setTimeout(50); //установка времени для считывания из порта
  lcd.clear();
  lcd.setCursor(3, 1);
  lcd.print("Turn on the mode");
  lcd.setCursor(5, 2);
  lcd.print("use the key");
  flag.currentMode = CLOSED;

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
    targetMode = MANUAL;
  }
  else if (digitalRead(PIN_TOGGLE_WITH_KEY_AUTOPILOT))
  {
    targetMode = AUTOPILOT;
  }
  else
  {
    targetMode = CLOSED;
  }
  if (targetMode != flag.currentMode)
  {
    switch (targetMode)
    {
    case CLOSED:
      lcd.clear();
      lcd.setCursor(3, 1);
      lcd.print("Turn on the mode");
      lcd.setCursor(5, 2);
      lcd.print("use the key");
      flag.currentMode = CLOSED;
      break;
    case MANUAL:
      lcd.clear();
      lcd.setCursor(3, 1);
      lcd.print("MANUAL MODE");
      flag.currentMode = MANUAL;
      break;
    case AUTOPILOT:
      lcd.clear();
      lcd.setCursor(3, 1);
      lcd.print("AUTOPILOT MODE");
      flag.currentMode = AUTOPILOT;
      break;
    default:
      break;
    }
  }
}