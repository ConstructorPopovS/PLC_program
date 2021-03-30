#ifndef ROBOTCLASS_H
#define ROBOTCLASS_H
#include "DigitalServoClass.h"

class Robot
{
public:
  Robot(int servoA1Id = 1, int servoA2Id = 2, int servoA3Id = 3,
        HardwareSerial *servoSerial = &Serial1, int HALF_DUPLEX_DIRECTION_PIN = 4,
        const long servoDefaultBaud = 1000000);
  DigitalServo a1;
  DigitalServo a2;
  DigitalServo a3;
  void setCoordinate(int x, int y, int fi);
  void setX(int x);
  void setY(int y);
  void setFi(int fi);
  void setSpeed(float vX, float vY, float omegaFi);
  void getXYFi();//решение прямой задачи кинематики
  int getX();
  int getY();
  int getFi();

private:
  float _xYToAngleA2();
  float _xYToAngleA3();
  //work with WCS
  void _xYCoordinateLimitation();
  //data of robot
  int _L_PL = 160; //длинна плеча в мм lenght of  the second and the third link
  //variables of Robot positions in the workshop coordinate system
  int _x = 100;
  const int _X_MIN = 60;
  const int _X_MAX = 300;
  int _y = 0;
  const int _Y_MIN = -40;
  const int _Y_MAX = 100;
  int _fi = 0;
  const int _FI_MIN = 0;
  const int _FI_MAX = 260;
  const int _R_MAX = 300; //max distance from A2 to last point of link A3
  float _angleA1;         //(DEGREES) angle A1 in the workshop coordinate system
  float _angleA2;         //(DEGREES) angle A2 in the workshop coordinate system
  float _angleA3;         //(DEGREES) angle A3 in the workshop coordinate system
  int _vX;
  int _vY;
  int _omegaFi;
  //variables of servo
  float _angleA1servo;
  const int _K_A1 = 1;
  const int _B_A1 = 90 + 43;
  float _angleA2servo;
  const int _K_A2 = -1;
  const int _B_A2 = 278;
  float _angleA3servo;
  const int _K_A3 = 1;
  const int _B_A3 = 93;
};
#endif