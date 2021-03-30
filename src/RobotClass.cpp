#include "RobotClass.h"

Robot::Robot(int servoA1Id, int servoA2Id, int servoA3Id, HardwareSerial *servoSerial,
             int HALF_DUPLEX_DIRECTION_PIN, const long servoDefaultBaud) : a1(servoA1Id), a2(servoA2Id), a3(servoA3Id)
{
  a1.init(servoSerial, HALF_DUPLEX_DIRECTION_PIN, servoDefaultBaud);
  a2.init(servoSerial, HALF_DUPLEX_DIRECTION_PIN, servoDefaultBaud);
  a3.init(servoSerial, HALF_DUPLEX_DIRECTION_PIN, servoDefaultBaud);
}
float Robot::_xYToAngleA2()
{
  _angleA2 = 180 - degrees(atan((double)_y / (double)_x)) - degrees(acos((hypot((double)_x, (double)_y)) / (2 * _L_PL)));
  return _angleA2;
}
float Robot::_xYToAngleA3()
{
  _angleA3 = degrees(acos((hypot((double)_x, (double)_y)) / (2 * _L_PL))) - degrees(atan((double)_y / (double)_x));
  return _angleA3;
}
void Robot::_xYCoordinateLimitation()
{
  _x = constrain(_x, _X_MIN, _X_MAX);
  _y = constrain(_y, _Y_MIN, _Y_MAX);

  //Ограничение y круговой зоной:
  if (hypot((double)_x, (double)_y) > (double)_R_MAX)
  {                                                 //Если гипотенуза (катеты x и y) больше значения R_MAX, то
    _y = sqrt(sq((double)_R_MAX) - sq((double)_x)); //Уменьшить y так, чтоб при заданом x он попадал в круговую зону радиусом R_MAX
  }
}
void Robot::setCoordinate(int x, int y, int fi)
{
  //ограничение координат:
  _x = x;
  _y = y;
  _fi = fi;
  _xYCoordinateLimitation();
  _fi = constrain(_fi, _FI_MIN, _FI_MAX);
  //обратная задача кинематики (определение углов, исходя из координат):
  _angleA1 = fi;
  _angleA2 = _xYToAngleA2();
  _angleA3 = _xYToAngleA3();
  //перевод углов из СК робота в цеху в углы на сервоприводы
  _angleA1servo = _K_A1 * _angleA1 + _B_A1;
  _angleA2servo = _K_A2 * _angleA2 + _B_A2;
  _angleA3servo = _K_A3 * _angleA3 + _B_A3;
  //отправка целевых углов на сервоприводы
  a1.setAngleDeg(_angleA1servo);
  a2.setAngleDeg(_angleA2servo);
  a3.setAngleDeg(_angleA3servo);
}
void Robot::setX(int x)
{
  //ограничение координат:
  _x = x;
  _xYCoordinateLimitation();
  //обратная задача кинематики (определение углов, исходя из координат):
  _angleA2 = _xYToAngleA2();
  _angleA3 = _xYToAngleA3();
  //перевод углов из СК робота в цеху в углы на сервоприводы
  _angleA2servo = _K_A2 * _angleA2 + _B_A2;
  _angleA3servo = _K_A3 * _angleA3 + _B_A3;
  //отправка целевых углов на сервоприводы
  a2.setAngleDeg(_angleA2servo);
  a3.setAngleDeg(_angleA3servo);
}
void Robot::setY(int y)
{
  //ограничение координат:
  _y = y;
  _xYCoordinateLimitation();
  //обратная задача кинематики (определение углов, исходя из координат):
  _angleA2 = _xYToAngleA2();
  _angleA3 = _xYToAngleA3();
  //перевод углов из СК робота в цеху в углы на сервоприводы
  _angleA2servo = _K_A2 * _angleA2 + _B_A2;
  _angleA3servo = _K_A3 * _angleA3 + _B_A3;
  //отправка целевых углов на сервоприводы
  a2.setAngleDeg(_angleA2servo);
  a3.setAngleDeg(_angleA3servo);
}
void Robot::setFi(int fi)
{
  //ограничение координат:
  _fi = fi;
  _fi = constrain(_fi, _FI_MIN, _FI_MAX);
  //обратная задача кинематики (определение углов, исходя из координат):
  _angleA1 = fi;
  //перевод углов из СК робота в цеху в углы на сервоприводы
  _angleA1servo = _K_A1 * _angleA1 + _B_A1;
  //отправка целевых углов на сервоприводы
  a1.setAngleDeg(_angleA1servo);
}
void Robot::setSpeed(float vX, float vY, float omegaFi)
{

  _omegaFi = omegaFi;
  a1.setSpeed(_omegaFi);
}
void Robot::getXYFi()
{
  //получение положения сервоприводов
  _angleA1servo = a1.getAngleDeg();
  _angleA2servo = a2.getAngleDeg();
  _angleA3servo = a3.getAngleDeg();
  //перевод положения сервоприводов в СК робота в цеху
  _angleA1 = (_angleA1servo - _B_A1) / _K_A1;
  _angleA2 = (_angleA2servo - _B_A2) / _K_A2;
  _angleA3 = (_angleA3servo - _B_A3) / _K_A3;
  //решение прямой задачи кинематики, х и у в мм, fi в градусах
  _x = 320*cos(radians(_angleA3 + (180 - _angleA2 - _angleA3)/2))*cos(radians((180 - _angleA2 - _angleA3)/2));
  _y = 320*cos(radians(_angleA3 + (180 - _angleA2 - _angleA3)/2))*sin(radians((180 - _angleA2 - _angleA3)/2));
  _fi = _angleA1;
}
int Robot::getX()
{
  getXYFi();
  return(_x);
}
int Robot::getY()
{
  getXYFi();
  return(_y);
}
int Robot::getFi()
{
  getXYFi();
  return(_fi);
}