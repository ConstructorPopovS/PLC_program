#include "../../include/CoordinateClasses_folder/RobotCoordinates.h"

RobotCoordinates::RobotCoordinates() : _x(IntConstrainedVariable::createX()),
                                       _y(IntConstrainedVariable::createY()),
                                       _fi(IntConstrainedVariable::createFi()),
                                       _v(IntConstrainedVariable::createV())
{
}

void RobotCoordinates::setCoordinates(int x, int y, int fi, int v)
{
    _x.setValue(x);
    _y.setValue(y);
    _fi.setValue(fi);
    _v.setValue(v);
}

void RobotCoordinates::setX(int x)
{
    _x.setValue(x);
}
void RobotCoordinates::setY(int y)
{
    _y.setValue(y);
}
void RobotCoordinates::setFi(int fi)
{
    _fi.setValue(fi);
}
void RobotCoordinates::setV(int v)
{
    _v.setValue(v);
}
int RobotCoordinates::getX()
{
    return _x.getValue();
}
int RobotCoordinates::getY()
{
    return _y.getValue();
}
int RobotCoordinates::getFi()
{
    return _fi.getValue();
}
int RobotCoordinates::getV()
{
    return _v.getValue();
}
IntConstrainedVariable *RobotCoordinates::getPX()
{
    return &_x;
}
IntConstrainedVariable *RobotCoordinates::getPY()
{
    return &_y;
}
IntConstrainedVariable *RobotCoordinates::getPFi()
{
    return &_fi;
}
IntConstrainedVariable *RobotCoordinates::getPV()
{
    return &_v;
}
