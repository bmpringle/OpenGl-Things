#include <vector>
#include "MacOs/MacOsPlatform.h"
#ifndef GLOBJECTLIST_H
#define GLOBJECTLIST_H

#ifdef __cplusplus



class GLObjectList {
public:
    void addVertex3f(float x, float y, float z, bool addMarker);
    void addColor3f(GLfloat normalizedR, GLfloat noramlizedG, GLfloat normalizedB);
    std::vector<float> returnVertexArray();
    std::vector<float> returnColorArray();
    void addVertexShape(std::vector<float> shape);   
    void DrawObject(int start, int end, GLenum DrawType);   
    void colorArrayClean();
private:
    std::vector<float> _verticesArray;
    std::vector<GLfloat> _colorArray;
    std::vector<int> _stopstartPolys;
    int _member;

};

#endif

#endif 