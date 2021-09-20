#ifndef INTVARIABLE_H
#define INTVARIABLE_H
#include "../../src/main.h"

class IntVariable
{
private:
    int _variable;
    int _minVariable;
    int _maxVariable;
    IntVariable(int variable, int minVariable, int maxVariable);

public:
    static IntVariable createX();
    static IntVariable createY();
    static IntVariable createFi();
    static IntVariable createV();
    static IntVariable createLift();
    static IntVariable createLiftFloor();
    static IntVariable createHighTemperature();
    static IntVariable createLowTemperature();
    static IntVariable createNowTemperature();
    void addToVariable(int addingValue);
    void setValue(int value);
    int getValue();
};

#endif