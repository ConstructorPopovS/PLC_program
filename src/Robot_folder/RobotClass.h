#ifndef ROBOTCLASS_H
#define ROBOTCLASS_H
#include "DigitalServoClass.h"

class Robot
{
public:
  // Robot robot(1, 2, 3, &Serial1, 4, 1000000L); //TODO 1000000L change to long(1000000) and tested
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
  void getXYFi(); //решение прямой задачи кинематики исходя из полученных углов от сервоприводов
  int getX();
  int getY();
  int getFi();
  // TODO: setVXYFi (int Vx (1-5 sm/s), ...)

private:
  const int _X_MIN = 60;
  const int _X_MAX = 300;
  const int _Y_MIN = -40;
  const int _Y_MAX = 200;
  const int _FI_MIN = 0;
  const int _FI_MAX = 260;
  const int _R_MAX = 300; //max distance from A2 to last point of link A3

  void _xYToAngleA2A3WorkshopCS();
  //work with Workshop Coordinate System
  void _xYFiCoordinateLimitation();
  void _angleWorkshopCSToServoCS();
  //variables of Robot positions in the Workshop Coordinate System
  int _x = 100;
  int _y = 0;
  int _fi = 0;
  float _angleA1WorkshopCS; //(DEGREES) angle A1 in the workshop coordinate system
  float _angleA2WorkshopCS; //(DEGREES) angle A2 in the workshop coordinate system
  float _angleA3WorkshopCS; //(DEGREES) angle A3 in the workshop coordinate system
  int _vX;
  int _vY;
  int _omegaFi;
  //variables of servo
  float _angleA1servo;
  float _angleA2servo;
  float _angleA3servo;
};
#endif