#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "Rect.h"
#include "WindowVars.h"
#include "RegularPolygon.h"
#include "CircleShape.h"

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

class BoundingBox2D {
public:
    BoundingBox2D(std::vector<float> objectVertexes);
    std::vector<float> returnBoundingBox();
    bool isCollision(BoundingBox2D BoundingObjB);
private:
    int maxXI;
    int maxYI;
    int minXI;
    int minYI;
    //coords for bounding box starting lower left and going counter-clockwise
    std::vector<float> boundingBox;
};

#endif 

