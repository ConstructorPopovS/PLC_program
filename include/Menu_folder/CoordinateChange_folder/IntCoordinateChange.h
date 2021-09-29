#ifndef INTCOORDINATECHANGE_H
#define INTCOORDINATECHANGE_H
#include "CoordinateChange.h"
#include "CoordinateClasses_folder/IntConstrainedVariable.h"

class IntCoordinateChange : public CoordinateChange
{
private:
    IntConstrainedVariable* _coord;
    int _minusMinus;
    int _minus;
    int _plus;
    int _plusPlus;

public:
    IntCoordinateChange(IntConstrainedVariable* coord, int minusMinus, int minus, int plus, int plusPlus);
    virtual void minusMinus();
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};

#endif