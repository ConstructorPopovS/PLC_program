#ifndef INTCOORDINATECHANGE_H
#define INTCOORDINATECHANGE_H
#include "CoordinateChange.h"
#include "../../CoordinateClasses_folder/IntConstrainedVariable.h"

class IntCoordinateChange : public CoordinateChange
{
private:
    IntConstrainedVariable *_pCoordinate;
    int _minusMinus;
    int _minus;
    int _plus;
    int _plusPlus;

public:
    IntCoordinateChange(String name, IntConstrainedVariable *coordinate, int minusMinus, int minus, int plus, int plusPlus);
    //it is neseccary to be overridden in derived class, because it is pure virtual functions
    virtual void minusMinus();
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};

#endif