#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "Rect.h"

void Rect::FillRect(float normX, float normY, float nWidth, float nHeight, std::vector<float> vert1, std::vector<float> vert2, std::vector<float> vert3, std::vector<float> vert4)
{  
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
}

void Rect::FillRect(float normX, float normY, float nWidth, float nHeight, GLObjectList colors)
{
    std::vector<float> colorsF = colors.returnColorArray();
    
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
}

void Rect::FillRect(float normX, float normY, float nWidth, float nHeight)
{    
    //Store Vertices
    g.addVertex3f(normX, normY, 0, false);
    g.addVertex3f(normX+nWidth, normY, 0, false);
    g.addVertex3f(normX+nWidth, normY+nHeight, 0, false);
    g.addVertex3f(normX, normY+nHeight, 0, false);  
    //Store Colors
    g.addColor3f(1, 1, 1);
    g.addColor3f(1, 1, 1);
    g.addColor3f(1, 1, 1);
    g.addColor3f(1, 1, 1); 
}

void Rect::changeVertexColor(GLfloat red, GLfloat green, GLfloat blue, int vertex)
{
    std::vector<float> oldColorArray = g.returnColorArray();
    g.colorArrayClean();
    switch(vertex)
    {
        case 1:
            g.addColor3f(red, green, blue);
            g.addColor3f(oldColorArray.at(3), oldColorArray.at(4), oldColorArray.at(5));
            g.addColor3f(oldColorArray.at(6), oldColorArray.at(7), oldColorArray.at(8));
            g.addColor3f(oldColorArray.at(9), oldColorArray.at(10), oldColorArray.at(11));
        break;
        case 2:
            g.addColor3f(oldColorArray.at(0), oldColorArray.at(1), oldColorArray.at(2));
            g.addColor3f(red, green, blue);
            g.addColor3f(oldColorArray.at(6), oldColorArray.at(7), oldColorArray.at(8));
            g.addColor3f(oldColorArray.at(9), oldColorArray.at(10), oldColorArray.at(11));
        break;
        case 3:
            g.addColor3f(oldColorArray.at(0), oldColorArray.at(1), oldColorArray.at(2));
            g.addColor3f(oldColorArray.at(3), oldColorArray.at(4), oldColorArray.at(5));
            g.addColor3f(red, green, blue);
            g.addColor3f(oldColorArray.at(9), oldColorArray.at(10), oldColorArray.at(11));
        break;
        case 4:
            g.addColor3f(oldColorArray.at(0), oldColorArray.at(1), oldColorArray.at(2));
            g.addColor3f(oldColorArray.at(3), oldColorArray.at(4), oldColorArray.at(5));
            g.addColor3f(oldColorArray.at(9), oldColorArray.at(10), oldColorArray.at(11));
            g.addColor3f(red, green, blue);
        break;      
    }
}
    
void Rect::drawRect()
{
    //Draw
    g.DrawObject(0, 4, GL_POLYGON);  
}