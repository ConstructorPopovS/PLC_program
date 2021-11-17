#include "../../../include/Menu_folder/CoordinateChange_folder/BoolCoordinateChange.h"

BoolCoordinateChange::BoolCoordinateChange(String name, bool *coord) : CoordinateChange(name)
{
_coordinate = coord;
}
void BoolCoordinateChange::minusMinus()
{
    *_coordinate = false;
}
void BoolCoordinateChange::minus()
{
    *_coordinate = false;
}
void BoolCoordinateChange::plus()
{
    *_coordinate = true;
}
void BoolCoordinateChange::plusPlus()
{
    *_coordinate = true;
}