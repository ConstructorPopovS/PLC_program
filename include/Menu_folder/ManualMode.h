#ifndef MANUALCLASS_H
#define MANUALCLASS_H
#include "../../src/main.h"
#include "IntUpdateCoord.h"
#include "BoolUpdateCoord.h"
#include "../CoordinateClasses_folder/RobotCoordinates.h"

class ManualMode
{
private:
RobotCoordinates _robotCoord;
IntUpdateCoord _xUpdate;
IntUpdateCoord _yUpdate;
IntUpdateCoord _fiUpdate;
IntUpdateCoord _vUpdate;
public:
    ManualMode();
};

#endif