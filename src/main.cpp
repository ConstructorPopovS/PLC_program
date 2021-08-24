//подключение функций из других файлов
#include "main.h"
#include "RobotClass.h"
#include <Wire.h>              // библиотека для работы с I2C
#include <LiquidCrystal_I2C.h> // библиотека для экранчика

class LCDClass
{
public:
  LCDClass();
  LiquidCrystal_I2C lcd; // Задаем адрес и размерность дисплея.
  void print(int row = 0, int column = 0);
};
LCDClass::LCDClass()
{
  LiquidCrystal_I2C lcd(0x27,20,4);
  lcd.init();      // Инициализация lcd
  lcd.backlight(); // Включаем подсветку
  //Serial.println("Test");
  delay(2000);
}
void LCDClass::print(int row, int column)
{
  lcd.setCursor(row, column);
  lcd.print("lcd.print is working");
}

int x = 150;
int y = 0;
int fi = 0;

Robot robot(1, 2, 3, &Serial1, 4, 1000000L);
LCDClass *lcd1 = nullptr;
//LiquidCrystal_I2C lcd2(0x27, 20, 4);

void setup(void)
{
  if (lcd1 == nullptr)
  {
    lcd1 = new LCDClass();
  }
  // lcd2.init();      // Инициализация lcd
  // lcd2.backlight(); // Включаем подсветку
  // lcd2.setCursor(0, 0);
  // lcd2.print("Hallo");
  Serial.begin(9600);
  // Serial.setTimeout(50); //установка времени для считывания из порта
  //robot.setX(x);
  // robot.setY(y);
  delay(2000);
  // Serial.println("getX = " + String(robot.getX()));
  Serial.println("Priveeet");
}

/*--------------------------------------------------------------------*/
void loop(void)
{
  lcd1->print();
  Serial.println("Oy");
  delay(1000);
}