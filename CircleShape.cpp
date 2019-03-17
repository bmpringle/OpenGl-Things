#include "RegularPolygon.h"
#include <math.h>
#include "CircleShape.h"

CircleShape::CircleShape(float radius, int xCenter, int yCenter) : p(10, 10, 10)
{
    xCenterI = xCenter;
    yCenterI = yCenter;
    radiusI = radius;
    
    RegularPolygon temporaryP(radiusI, xCenterI, yCenterI);
    p = temporaryP;
    setColor(0, 0, 0);
}

void CircleShape::setColor(int r, int g, int b)
{
    p.setPolygonColor(r, g, b);
}

void CircleShape::drawCircle()
{
    p.DrawPolygon();
}