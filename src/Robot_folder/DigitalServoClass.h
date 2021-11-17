#ifndef DIGITALSERVOCLASS_H
#define DIGITALSERVOCLASS_H
#include <Dynamixel_Servo.h>
#include "../main.h"

class DigitalServo
{
public:
  DigitalServo(int servoId = 1);
  void init(HardwareSerial *servoSerial = &Serial1, int HALF_DUPLEX_DIRECTION_PIN = 4, const long servoDefaultBaud = 1000000);
  void setTimeout(int inputTimeout);
  void setAngleDeg(float setAngleDeg); //минимальный шаг - 0.004рад = 0.28град
  void setSpeed(float setSpeed);         //заметная разница до 20, плавно двигается от 0.2
  servo_error_t ping();
  int getTimeout();
  float getAngleDeg();

private:
  void _positionCorrect();
  uint8_t _servoId;
  int _HALF_DUPLEX_DIRECTION_PIN;
  int _timeout = 50;  //milliseconds time, before error: "timeout"
  float _accuracyDeg; //точность отработки градусной меры угла сервоприводом
  servo_error_t _error;
  float _lastSetAngleDeg;
  float _setAngleDeg;
  float _getAngleDeg;
  float _setAngle; //угол, который корректно отработает функция библиотеки Dynamixel_Servo
  float _getAngle; //угол, который присылает функция библиотеки Dynamixel_Servo
};
#endif