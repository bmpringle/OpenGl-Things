
#include "RegularPolygon.h"
#include <math.h>

RegularPolygon::RegularPolygon(int sides, int sideLength, int centerX, int centerY)
{
    sidesI=sides;
    radius = sideLength/(2*sin(180/sides));
    degs = 360/sides;
    rads=degs*M_PI/180;

    for(int i=0; i<sides; ++i)
    {
        GLo.addVertex3f(centerX+radius*cos(rads*(i+1)), centerY+radius*sin(rads*(i+1)), 0, false);
    }
    
    for(int i=0; i<sides; ++i)
    {
        GLo.addColor3f(1, 1, 1);
    }
    
    
}

void RegularPolygon::DrawPolygon()
{
    GLo.DrawObject(0, sidesI, GL_POLYGON);
}

void RegularPolygon::setVertexColor(GLfloat red, GLfloat green, GLfloat blue, int vertex)
{
    GLfloat r = red/255;
    GLfloat g = green/255;
    GLfloat b = blue/255;
    std::vector<float> oldColorArray = GLo.returnColorArray();
    GLo.colorArrayClean();    
    
    for(int i=0; i<sidesI ;++i)
    {
        if(i==vertex-1)
        {
            GLo.addColor3f(r, g, b);
        }else{
            GLo.addColor3f(oldColorArray.at(3*i), oldColorArray.at(3*i+1), oldColorArray.at(3*i+2));  
        }
    }
}

void RegularPolygon::setPolygonColor(GLfloat red, GLfloat green, GLfloat blue)
{
    GLfloat r = red/255;
    GLfloat g = green/255;
    GLfloat b = blue/255;
    int Polynum = GLo.returnColorArray().size();
    GLo.colorArrayClean();
    for(int i=0; i<Polynum;++i)
    {      
        GLo.addColor3f(r, g, b);
      
    }
}
