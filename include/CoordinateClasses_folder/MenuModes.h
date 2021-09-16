#ifndef MENUMODES_H
#define MENUMODES_H
#include "../../src/main.h"
class MenuModes
{
private:
    String _mode;

public:
    MenuModes();
    void setMode(String mode);
    String getMode();
};

#endif