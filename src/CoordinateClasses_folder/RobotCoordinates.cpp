#include "../../include/CoordinateClasses_folder/RobotCoordinates.h"

RobotCoordinates::RobotCoordinates()
{
}
RobotCoordinates *RobotCoordinates::_instance = NULL;
RobotCoordinates *RobotCoordinates::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new RobotCoordinates();
    }
    return _instance;
}
void RobotCoordinates::setCoordinates(int newX, int newY, int newFi, int newV)
{
    x.setValue(newX);
    y.setValue(newY);
    fi.setValue(newFi);
    v.setValue(newV);
}