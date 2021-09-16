#include "../../include/CoordinateClasses_folder/MenuModes.h"

MenuModes::MenuModes()
{
}

void MenuModes::setMode(String mode)
{
    _mode = mode;
}
String MenuModes::getMode()
{
    return(_mode);
}