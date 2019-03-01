#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "Rect.h"

void Rect::FillRect(float normX, float normY, float nWidth, float nHeight, std::vector<float> vert1, std::vector<float> vert2, std::vector<float> vert3, std::vector<float> vert4)
{
    //Draw Object
    ObjectDrawList g;
    
    //Store Vertices
    g.addVertex3f(normX, normY, 0, false);
    g.addVertex3f(normX+nWidth, normY, 0, false);
    g.addVertex3f(normX+nWidth, normY+nHeight, 0, false);
    g.addVertex3f(normX, normY+nHeight, 0, false);  
    //Store Colors
    g.addColor3f(vert1.at(0), vert1.at(1), vert1.at(2));
    g.addColor3f(vert2.at(0), vert2.at(1), vert2.at(2));
    g.addColor3f(vert3.at(0), vert3.at(1), vert3.at(2));
    g.addColor3f(vert4.at(0), vert4.at(1), vert4.at(2));
    
    //Draw
    g.DrawObject(0, 4, GL_POLYGON);   
}

void Rect::FillRect(float normX, float normY, float nWidth, float nHeight, ObjectDrawList colors)
{
    std::vector<float> colorsF = colors.returnColorArray();
    
    //Draw Object
    ObjectDrawList g;
    
    //Store Vertices
    g.addVertex3f(normX, normY, 0, false);
    g.addVertex3f(normX+nWidth, normY, 0, false);
    g.addVertex3f(normX+nWidth, normY+nHeight, 0, false);
    g.addVertex3f(normX, normY+nHeight, 0, false);  
    //Store Colors
    g.addColor3f(colorsF.at(0), colorsF.at(1), colorsF.at(2));
    g.addColor3f(colorsF.at(3), colorsF.at(4), colorsF.at(5));
    g.addColor3f(colorsF.at(6), colorsF.at(7), colorsF.at(8));
    g.addColor3f(colorsF.at(9), colorsF.at(10), colorsF.at(11));
    
    //Draw
    g.DrawObject(0, 4, GL_POLYGON);   
}
