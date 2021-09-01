#ifndef INTACTION_H
#define INTACTION_H

#include "../../src/main.h"
class IntAction
{
private:
    int *_rCoordinate;

public:
    void plus(int delta);
    IntAction(int *rCoordinate);
};

#endif