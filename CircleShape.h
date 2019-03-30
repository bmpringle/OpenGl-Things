#include "Rect.h"
#include "RegularPolygon.h"
#include "BaseObject.h"
#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H
class CircleShape:BaseObject {
public:
    CircleShape(int xCenter, int yCenter, float radius);
    void setColor(int r, int g, int b);
    void drawCircle();
    std::vector<float> returnVertexArray();
    bool compareWith(std::vector<float> v);
private:
    RegularPolygon p;
    float radiusI;
    int xCenterI;
    int yCenterI;
};


#endif /* CIRCLESHAPE_H */


