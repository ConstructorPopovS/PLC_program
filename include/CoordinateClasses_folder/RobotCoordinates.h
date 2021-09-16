#ifndef ROBOTCOORDINATES_H
#define ROBOTCOORDINATES_H
#include "../src/main.h"

class RobotCoordinates //TODO make the parrents class for FurnaseCoordinates and RobotCoordinates
{

public:
    RobotCoordinates(int x, int y, int fi, int v);
    void setCoordinates(int x, int y, int fi, int v);
    void setX(int x);
    void setY(int y);
    void setFi(int fi);
    void setV(int v);
    int getX();
    int getY();
    int getFi();
    int getV();
    int *getRX();
    int *getRY();
    int *getRFi();
    int *getRV();

private:
    struct RobotCoord
    {
        int x = 100;
        int y = 0;
        int fi = 0;
        int v = 10;
    };
    RobotCoord _coordinate;
};
#endif