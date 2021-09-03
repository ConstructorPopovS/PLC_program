#ifndef ROBOTCOORDINATES_H
#define ROBOTCOORDINATES_H
#include "../src/main.h"

struct RobotCoord
{
    int x = 100;
    int y = 0;
    int fi = 0;
    int v = 10;
};
struct BoolUpdateRobCoord
{
    bool x = false;
    bool y = false;
    bool fi = false;
    bool v = false;
};

class RobotCoordinates //TODO make the parrents class for FurnaseCoordinates and RobotCoordinates
{
private:
    RobotCoord _current;
    BoolUpdateRobCoord _boolNeedUpdate;
    void hasCoordinateChanged(int *currentCoordinate, int *targetCoordinate, bool *boolStructFlag, bool *flag);

protected:
public:
    RobotCoordinates(int targetX, int targetY, int targetFi, int targetV);
    RobotCoord target;
    bool hasAnythingChanged();
    BoolUpdateRobCoord getBoolNeedUpdate();
    void updateCoordinates();
    void setTargetCoord(int targetX, int targetY, int targetFi, int targetV);
    void setTargetX(int targetX);
    void setTargetY(int targetY);
    void setTargetFi(int targetFi);
    void setTargetV(int targetV);
    int getTargetX();
    int getTargetY();
    int getTargetFi();
    int getTargetV();
};
#endif