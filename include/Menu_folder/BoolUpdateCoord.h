#ifndef BOOLUPDATECOORD_H
#define BOOLUPDATECOORD_H
#include "../../src/main.h"
#include "UpdateCoord.h"
class BoolUpdateCoord : UpdateCoord
{
private:
    bool *_coordinate;

public:
    BoolUpdateCoord(bool *coordinate);
    virtual void minusMinus();
    virtual void minus();
    virtual void plus();
    virtual void plusPlus();
};
#endif