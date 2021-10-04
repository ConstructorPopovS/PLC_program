#ifndef COORDINATECHANGE_H
#define COORDINATECHANGE_H
#include "../../../src/main.h"

class CoordinateChange
{
private:
    String _nameOfCoordinate;

protected:
public:
    CoordinateChange(String name);
    // virtual ~CoordinateChange(){};
    String getNameOfCoordinate();
    virtual void minusMinus() = 0;// = 0 is necessary for pure virtual methods
    virtual void minus() = 0;
    virtual void plus() = 0;
    virtual void plusPlus() = 0;
};

#endif