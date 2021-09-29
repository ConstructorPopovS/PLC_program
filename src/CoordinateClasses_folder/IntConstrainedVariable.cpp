#include "../../include/CoordinateClasses_folder/IntConstrainedVariable.h"

IntConstrainedVariable::IntConstrainedVariable(int variable, int minVariable, int maxVariable)
{
    _variable = variable;
    _minVariable = minVariable;
    _maxVariable = maxVariable;
}
IntConstrainedVariable IntConstrainedVariable::createX()
{
    int variable = 50;
    int minVariable = 80;
    int maxVariable = 300;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
IntConstrainedVariable IntConstrainedVariable::createY()
{
    int variable = 0;
    int minVariable = -40;
    int maxVariable = 100;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
IntConstrainedVariable IntConstrainedVariable::createFi()
{
    int variable = 0;
    int minVariable = -130;
    int maxVariable = 130;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
IntConstrainedVariable IntConstrainedVariable::createV()
{
    int variable = 3;
    int minVariable = 0;
    int maxVariable = 9;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
IntConstrainedVariable IntConstrainedVariable::createLift()
{
    int variable = 120;
    int minVariable = 0;
    int maxVariable = 200;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
IntConstrainedVariable IntConstrainedVariable::createLiftFloor()
{
    int variable = 2;
    int minVariable = 1;
    int maxVariable = 4;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
IntConstrainedVariable IntConstrainedVariable::createHighTemperature()
{
    int variable = 1000;
    int minVariable = 40;
    int maxVariable = 1200;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
IntConstrainedVariable IntConstrainedVariable::createLowTemperature()
{
    int variable = 500;
    int minVariable = 30;
    int maxVariable = 1100;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
IntConstrainedVariable IntConstrainedVariable::createNowTemperature()
{
    int variable = 30;
    int minVariable = 10;
    int maxVariable = 2000;
    return IntConstrainedVariable(variable, minVariable, maxVariable);
}
void IntConstrainedVariable::addToVariable(int addingValue)
{
    _variable += addingValue;// dont integrite this line into "constrain"
    _variable = constrain(_variable, _minVariable, _maxVariable);
}
void IntConstrainedVariable::setValue(int value)
{
    _variable = constrain(value, _minVariable, _maxVariable);
}
int IntConstrainedVariable::getValue()
{
    return _variable;
}