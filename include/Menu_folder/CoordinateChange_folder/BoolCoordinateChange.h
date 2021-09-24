#ifndef BOOLCOORDINATECHANGE_H
#define BOOLCOORDINATECHANGE_H
#include "CoordinateChange.h"

class BoolCoordinateChange : public CoordinateChange
{
private:
    bool *_coordinate;

public:
    BoolCoordinateChange(bool *coord);
    virtual void minusMinus();
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};
#endif