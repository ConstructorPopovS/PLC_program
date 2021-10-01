#include "../../include/CoordinateClasses_folder/RobotCoordinates.h"

RobotCoordinates::RobotCoordinates()
{
}

void RobotCoordinates::setCoordinates(int x, int y, int fi, int v)
{
    _robotCoordinates.x.setValue(x);
    _robotCoordinates.y.setValue(y);
    _robotCoordinates.fi.setValue(fi);
    _robotCoordinates.v.setValue(v);
}
void RobotCoordinates::setCoordinates(StructRobotCoordinates structRobotCoordinates)
{
    _robotCoordinates = structRobotCoordinates;
}
void RobotCoordinates::setX(int x)
{
    _robotCoordinates.x.setValue(x);
}
void RobotCoordinates::setY(int y)
{
    _robotCoordinates.y.setValue(y);
}
void RobotCoordinates::setFi(int fi)
{
    _robotCoordinates.fi.setValue(fi);
}
void RobotCoordinates::setV(int v)
{
    _robotCoordinates.v.setValue(v);
}
StructRobotCoordinates RobotCoordinates::getStructOfCoordinates()
{
    return _robotCoordinates;
}
int RobotCoordinates::getX()
{
    return _robotCoordinates.x.getValue();
}
int RobotCoordinates::getY()
{
    return _robotCoordinates.y.getValue();
}
int RobotCoordinates::getFi()
{
    return _robotCoordinates.fi.getValue();
}
int RobotCoordinates::getV()
{
    return _robotCoordinates.v.getValue();
}
IntConstrainedVariable *RobotCoordinates::getPX()
{
    return &_robotCoordinates.x;
}
IntConstrainedVariable *RobotCoordinates::getPY()
{
    return &_robotCoordinates.y;
}
IntConstrainedVariable *RobotCoordinates::getPFi()
{
    return &_robotCoordinates.fi;
}
IntConstrainedVariable *RobotCoordinates::getPV()
{
    return &_robotCoordinates.v;
}
