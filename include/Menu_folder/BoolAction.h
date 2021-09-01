#ifndef BOOLACTION_H
#define BOOLACTION_H

#include "../../src/main.h"
class BoolAction
{
private:
    bool *_rCoordinate;

public:
    void changeBoolTo(bool state);
    BoolAction(bool *rCoordinate);
};

#endif