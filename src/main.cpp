//подключение функций из других файлов
// #include "Robot_folder/RobotClass.h"
#include "main.h"
// #include "../include/Menu_folder/ManualMenuMode.h"
#include "../include/LCD_folder/MenuOnLCD.h"
// ManualMenuMode manualMenu;
MenuOnLCD menuOnLCD;
void setup(void)
{
  menuOnLCD.initAndBacklight();
  Serial.begin(9600);
  Serial.setTimeout(1000); //установка времени для считывания из порта
  menuOnLCD.printConstPartOfMode("MANUAL");
  menuOnLCD.printAllCoordiinates(80, 90, 100, 1, 110, 2, false, false, 1000, 600, 36);
  // manualMenu.initLCD();
}

/*--------------------------------------------------------------------*/
void loop(void)
{
  if (Serial.available())
  {
    int a = Serial.parseInt();
    bool doors = false;
    if (a == 0) {doors = false;}
    else {doors = true;}
    menuOnLCD.renewAllCoordiinates(80, 90, 100, 1, 110, 2, doors, false, 1000, 600, 36);
  }
  // manualMenu.doMenu();
}