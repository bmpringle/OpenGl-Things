#include <vector>
#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "BoundingBox2D.h"
#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#ifdef __cplusplus

class RegularPolygon:GLObjectList
{
public:
    RegularPolygon(int sides, int sideLength, int centerX, int centerY);
    RegularPolygon(float radius, int centerX, int centerY);
    void DrawPolygon();
    void setVertexColor(GLfloat red, GLfloat green, GLfloat blue, int vertex);
    void setPolygonColor(GLfloat red, GLfloat green, GLfloat blue);
    bool compareWith(std::vector<float> v);
    std::vector<float> returnVertexArray();
private:
    GLObjectList GLo;
    float radius;
    int sidesI;
    float degs;
    float rads;
};

#endif

#endif

