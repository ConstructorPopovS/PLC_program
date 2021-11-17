#ifndef BOOLCOORDINATECHANGE_H
#define BOOLCOORDINATECHANGE_H
#include "CoordinateChange.h"

class BoolCoordinateChange : public CoordinateChange
{
private:
    bool *_coordinate;

public:
    BoolCoordinateChange(String name, bool *coord);
    virtual void minusMinus();//it is neseccary to be overridden in derived class, because it is pure virtual functions
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};
#endif