#include "../../include/Menu_folder/ManualMode.h"

ManualMode::ManualMode() : _robotCoordClass(100, 20, 0, 4),
                           _xUpdateCoordClass(&_robotCoord.targetRobotCoord.x, 1, 1, 10, 10),
                           _yUpdateCoordClass(&_robotCoord.targetRobotCoord.y, 1, 1, 10, 10),
                           _fiUpdateCoordClass(&_robotCoord.targetRobotCoord.fi, 1, 1, 10, 10),
                           _vUpdateCoordClass(&_robotCoord.targetRobotCoord.v, 1, 1, 5, 5)
{
}