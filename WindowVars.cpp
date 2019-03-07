#include "WindowVars.h"

WindowVars::WindowVars(int x, int y)
{
    setScreenRefVar(x, y);
}
void WindowVars::setScreenRefVar(int x, int y)
{
    xScreen = x;
    yScreen = y;
}
int WindowVars::getScreenRefVarX()
{
    return xScreen;
}
int WindowVars::getScreenRefVarY()
{
    return yScreen;      
}