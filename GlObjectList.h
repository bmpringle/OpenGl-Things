#include <vector>
#include "MacOs/MacOsPlatform.h"
#ifndef GLOBJECTLIST_H
#define GLOBJECTLIST_H

#ifdef __cplusplus



class ObjectDrawList {
public:
    ObjectDrawList();
    void addVertex3f(float x, float y, float z, GLfloat normalizedR, GLfloat noramlizedG, GLfloat normalizedB, bool addMarker);
    std::vector<float> returnObjectList();
    void addVertexShape(std::vector<float> shape);   
    void DrawObject(int start, int end, GLenum DrawType);   
private:
    std::vector<float> _verticesArray;
    std::vector<GLfloat> _colorArray;
    std::vector<int> _stopstartPolys;
    int _member;

};

#endif

#endif 

