#include "../../../include/Menu_folder/CoordinateChange_folder/BoolCoordinateChange.h"

BoolCoordinateChange::BoolCoordinateChange(String name, bool* coord) : CoordinateChange(name)
{
_pCoordinate = coord;
}
void BoolCoordinateChange::minusMinus()
{
    *_pCoordinate = false;
}
void BoolCoordinateChange::minus()
{
    *_pCoordinate = false;
}
void BoolCoordinateChange::plus()
{
    *_pCoordinate = true;
}
void BoolCoordinateChange::plusPlus()
{
    *_pCoordinate = true;
}