#include "../../include/Menu_folder/BoolUpdateCoord.h"

BoolUpdateCoord::BoolUpdateCoord(bool *coordinate)
{
*_coordinate = coordinate;
}
void BoolUpdateCoord::minusMinus()
{
    *_coordinate = false;
}
void BoolUpdateCoord::minus()
{
    *_coordinate = false;
}
void BoolUpdateCoord::plus()
{
    *_coordinate = true;
}
void BoolUpdateCoord::plusPlus()
{
    *_coordinate = true;
}