#ifndef TOGGLEFURNACEMODES_H
#define TOGGLEFURNACEMODES_H
#include "../../../src/main.h"

class ToggleFurnaceModes
{
private:
    const int _PIN_HIGH = 23;
    const int _PIN_LOW = 25;
    ToggleFurnaceModes();
    static ToggleFurnaceModes *_instance;

protected:
public:
    static ToggleFurnaceModes *getInstance();
    String getMode();
};

#endif