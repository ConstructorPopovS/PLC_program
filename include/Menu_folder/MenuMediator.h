#ifndef MENUMEDIATOR_H
#define MENUMEDIATOR_H
#include "../src/main.h"
#include "../Console_folder/Toggle_folder/ToggleWithKey.h"
#include "ManualMenuMode.h"
#include "AutopilotMenuMode.h"
#include "LockedMenuMode.h"

class MenuMediator
{
private:
    ToggleWithKey _toggleKey;
    MenuMode* _menuMode = NULL;
    ManualMenuMode _manualMenuMode;
    AutopilotMenuMode _autopilotMenuMode;
    LockedMenuMode _lockedMenuMode;

    String _currentMode;
    String _targetMode;
    static const int _numberOfModes = 3;
    String _namesOfModes[_numberOfModes] = {"AUTOPILOT", "NULL", "MANUAL"};

    bool _modeExists(String mode);
    void _setCurrentMode(String mode);
    String _getCurrentMode();
    void _setTargetMode(String mode);
    String _getTargetMode();

public:
    MenuMediator();
    void doMenu();
};

#endif