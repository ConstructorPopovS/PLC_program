#ifndef MENUCOORDINATES_H
#define MENUCOORDINATES_H
#include "../../src/main.h"
class MenuCoordinates
{
private:
    String _mode;
public:
    MenuCoordinates();
    void setMode(String mode);
    String getMode();
};

#endif