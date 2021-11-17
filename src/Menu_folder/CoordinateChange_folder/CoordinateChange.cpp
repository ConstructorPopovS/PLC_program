#include "../../../include/Menu_folder/CoordinateChange_folder/CoordinateChange.h"

CoordinateChange::CoordinateChange(String name) : _nameOfCoordinate(name)
{
}
String CoordinateChange::getNameOfCoordinate()
{
    return _nameOfCoordinate;
}