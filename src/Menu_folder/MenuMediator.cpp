#include "../include/Menu_folder/MenuMediator.h"

MenuMediator::MenuMediator()
{
    _menuMode = &_autopilotMenuMode;
}
bool MenuMediator::_modeExists(String mode)
{
    for (int i = 0; i < _numberOfModes; i++)
    {
        if (mode == _namesOfModes[i])
        {
            return true;
        }
    }
    return false;
}
void MenuMediator::_setCurrentMode(String mode)
{
    if (_modeExists(mode))
    {
        _currentMode = mode;
    }
}
void MenuMediator::_setTargetMode(String mode)
{
    if (_modeExists(mode))
    {
        _targetMode = mode;
    }
}
String MenuMediator::_getCurrentMode()
{
    return (_currentMode);
}
String MenuMediator::_getTargetMode()
{
    return (_targetMode);
}
void MenuMediator::initLCD()
{
    _autopilotMenuMode.initLCD();
    _lockedMenuMode.initLCD();
    _manualMenuMode.initLCD();
    _menuMode = &_lockedMenuMode;
    _menuMode->printConstPartOfMode();
    // _menuMode = &_autopilotMenuMode;
    // _menuMode->printConstPartOfMode();
}
void MenuMediator::doMenu()
{
    _setTargetMode(_toggleKey.getMode());

    if (_targetMode != _currentMode)
    {
        _setCurrentMode(_targetMode);
        if (_currentMode == "MANUAL")
        {
            _menuMode = &_manualMenuMode;
        }
        if (_currentMode == "AUTOPILOT")
        {
            _menuMode = &_autopilotMenuMode;
        }
        if (_currentMode == "LOCKED")
        {
            _menuMode = &_lockedMenuMode;
        }
        _menuMode->printConstPartOfMode();
    }
    if (_menuMode != NULL)
    {
        _menuMode->doMenu();
    }
}