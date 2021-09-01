#include "../../include/Menu_folder/IntAction.h"

IntAction::IntAction(int *rCoordinate)
{
    _rCoordinate = rCoordinate;
}
void IntAction::plus(int delta)
{
    *_rCoordinate += delta;
}