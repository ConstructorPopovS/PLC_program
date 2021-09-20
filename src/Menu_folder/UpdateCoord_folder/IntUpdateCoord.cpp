#include "../../../include/Menu_folder/UpdateCoord_folder/IntUpdateCoord.h"
IntUpdateCoord::IntUpdateCoord(IntVariable* coord, int minusMinus, int minus, int plus, int plusPlus)
{
    _coord = coord;
    _minusMinus = minusMinus;
    _minus = minus;
    _plus = plus;
    _plusPlus = plusPlus;
}
void IntUpdateCoord::minusMinus()
{
    _coord->addToVariable(_minusMinus);
}
void IntUpdateCoord::minus()
{
    _coord->addToVariable(_minus);
}
void IntUpdateCoord::plus()
{
    _coord->addToVariable(_plus);
}
void IntUpdateCoord::plusPlus()
{
    _coord->addToVariable(_plusPlus);
}