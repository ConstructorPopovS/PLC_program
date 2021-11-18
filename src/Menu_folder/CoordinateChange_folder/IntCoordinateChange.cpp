#include "../../../include/Menu_folder/CoordinateChange_folder/IntCoordinateChange.h"
IntCoordinateChange::IntCoordinateChange(String name, IntConstrainedVariable* coordinate, int minusMinus, int minus, int plus, int plusPlus)
    : CoordinateChange(name)
{
    _pCoordinate = coordinate;
    _minusMinus = minusMinus;
    _minus = minus;
    _plus = plus;
    _plusPlus = plusPlus;
}

void IntCoordinateChange::minusMinus()
{
    _pCoordinate->addToVariable(_minusMinus);
}
void IntCoordinateChange::minus()
{
    _pCoordinate->addToVariable(_minus);
}
void IntCoordinateChange::plus()
{
    _pCoordinate->addToVariable(_plus);
}
void IntCoordinateChange::plusPlus()
{
    _pCoordinate->addToVariable(_plusPlus);
}