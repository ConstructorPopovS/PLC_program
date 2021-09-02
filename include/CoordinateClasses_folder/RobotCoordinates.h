#ifndef ROBOTCOORDINATES_H
#define ROBOTCOORDINATES_H

#include "../src/main.h"
struct RobotCoord
{
    int x;
    int y;
    int fi;
    int vX;
    int vY;
    int omegaFi;
};
struct BoolUpdateRobCoord
{
    bool x = false;
    bool y = false;
    bool fi = false;
    bool vX = false;
    bool vY = false;
    bool omegaFi = false;
};

class RobotCoordinates
{
private:
    RobotCoord _robotCoord;
    RobotCoord _targetRobotCoord;
    BoolUpdateRobCoord _boolRobCoordNeedUpdate;
    void hasCoordinateChanged(int *coordinate, int *targetCoordinate, bool *boolRobflag, bool *flag);

protected:
public:
    RobotCoordinates(RobotCoord targetRobotCoord);
    bool hasAnythingChanged(RobotCoord targetRobotCoord);
    BoolUpdateRobCoord getBoolCoordNeedUpdate();
    void updateCoordinates();
    void setRobotCoord(RobotCoord robotCoord);
    RobotCoord getRobotCoord();
    void setTargetX(int targetX);
    void setTargetY(int targetY);
    void setTargetFi(int targetFi);
    void setTargetVX(int targetVX);
    void setTargetVY(int trrgetVY);
    void setTargetOmegaFi(int targetOmegaFi);
};

#endif