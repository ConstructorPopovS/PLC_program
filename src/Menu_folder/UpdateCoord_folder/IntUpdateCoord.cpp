#include "../../../include/Menu_folder/UpdateCoord_folder/IntUpdateCoord.h"
IntUpdateCoord::IntUpdateCoord(int *coord, int minusMinus, int minus, int plus, int plusPlus)
{
    _coord = coord;
    _minusMinus = minusMinus;
    _minus = minus;
    _plus = plus;
    _plusPlus = plusPlus;
}
void IntUpdateCoord::minusMinus()
{
    *_coord -= _minusMinus;
}
void IntUpdateCoord::minus()
{
    *_coord -= _minus;
}
void IntUpdateCoord::plus()
{
    *_coord += _plus;
}
void IntUpdateCoord::plusPlus()
{
    *_coord += _plusPlus;
}