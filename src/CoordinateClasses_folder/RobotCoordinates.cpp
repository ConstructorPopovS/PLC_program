#include "../../include/CoordinateClasses_folder/RobotCoordinates.h"

RobotCoordinates::RobotCoordinates(int x, int y, int fi, int v)
{
    _coordinate.x = x;
    _coordinate.y = y;
    _coordinate.fi = fi;
    _coordinate.v = v;
}


void RobotCoordinates::setCoordinates(int x, int y, int fi, int v)
{
    _coordinate.x = x;
    _coordinate.y = y;
    _coordinate.fi = fi;
    _coordinate.v = v;
}

void RobotCoordinates::setX(int x)
{
    _coordinate.x = x;
}
void RobotCoordinates::setY(int y)
{
    _coordinate.y = y;
}
void RobotCoordinates::setFi(int fi)
{
    _coordinate.fi = fi;
}
void RobotCoordinates::setV(int v)
{
    _coordinate.v = v;
}
int RobotCoordinates::getX()
{
    return (_coordinate.x);
}
int RobotCoordinates::getY()
{
    return (_coordinate.y);
}
int RobotCoordinates::getFi()
{
    return (_coordinate.fi);
}
int RobotCoordinates::getV()
{
    return (_coordinate.v);
}
int* RobotCoordinates::getRX()
{
    return (&_coordinate.x);
}
int* RobotCoordinates::getRY()
{
    return (&_coordinate.y);
}
int* RobotCoordinates::getRFi()
{
    return (&_coordinate.fi);
}
int* RobotCoordinates::getRV()
{
    return (&_coordinate.v);
}
