#include "../../include/CoordinateClasses_folder/RobotCoordinates.h"

RobotCoordinates::RobotCoordinates(RobotCoord targetRobotCoord)
{
    _targetRobotCoord = targetRobotCoord;
    _robotCoord = _targetRobotCoord;
}
void RobotCoordinates::hasCoordinateChanged(int *coordinate, int *targetCoordinate, bool *boolRobflag, bool *flag)
{
    if (coordinate != targetCoordinate)
    {
        *boolRobflag = true;
        *flag = true;
    }
}
bool RobotCoordinates::hasAnythingChanged(RobotCoord targetRobotCoord)
{
    bool flag = false;
hasCoordinateChanged(&_robotCoord.x, &_targetRobotCoord.x, &_boolRobCoordNeedUpdate.x, &flag);
hasCoordinateChanged(&_robotCoord.y, &_targetRobotCoord.y, &_boolRobCoordNeedUpdate.y, &flag);
hasCoordinateChanged(&_robotCoord.fi, &_targetRobotCoord.fi, &_boolRobCoordNeedUpdate.fi, &flag);
hasCoordinateChanged(&_robotCoord.vX, &_targetRobotCoord.vX, &_boolRobCoordNeedUpdate.vX, &flag);
hasCoordinateChanged(&_robotCoord.vY, &_targetRobotCoord.vY, &_boolRobCoordNeedUpdate.vY, &flag);
hasCoordinateChanged(&_robotCoord.omegaFi, &_targetRobotCoord.omegaFi, &_boolRobCoordNeedUpdate.omegaFi, &flag);
    return (flag);
}
BoolUpdateRobCoord RobotCoordinates::getBoolCoordNeedUpdate()
{
    return(_boolRobCoordNeedUpdate);
}
void RobotCoordinates::updateCoordinates()
{
    _robotCoord = _targetRobotCoord;
}
void RobotCoordinates::setRobotCoord(RobotCoord robotCoord)
{
    _targetRobotCoord = robotCoord;
}
RobotCoord RobotCoordinates::getRobotCoord()
{
    return(_robotCoord);
}
void RobotCoordinates::setTargetX(int targetX)
{
_targetRobotCoord.x = targetX;
}
void RobotCoordinates::setTargetY(int targetY)
{
_targetRobotCoord.y = targetY;
}
void RobotCoordinates::setTargetFi(int targetFi)
{
_targetRobotCoord.fi = targetFi;
}
void RobotCoordinates::setTargetVX(int targetVX)
{
_targetRobotCoord.vX = targetVX;
}
void RobotCoordinates::setTargetVY(int targetVY)
{
_targetRobotCoord.vY = targetVY;
}
void RobotCoordinates::setTargetOmegaFi(int targetOmegaFi)
{
_targetRobotCoord.omegaFi = targetOmegaFi;
}