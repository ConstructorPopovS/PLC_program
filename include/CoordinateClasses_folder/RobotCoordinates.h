#ifndef ROBOTCOORDINATES_H
#define ROBOTCOORDINATES_H
#include "../src/main.h"
#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"

class RobotCoordinates
{

public:
    static RobotCoordinates *getInstance();
    void setCoordinates(int newX, int newY, int newFi, int newV);
    IntConstrainedVariable x = IntConstrainedVariable::createX();
    IntConstrainedVariable y = IntConstrainedVariable::createY();
    IntConstrainedVariable fi = IntConstrainedVariable::createFi();
    IntConstrainedVariable v = IntConstrainedVariable::createV();

private:
    RobotCoordinates();
    static RobotCoordinates *_instance;
};
#endif