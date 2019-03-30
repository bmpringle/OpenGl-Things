#include "RegularPolygon.h"
#include <math.h>
#include "CircleShape.h"
#include "BoundingBox2D.h"
#include "Rect.h"

CircleShape::CircleShape(int xCenter, int yCenter, float radius) : p(10, 10, 10)
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

std::vector<float> CircleShape::returnVertexArray()
{
    return p.returnVertexArray();
}

bool CircleShape::compareWith(std::vector<float> v)
{
        BoundingBox2D a(v);
        BoundingBox2D b(returnVertexArray());
        
        return a.isCollision(b);
}
