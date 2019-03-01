#include <vector>
#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#ifndef RECT_H
#define RECT_H

#ifdef __cplusplus



class Rect:ObjectDrawList {
public:  
   void FillRect(float normX, float normY, float nWidth, float nHeight, std::vector<float> vert1, std::vector<float> vert2, std::vector<float> vert3, std::vector<float> vert4);
   void FillRect(float normX, float normY, float nWidth, float nHeight, ObjectDrawList colors);

private:
};

#endif

#endif




