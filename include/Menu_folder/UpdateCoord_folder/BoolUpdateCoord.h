#ifndef BOOLUPDATECOORD_H
#define BOOLUPDATECOORD_H
#include "UpdateCoord.h"

class BoolUpdateCoord : public UpdateCoord
{
private:
    bool *_coordinate;

public:
    BoolUpdateCoord(bool *coord);
    virtual void minusMinus();
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};
#endif