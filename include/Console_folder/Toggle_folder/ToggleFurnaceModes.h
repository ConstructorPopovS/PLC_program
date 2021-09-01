#ifndef TOGGLEFURNACEMODES_H
#define TOGGLEFURNACEMODES_H
#include "../../../src/main.h"

class ToggleFurnaceModes
{
private:
const int _PIN_HIGH = 27;
const int _PIN_LOW = 29;
protected:
public:
    ToggleFurnaceModes();
    String getMode();
};

#endif