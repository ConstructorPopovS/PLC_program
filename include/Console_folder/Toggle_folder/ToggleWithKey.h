#ifndef TOGGLEWITHKEY_H
#define TOGGLEWITHKEY_H
#include "../../../src/main.h"

class ToggleWithKey
{
private:
const int _PIN_MANUAL = 27;
const int _PIN_AUTOPILOT = 29;
protected:
public:
    ToggleWithKey();
    String getMode();
};

#endif