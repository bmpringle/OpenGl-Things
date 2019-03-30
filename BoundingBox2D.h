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
};

#endif 

