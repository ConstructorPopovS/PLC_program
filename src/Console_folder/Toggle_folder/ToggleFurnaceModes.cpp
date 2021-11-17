#include "../../../include/Console_folder/Toggle_folder/ToggleFurnaceModes.h"

ToggleFurnaceModes::ToggleFurnaceModes()
{
    pinMode(_PIN_HIGH, INPUT);
    pinMode(_PIN_LOW, INPUT);
}
ToggleFurnaceModes *ToggleFurnaceModes::_instance = NULL;
ToggleFurnaceModes *ToggleFurnaceModes::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new ToggleFurnaceModes();
    }
    return _instance;
}
String ToggleFurnaceModes::getMode()
{
    bool highT = digitalRead(_PIN_HIGH);
    bool lowT = digitalRead(_PIN_LOW);
    if (highT)
    {
        return String("HIGH");
    }
    if (lowT)
    {
        return String("LOW");
    }
    return String("NULL");
}
