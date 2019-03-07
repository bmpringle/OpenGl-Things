#include <vector>
#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#ifdef __cplusplus

class RegularPolygon:GLObjectList
{
public:
    RegularPolygon(int sides, int sideLength, int centerX, int centerY);
    void DrawPolygon();
    void setVertexColor(GLfloat red, GLfloat green, GLfloat blue, int vertex);
    void setPolygonColor(GLfloat red, GLfloat green, GLfloat blue);
private:
    GLObjectList GLo;
    int radius;
    int sidesI;
    float degs;
    float rads;
};

#endif

#endif

