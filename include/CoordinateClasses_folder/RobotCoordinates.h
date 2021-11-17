#ifndef ROBOTCOORDINATES_H
#define ROBOTCOORDINATES_H
#include "../src/main.h"
#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"

struct StructRobotCoordinates
{
    IntConstrainedVariable x = IntConstrainedVariable::createX();
    IntConstrainedVariable y = IntConstrainedVariable::createY();
    IntConstrainedVariable fi = IntConstrainedVariable::createFi();
    IntConstrainedVariable v = IntConstrainedVariable::createV();
};

class RobotCoordinates
{

public:
    RobotCoordinates();
    void setCoordinates(int x, int y, int fi, int v);
    void setCoordinates(StructRobotCoordinates structRobotCoordinates);
    void setX(int x);
    void setY(int y);
    void setFi(int fi);
    void setV(int v);
    StructRobotCoordinates getStructOfCoordinates();
    int getX();
    int getY();
    int getFi();
    int getV();
    IntConstrainedVariable *getPX();
    IntConstrainedVariable *getPY();
    IntConstrainedVariable *getPFi();
    IntConstrainedVariable *getPV();

private:
    StructRobotCoordinates _robotCoordinates;
};
#endif