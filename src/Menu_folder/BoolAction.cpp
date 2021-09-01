#include "../../include/Menu_folder/BoolAction.h"

BoolAction::BoolAction(bool *rCoordinate)
{
    _rCoordinate = rCoordinate;
}
void BoolAction::changeBoolTo(bool state)
{
    *_rCoordinate = state;
}