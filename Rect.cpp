#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "Rect.h"
#include "WindowVars.h"

void Rect::FillRect(float normX, float normY, float nWidth, float nHeight, std::vector<float> vert1, std::vector<float> vert2, std::vector<float> vert3, std::vector<float> vert4)
{  
    //Store Vertices
    GLo.addVertex3f(normX, normY, 0, false);
    GLo.addVertex3f(normX+nWidth, normY, 0, false);
    GLo.addVertex3f(normX+nWidth, normY+nHeight, 0, false);
    GLo.addVertex3f(normX, normY+nHeight, 0, false);  
    //Store Colors
    GLo.addColor3f(vert1.at(0), vert1.at(1), vert1.at(2));
    GLo.addColor3f(vert2.at(0), vert2.at(1), vert2.at(2));
    GLo.addColor3f(vert3.at(0), vert3.at(1), vert3.at(2));
    GLo.addColor3f(vert4.at(0), vert4.at(1), vert4.at(2)); 
}

void Rect::FillRect(float normX, float normY, float nWidth, float nHeight, GLObjectList colors)
{
    std::vector<float> colorsF = colors.returnColorArray();
    
    //Store Vertices
    GLo.addVertex3f(normX, normY, 0, false);
    GLo.addVertex3f(normX+nWidth, normY, 0, false);
    GLo.addVertex3f(normX+nWidth, normY+nHeight, 0, false);
    GLo.addVertex3f(normX, normY+nHeight, 0, false);  
    //Store Colors
    GLo.addColor3f(colorsF.at(0), colorsF.at(1), colorsF.at(2));
    GLo.addColor3f(colorsF.at(3), colorsF.at(4), colorsF.at(5));
    GLo.addColor3f(colorsF.at(6), colorsF.at(7), colorsF.at(8));
    GLo.addColor3f(colorsF.at(9), colorsF.at(10), colorsF.at(11)); 
}

void Rect::FillRect(float x, float y, float Width, float Height)
{    
    GLo.vertexArrayClean();
    //Store Vertices
    GLo.addVertex3f(x, y, 0, false);
    GLo.addVertex3f(x+Width, y, 0, false);
    GLo.addVertex3f(x+Width, y+Height, 0, false);
    GLo.addVertex3f(x, y+Height, 0, false);  
    //Store Colors
    GLo.addColor3f(1, 1, 1);
    GLo.addColor3f(1, 1, 1);
    GLo.addColor3f(1, 1, 1);
    GLo.addColor3f(1, 1, 1); 
}

void Rect::setVertexColor(GLfloat red, GLfloat green, GLfloat blue, int vertex)
{
    GLfloat r = red/255;
    GLfloat g = green/255;
    GLfloat b = blue/255;
    std::vector<float> oldColorArray = GLo.returnColorArray();
    GLo.colorArrayClean();
    switch(vertex)
    {
        case 1:
            GLo.addColor3f(r, g, b);
            GLo.addColor3f(oldColorArray.at(3), oldColorArray.at(4), oldColorArray.at(5));
            GLo.addColor3f(oldColorArray.at(6), oldColorArray.at(7), oldColorArray.at(8));
            GLo.addColor3f(oldColorArray.at(9), oldColorArray.at(10), oldColorArray.at(11));
        break;
        case 2:
            GLo.addColor3f(oldColorArray.at(0), oldColorArray.at(1), oldColorArray.at(2));
            GLo.addColor3f(r, g, b);
            GLo.addColor3f(oldColorArray.at(6), oldColorArray.at(7), oldColorArray.at(8));
            GLo.addColor3f(oldColorArray.at(9), oldColorArray.at(10), oldColorArray.at(11));
        break;
        case 3:
            std::cout << "hi" << std::endl;
            GLo.addColor3f(oldColorArray.at(0), oldColorArray.at(1), oldColorArray.at(2));
            GLo.addColor3f(oldColorArray.at(3), oldColorArray.at(4), oldColorArray.at(5));
            GLo.addColor3f(r, g, b);
            GLo.addColor3f(oldColorArray.at(9), oldColorArray.at(10), oldColorArray.at(11));
        break;
        case 4:
            GLo.addColor3f(oldColorArray.at(0), oldColorArray.at(1), oldColorArray.at(2));
            GLo.addColor3f(oldColorArray.at(3), oldColorArray.at(4), oldColorArray.at(5));
            GLo.addColor3f(oldColorArray.at(6), oldColorArray.at(7), oldColorArray.at(8));
            GLo.addColor3f(r, g, b);
        break;      
    }
}

void Rect::setRectColor(GLfloat red, GLfloat green, GLfloat blue)
{
    GLfloat r = red/255;
    GLfloat g = green/255;
    GLfloat b = blue/255;
    GLo.colorArrayClean();
    GLo.addColor3f(r, g, b);
    GLo.addColor3f(r, g, b);
    GLo.addColor3f(r, g, b);
    GLo.addColor3f(r, g, b);
}
    
void Rect::drawRect()
{
    //Draw
    GLo.DrawObject(0, 4, GL_POLYGON);  
}

