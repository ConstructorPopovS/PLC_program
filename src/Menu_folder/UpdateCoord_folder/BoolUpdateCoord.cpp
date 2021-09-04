#include "../../../include/Menu_folder/UpdateCoord_folder/BoolUpdateCoord.h"

BoolUpdateCoord::BoolUpdateCoord(bool *coord)
{
*_coordinate = coord;
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