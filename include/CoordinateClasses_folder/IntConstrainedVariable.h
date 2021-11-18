#ifndef INTCONSTRAINEDVARIABLE_H
#define INTCONSTRAINEDVARIABLE_H
#include "../../src/main.h"

class IntConstrainedVariable
{
private:
    int _variable;
    int _minVariable;
    int _maxVariable;

public:
    IntConstrainedVariable(int variable = 100, int minVariable = 80, int maxVariable = 120);
    static IntConstrainedVariable createX();
    static IntConstrainedVariable createY();
    static IntConstrainedVariable createFi();
    static IntConstrainedVariable createV();
    static IntConstrainedVariable createLift();
    static IntConstrainedVariable createLiftFloor();
    static IntConstrainedVariable createHighTemperature();
    static IntConstrainedVariable createLowTemperature();
    static IntConstrainedVariable createNowTemperature();
    void addToVariable(int addingValue);
    void setValue(int value);
    int getValue();
};

#endif