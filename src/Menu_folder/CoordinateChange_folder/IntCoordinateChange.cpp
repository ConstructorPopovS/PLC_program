#include "../../../include/Menu_folder/CoordinateChange_folder/IntCoordinateChange.h"
IntCoordinateChange::IntCoordinateChange(IntConstrainedVariable* coord, int minusMinus, int minus, int plus, int plusPlus)
{
    _coord = coord;
    _minusMinus = minusMinus;
    _minus = minus;
    _plus = plus;
    _plusPlus = plusPlus;
}
void IntCoordinateChange::minusMinus()
{
    _coord->addToVariable(_minusMinus);
}
void IntCoordinateChange::minus()
{
    _coord->addToVariable(_minus);
}
void IntCoordinateChange::plus()
{
    _coord->addToVariable(_plus);
}
void IntCoordinateChange::plusPlus()
{
    _coord->addToVariable(_plusPlus);
}