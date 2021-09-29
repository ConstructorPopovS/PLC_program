#ifndef ROBOTCOORDINATES_H
#define ROBOTCOORDINATES_H
#include "../src/main.h"
#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"

class RobotCoordinates
{

public:
    RobotCoordinates();
    void setCoordinates(int x, int y, int fi, int v);
    void setX(int x);
    void setY(int y);
    void setFi(int fi);
    void setV(int v);
    int getX();
    int getY();
    int getFi();
    int getV();
    IntConstrainedVariable* getPX();
    IntConstrainedVariable* getPY();
    IntConstrainedVariable* getPFi();
    IntConstrainedVariable* getPV();

private:
IntConstrainedVariable _x;
IntConstrainedVariable _y;
IntConstrainedVariable _fi;
IntConstrainedVariable _v;
};
#endif