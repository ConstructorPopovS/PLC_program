//подключение функций из других файлов
// #include "Robot_folder/RobotClass.h"
#include "main.h"
#include "../include/Menu_folder/MenuMediator.h"

MenuMediator menuMediator;
void setup(void)
{
  Serial.begin(9600);
  Serial.setTimeout(1000); //установка времени для считывания из порта
  menuMediator.initLCD();
}

/*--------------------------------------------------------------------*/
void loop(void)
{
  menuMediator.doMenu();

}
