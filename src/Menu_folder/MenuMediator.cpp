#include "../include/Menu_folder/MenuMediator.h"

MenuMediator::MenuMediator() : _manualMenuMode(&_menuOnLCD),
                               _autopilotMenuMode(&_menuOnLCD),
                               _lockedMenuMode(&_menuOnLCD),
                               _pToggleKey(ToggleWithKey::getInstance())

{
    _pMenuMode = &_lockedMenuMode;
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
    _pMenuMode->initLCD();
    _pMenuMode = &_lockedMenuMode;
}
void MenuMediator::doMenu()
{
    _setTargetMode(_pToggleKey->getMode());

    if (_targetMode != _currentMode)
    {
        _setCurrentMode(_targetMode);
        if (_currentMode == "MANUAL")
        {
            _pMenuMode = &_manualMenuMode;
        }
        if (_currentMode == "AUTOPILOT")
        {
            _pMenuMode = &_autopilotMenuMode;
        }
        if (_currentMode == "LOCKED")
        {
            _pMenuMode = &_lockedMenuMode;
        }
        _pMenuMode->printConstPartOfMode();
    }
    if (_pMenuMode != NULL)
    {
        _pMenuMode->doMenu();
    }
}