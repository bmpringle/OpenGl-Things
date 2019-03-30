#include "MacOs/MacOsPlatform.h"
#include "CircleShape.h"
#include "GlObjectList.h"
#include "Rect.h"
#include "RegularPolygon.h"
#include "BoundingBox2D.h"
#include <vector>

#ifndef WINDOWVARS_H
#define WINDOWVARS_H

class WindowVars{
public:
    WindowVars(int x, int y);
    void setScreenRefVar(int x, int y);
    int getScreenRefVarX();
    int getScreenRefVarY();
private:
    int xScreen;
    int yScreen;
};

extern WindowVars gWindowVars;

#endif /* WINDOWVARS_H */

