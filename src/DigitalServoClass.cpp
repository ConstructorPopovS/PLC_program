#include "DigitalServoClass.h"

DigitalServo::DigitalServo(int servoId)
{
  _servoId = servoId;
}
void DigitalServo::init(HardwareSerial *servoSerial,int HALF_DUPLEX_DIRECTION_PIN, const long servoDefaultBaud)
{
  _HALF_DUPLEX_DIRECTION_PIN = HALF_DUPLEX_DIRECTION_PIN;
  servo_init(servoSerial, _HALF_DUPLEX_DIRECTION_PIN, servoDefaultBaud);
}
void DigitalServo::setTimeout(int inputTimeout) { _timeout = inputTimeout; };
int DigitalServo::getTimeout() { return _timeout; };
void DigitalServo::setSpeed(float setSpeed)
{
  servo_set(_servoId, SERVO_REGISTER_MOVING_SPEED, setSpeed, _timeout);
}
void DigitalServo::setAngleDeg(float setAngleDeg)
{
  _setAngleDeg = setAngleDeg;
  _positionCorrect();
  _setAngle = radians(_setAngleDeg) / M_PI;
  servo_set(_servoId, SERVO_REGISTER_GOAL_ANGLE, _setAngle, _timeout);
}
float DigitalServo::getAngleDeg()
{
  servo_get(_servoId, SERVO_REGISTER_PRESENT_ANGLE, &_getAngle, _timeout);
  _getAngleDeg = degrees(_getAngle * M_PI);
  return _getAngleDeg;
}
servo_error_t DigitalServo::ping()
{
  _error = servo_ping(_servoId, _timeout);
  return _error;
}
void DigitalServo::_positionCorrect()
{
  float copy = _setAngleDeg;
  if (_lastSetAngleDeg > _setAngleDeg)
  {
    _setAngleDeg -= 3.5;
  }
  else if (_lastSetAngleDeg < _setAngleDeg)
  {
    _setAngleDeg += 3.5;
  }
  _lastSetAngleDeg = copy;
}
