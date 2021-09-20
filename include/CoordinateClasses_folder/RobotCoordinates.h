#ifndef ROBOTCOORDINATES_H
#define ROBOTCOORDINATES_H
#include "../src/main.h"
#include "../../include/CoordinateClasses_folder/IntVariable.h"

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
    IntVariable *getPX();
    IntVariable *getPY();
    IntVariable *getPFi();
    IntVariable *getPV();

private:
IntVariable _x;
IntVariable _y;
IntVariable _fi;
IntVariable _v;
};
#endif