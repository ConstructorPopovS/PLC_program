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

Robot robot(1, 2, 3, &Serial1, 4, 1000000L);//TODO 1000000L change to long(1000000) and tested
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup(void)
{
  lcd.init();      // Инициализация lcd
  lcd.backlight(); // Включаем подсветку
  Serial.begin(9600);
  Serial.setTimeout(50); //установка времени для считывания из порта
  lcd.clear();
  lcd.setCursor(3, 1);
  String text = "Turn on the mode";
  lcd.print(text);
  lcd.setCursor(5, 2);
  lcd.print("use the key");
  flag.currentMode = BLOCKED;

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
    targetMode = BLOCKED;
  }
  if (targetMode != flag.currentMode)
  {
    switch (targetMode)
    {
    case BLOCKED:
      lcd.clear();
      lcdSetCursorAndPrint(3, 1, "Turn on the mode");
      lcdSetCursorAndPrint(5, 2, "use the key");
      flag.currentMode = targetMode;
      break;
    case MANUAL:
      lcd.clear();
      lcdSetCursorAndPrint(0, 0, "Man");
      lcdSetCursorAndPrint(3, 0, String(x));
      lcdSetCursorAndPrint(6, 0, ";");
      lcdSetCursorAndPrint(7, 0, String(y));
      lcdSetCursorAndPrint(10, 0, ";");
      lcdSetCursorAndPrint(11, 0, String(fi));
      lcdSetCursorAndPrint(14, 0, "SK");
      lcdSetCursorAndPrint(16, 0, "*");
      lcdSetCursorAndPrint(18, 0, "V");
      lcd.setCursor(3, 0);
      flag.currentMode = targetMode;
      // manualControlMode();
      break;
    case AUTOPILOT:
      lcd.clear();
      lcdSetCursorAndPrint(3, 1, "AUTOPILOT MODE");
      flag.currentMode = targetMode;
      break;
    default:
      break;
    }
  }
}
void lcdSetCursorAndPrint(int column, int row, String text)
{
  lcd.setCursor(column, row);
  lcd.print(text);
}
void manualControlMode()
{
}