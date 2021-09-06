#include "../../include/CoordinateClasses_folder/RobotCoordinates.h"

RobotCoordinates::RobotCoordinates(int targetX, int targetY, int targetFi, int targetV)
{
    _target.x = targetX;
    _target.y = targetY;
    _target.fi = targetFi;
    _target.v = targetV;
}
bool RobotCoordinates::hasAnythingChanged()
{

    if ((_current.x != _target.x) ||
        (_current.y != _target.y) ||
        (_current.fi != _target.fi) ||
        (_current.v != _target.v))
    {
        return (true);
    }
    return (false);
}
bool RobotCoordinates::hasXChanged()
{
    if (_current.x != _target.x)
    {
        return (true);
    }
    return (false);
}
bool RobotCoordinates::hasYChanged()
{
    if (_current.y != _target.y)
    {
        return (true);
    }
    return (false);
}
bool RobotCoordinates::hasFiChanged()
{
    if (_current.fi != _target.fi)
    {
        return (true);
    }
    return (false);
}
bool RobotCoordinates::hasVChanged()
{
    if (_current.v != _target.v)
    {
        return (true);
    }
    return (false);
}
void RobotCoordinates::updateCoordinates()
{
    _current = _target;
}
void RobotCoordinates::setTargetCoord(int targetX, int targetY, int targetFi, int targetV)
{
    _target.x = targetX;
    _target.y = targetY;
    _target.fi = targetFi;
    _target.v = targetV;
}

void RobotCoordinates::setTargetX(int targetX)
{
    _target.x = targetX;
}
void RobotCoordinates::setTargetY(int targetY)
{
    _target.y = targetY;
}
void RobotCoordinates::setTargetFi(int targetFi)
{
    _target.fi = targetFi;
}
void RobotCoordinates::setTargetV(int targetV)
{
    _target.v = targetV;
}
int RobotCoordinates::getTargetX()
{
    return (_target.x);
}
int RobotCoordinates::getTargetY()
{
    return (_target.y);
}
int RobotCoordinates::getTargetFi()
{
    return (_target.fi);
}
int RobotCoordinates::getTargetV()
{
    return (_target.v);
}
