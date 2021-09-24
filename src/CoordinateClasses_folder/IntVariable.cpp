#include "../../include/CoordinateClasses_folder/IntVariable.h"

IntVariable::IntVariable(int variable, int minVariable, int maxVariable)
{
    _variable = variable;
    _minVariable = minVariable;
    _maxVariable = maxVariable;
}
IntVariable IntVariable::createX()
{
    int variable = 50;
    int minVariable = 80;
    int maxVariable = 300;
    return IntVariable(variable, minVariable, maxVariable);
}
IntVariable IntVariable::createY()
{
    int variable = 0;
    int minVariable = -40;
    int maxVariable = 100;
    return IntVariable(variable, minVariable, maxVariable);
}
IntVariable IntVariable::createFi()
{
    int variable = 0;
    int minVariable = -130;
    int maxVariable = 130;
    return IntVariable(variable, minVariable, maxVariable);
}
IntVariable IntVariable::createV()
{
    int variable = 3;
    int minVariable = 0;
    int maxVariable = 9;
    return IntVariable(variable, minVariable, maxVariable);
}
IntVariable IntVariable::createLift()
{
    int variable = 120;
    int minVariable = 0;
    int maxVariable = 200;
    return IntVariable(variable, minVariable, maxVariable);
}
IntVariable IntVariable::createLiftFloor()
{
    int variable = 2;
    int minVariable = 1;
    int maxVariable = 4;
    return IntVariable(variable, minVariable, maxVariable);
}
IntVariable IntVariable::createHighTemperature()
{
    int variable = 1000;
    int minVariable = 40;
    int maxVariable = 1200;
    return IntVariable(variable, minVariable, maxVariable);
}
IntVariable IntVariable::createLowTemperature()
{
    int variable = 500;
    int minVariable = 30;
    int maxVariable = 1100;
    return IntVariable(variable, minVariable, maxVariable);
}
IntVariable IntVariable::createNowTemperature()
{
    int variable = 30;
    int minVariable = 10;
    int maxVariable = 2000;
    return IntVariable(variable, minVariable, maxVariable);
}
void IntVariable::addToVariable(int addingValue)
{
    _variable += addingValue;// dont integrite this line into "constrain"
    _variable = constrain(_variable, _minVariable, _maxVariable);
}
void IntVariable::setValue(int value)
{
    _variable = constrain(value, _minVariable, _maxVariable);
}
int IntVariable::getValue()
{
    return _variable;
}