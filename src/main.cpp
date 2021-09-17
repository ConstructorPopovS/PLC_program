//подключение функций из других файлов
// #include "Robot_folder/RobotClass.h"
#include "main.h"
#include "../include/Menu_folder/ManualMenuMode.h"

ManualMenuMode manualMenu;
void setup(void)
{
  Serial.begin(9600);
  Serial.setTimeout(500); //установка времени для считывания из порта
  manualMenu.init();
}

/*--------------------------------------------------------------------*/
void loop(void)
{
  manualMenu.doMenu();
}