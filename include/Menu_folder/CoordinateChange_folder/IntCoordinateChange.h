#ifndef INTCOORDINATECHANGE_H
#define INTCOORDINATECHANGE_H
#include "CoordinateChange.h"
#include "CoordinateClasses_folder/IntVariable.h"

class IntCoordinateChange : public CoordinateChange
{
private:
    IntVariable *_coord;
    int _minusMinus;
    int _minus;
    int _plus;
    int _plusPlus;
    IntCoordinateChange(IntVariable *coord, int minusMinus, int minus, int plus, int plusPlus);

public:
    virtual void minusMinus();
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};

#endif