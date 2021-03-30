//подключение функций из других файлов
#include "main.h"
#include "RobotClass.h"

int x = 150;
int y = 0;
int fi = 0;

Robot robot(1, 2, 3, &Serial1, 4, 1000000L);
void setup(void)
{
  Serial.begin(9600);
  Serial.setTimeout(50);
}

/*--------------------------------------------------------------------*/
void loop(void)
{
  if (Serial.available())
  {
    x = Serial.parseInt();
    robot.setX(x);
    Serial.println("x = " + String(x));

  }
  
}