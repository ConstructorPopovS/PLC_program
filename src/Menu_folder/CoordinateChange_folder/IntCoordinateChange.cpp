#include "../../../include/Menu_folder/CoordinateChange_folder/IntCoordinateChange.h"
IntCoordinateChange::IntCoordinateChange(String name, IntConstrainedVariable *coordinate, int minusMinus, int minus, int plus, int plusPlus)
    : CoordinateChange(name)
{
    _coordinate = coordinate;
    _minusMinus = minusMinus;
    _minus = minus;
    _plus = plus;
    _plusPlus = plusPlus;
}

void IntCoordinateChange::minusMinus()
{
    _coordinate->addToVariable(_minusMinus);
}
void IntCoordinateChange::minus()
{
    _coordinate->addToVariable(_minus);
}
void IntCoordinateChange::plus()
{
    _coordinate->addToVariable(_plus);
}
void IntCoordinateChange::plusPlus()
{
    _coordinate->addToVariable(_plusPlus);
}