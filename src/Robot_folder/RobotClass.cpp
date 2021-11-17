#include "RobotClass.h"

Robot::Robot(int servoA1Id, int servoA2Id, int servoA3Id, HardwareSerial *servoSerial,
             int HALF_DUPLEX_DIRECTION_PIN, const long servoDefaultBaud) : a1(servoA1Id), a2(servoA2Id), a3(servoA3Id)
{
  a1.init(servoSerial, HALF_DUPLEX_DIRECTION_PIN, servoDefaultBaud);
  a2.init(servoSerial, HALF_DUPLEX_DIRECTION_PIN, servoDefaultBaud);
  a3.init(servoSerial, HALF_DUPLEX_DIRECTION_PIN, servoDefaultBaud);
  a1.setSpeed(0.5);
  a2.setSpeed(0.5);
  a3.setSpeed(0.5);
}
void Robot::_xYToAngleA2A3WorkshopCS()
{
  int _L_PL = 160; //длинна плеча в мм lenght of  the second and the third link
  _angleA2WorkshopCS = 180 - degrees(atan((double)_y / (double)_x)) - degrees(acos((hypot((double)_x, (double)_y)) / (2 * _L_PL)));
  _angleA3WorkshopCS = degrees(acos((hypot((double)_x, (double)_y)) / (2 * _L_PL))) - degrees(atan((double)_y / (double)_x));
}
void Robot::_xYFiCoordinateLimitation()
{
  _x = constrain(_x, _X_MIN, _X_MAX);
  _y = constrain(_y, _Y_MIN, _Y_MAX);
  _fi = constrain(_fi, _FI_MIN, _FI_MAX);

  //Ограничение y круговой зоной:
  if (hypot((double)_x, (double)_y) > (double)_R_MAX)
  {                                                 //Если гипотенуза (катеты x и y) больше значения R_MAX, то
    _y = sqrt(sq((double)_R_MAX) - sq((double)_x)); //Уменьшить y так, чтоб при заданом x он попадал в круговую зону радиусом R_MAX
  }
}
void Robot::_angleWorkshopCSToServoCS()
{
  const int _K_A1 = 1;
  const int _B_A1 = 90 + 43;
  const int _K_A2 = -1;
  const int _B_A2 = 278;
  const int _K_A3 = 1;
  const int _B_A3 = 93;
  //перевод углов из СК робота в цеху в углы на сервоприводы
  _angleA1servo = _K_A1 * _angleA1WorkshopCS + _B_A1;
  _angleA2servo = _K_A2 * _angleA2WorkshopCS + _B_A2;
  _angleA3servo = _K_A3 * _angleA3WorkshopCS + _B_A3;
}
void Robot::setCoordinate(int x, int y, int fi)
{
  //ограничение координат:
  _x = x;
  _y = y;
  _fi = fi;
  _xYFiCoordinateLimitation();
  //обратная задача кинематики (определение углов, исходя из координат):
  _angleA1WorkshopCS = fi;
  _xYToAngleA2A3WorkshopCS(); //расчет углов А2 и А3 исходя из целевых х и у
  _angleWorkshopCSToServoCS();
  //отправка целевых углов на сервоприводы
  a1.setAngleDeg(_angleA1servo);
  a2.setAngleDeg(_angleA2servo);
  a3.setAngleDeg(_angleA3servo);
}
void Robot::setX(int x)
{
  //ограничение координат:
  _x = x;
  _xYFiCoordinateLimitation();
  //обратная задача кинематики (определение углов, исходя из координат):
  _xYToAngleA2A3WorkshopCS();
  _angleWorkshopCSToServoCS();
  //отправка целевых углов на сервоприводы
  a2.setAngleDeg(_angleA2servo);
  a3.setAngleDeg(_angleA3servo);
}
void Robot::setY(int y)
{
  //ограничение координат:
  _y = y;
  _xYFiCoordinateLimitation();
  //обратная задача кинематики (определение углов, исходя из координат):
  _xYToAngleA2A3WorkshopCS();
  _angleWorkshopCSToServoCS();
  //отправка целевых углов на сервоприводы
  a2.setAngleDeg(_angleA2servo);
  a3.setAngleDeg(_angleA3servo);
}
void Robot::setFi(int fi)
{
  //ограничение координат:
  _fi = fi;
  _xYFiCoordinateLimitation();
  //обратная задача кинематики (определение углов, исходя из координат):
  _angleA1WorkshopCS = fi;
  //перевод углов из СК робота в цеху в углы на сервоприводы
  _angleWorkshopCSToServoCS();
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
  _angleWorkshopCSToServoCS();
  //решение прямой задачи кинематики, х и у в мм, fi в градусах
  _x = 320 * cos(radians(_angleA3WorkshopCS + (180 - _angleA2WorkshopCS - _angleA3WorkshopCS) / 2)) * cos(radians((180 - _angleA2WorkshopCS - _angleA3WorkshopCS) / 2));
  _y = 320 * cos(radians(_angleA3WorkshopCS + (180 - _angleA2WorkshopCS - _angleA3WorkshopCS) / 2)) * sin(radians((180 - _angleA2WorkshopCS - _angleA3WorkshopCS) / 2));
  _fi = _angleA1WorkshopCS;
}
int Robot::getX()
{
  getXYFi();
  return (_x);
}
int Robot::getY()
{
  getXYFi();
  return (_y);
}
int Robot::getFi()
{
  getXYFi();
  return (_fi);
}