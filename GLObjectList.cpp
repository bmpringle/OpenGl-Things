#include "GlObjectList.h"
#include <iostream>
#include <vector>
#include "MacOs/MacOsPlatform.h"

void ObjectDrawList::addVertex3f(float x, float y, float z, bool addMarker)
{
    _verticesArray.push_back(x);
    _verticesArray.push_back(y);
    _verticesArray.push_back(z);
    
    if(addMarker)
    {
        _stopstartPolys.push_back(_verticesArray.size());
    }
}

void ObjectDrawList::addColor3f(GLfloat normalizedR, GLfloat noramlizedG, GLfloat normalizedB)
{
    _colorArray.push_back(normalizedR);
    _colorArray.push_back(noramlizedG);
    _colorArray.push_back(normalizedB);
}


void ObjectDrawList::addVertexShape(std::vector<float> shape)
{
    int shapeSize = shape.size();
    for(int i = 0; shapeSize>i ; ++i)
    {
        _verticesArray.push_back(shape.back());
        shape.pop_back();
    }
    _stopstartPolys.push_back(_verticesArray.size());  
}

std::vector<float> ObjectDrawList::returnVertexArray()
{
    return _verticesArray;
}

std::vector<float> ObjectDrawList::returnColorArray()
{
    return _colorArray;
}

void ObjectDrawList::DrawObject(int startI, int endI, GLenum DrawType)
{
    glBegin(DrawType);
    for(int i=0; i<(endI-startI)*3; ++i)
    {
    glColor3f(_colorArray.at(startI+i), _colorArray.at(startI+i+1), _colorArray.at(startI+i+2));
    glVertex3f(_verticesArray.at(startI+i), _verticesArray.at(startI+i+1), _verticesArray.at(startI+i+2));
     ++i;
     ++i;
    }
    glEnd();
}


