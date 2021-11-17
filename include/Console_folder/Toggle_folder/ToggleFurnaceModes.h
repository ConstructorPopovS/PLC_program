#ifndef TOGGLEFURNACEMODES_H
#define TOGGLEFURNACEMODES_H
#include "../../../src/main.h"

class ToggleFurnaceModes
{
private:
const int _PIN_HIGH = 23;
const int _PIN_LOW = 25;
protected:
public:
    ToggleFurnaceModes();
    String getMode();
};

#endif