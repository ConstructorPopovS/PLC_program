#include "../../../include/Console_folder/Toggle_folder/ToggleFurnaceModes.h"

ToggleFurnaceModes::ToggleFurnaceModes()
{
    pinMode(_PIN_HIGH, INPUT);
    pinMode(_PIN_LOW, INPUT);
}
String ToggleFurnaceModes::getMode()
{
    bool high = digitalRead(_PIN_HIGH);
    bool low = digitalRead(_PIN_LOW);
    if (high)
    {
        return String("HIGH");
    }
    if (low)
    {
        return String("LOW");
    }
    return String("NULL");
}
