#include "../../../include/Menu_folder/CoordinateChange_folder/BoolCoordinateChange.h"

BoolCoordinateChange::BoolCoordinateChange(bool *coord)
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