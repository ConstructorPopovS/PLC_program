#include "../../include/CoordinateClasses_folder/MenuCoordinates.h"

MenuCoordinates::MenuCoordinates()
{
}

void MenuCoordinates::setMode(String mode)
{
    _mode = mode;
}
String MenuCoordinates::getMode()
{
    return(_mode);
}