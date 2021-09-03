#include "../../include/CoordinateClasses_folder/RobotCoordinates.h"

RobotCoordinates::RobotCoordinates(int targetX, int targetY, int targetFi, int targetV)
{
    target.x = targetX;
    target.y = targetY;
    target.fi = targetFi;
    target.v = targetV;
}
void RobotCoordinates::hasCoordinateChanged(int *currentCoordinate, int *targetCoordinate, bool *boolStructFlag, bool *flag)
{
    if (currentCoordinate != targetCoordinate)
    {
        *boolStructFlag = true;
        *flag = true;
    }
}
bool RobotCoordinates::hasAnythingChanged()
{
    bool flag = false;
    hasCoordinateChanged(&_current.x, &target.x, &_boolNeedUpdate.x, &flag);
    hasCoordinateChanged(&_current.y, &target.y, &_boolNeedUpdate.y, &flag);
    hasCoordinateChanged(&_current.fi, &target.fi, &_boolNeedUpdate.fi, &flag);
    hasCoordinateChanged(&_current.v, &target.v, &_boolNeedUpdate.v, &flag);
    return (flag);
}
BoolUpdateRobCoord RobotCoordinates::getBoolNeedUpdate()
{
    return (_boolNeedUpdate);
}
void RobotCoordinates::updateCoordinates()
{
    _current = target;
}
void RobotCoordinates::setTargetCoord(int targetX, int targetY, int targetFi, int targetV)
{
    target.x = targetX;
    target.y = targetY;
    target.fi = targetFi;
    target.v = targetV;
}

void RobotCoordinates::setTargetX(int targetX)
{
    target.x = targetX;
}
void RobotCoordinates::setTargetY(int targetY)
{
    target.y = targetY;
}
void RobotCoordinates::setTargetFi(int targetFi)
{
    target.fi = targetFi;
}
void RobotCoordinates::setTargetV(int targetV)
{
    target.v = targetV;
}
int RobotCoordinates::getTargetX()
{
    return(target.x);
}
int RobotCoordinates::getTargetY()
{
    return(target.y);
}
int RobotCoordinates::getTargetFi()
{
    return(target.fi);
}
int RobotCoordinates::getTargetV()
{
    return(target.v);
}
