#ifndef INTUPDATECOORD_H
#define INTUPDATECOORD_H
#include "UpdateCoord.h"
#include "CoordinateClasses_folder/IntVariable.h"

class IntUpdateCoord : public UpdateCoord
{
private:
    IntVariable *_coord;
    int _minusMinus;
    int _minus;
    int _plus;
    int _plusPlus;

public:
    IntUpdateCoord(IntVariable *coord, int minusMinus, int minus, int plus, int plusPlus);
    virtual void minusMinus();
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};

#endif