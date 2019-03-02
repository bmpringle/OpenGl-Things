#include <vector>
#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#ifndef RECT_H
#define RECT_H

#ifdef __cplusplus



class Rect:GLObjectList {
public:  
    //Vertexes are enumerated starting at lower-left and moving counter-clockwise when adding Colors. So Lower-Left is 1, LowerRight is 2, Upper Right is 3, and Upper Left is 4.
   void FillRect(float normX, float normY, float nWidth, float nHeight, std::vector<float> vert1, std::vector<float> vert2, std::vector<float> vert3, std::vector<float> vert4);
   void FillRect(float normX, float normY, float nWidth, float nHeight, GLObjectList colors);
   void FillRect(float normX, float normY, float nWidth, float nHeight);
   void drawRect();
   void changeVertexColor(GLfloat red, GLfloat green, GLfloat blue, int vertex);
private:
    //Draw Object
    GLObjectList g;
};

#endif

#endif