#ifndef INTUPDATECOORD_H
#define INTUPDATECOORD_H
#include "UpdateCoord.h"

class IntUpdateCoord : public UpdateCoord
{
private:
    int *_coord;
    int _minusMinus;
    int _minus;
    int _plus;
    int _plusPlus;

public:
    IntUpdateCoord(int *coord, int minusMinus, int minus, int plus, int plusPlus);
    virtual void minusMinus();
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};

#endif