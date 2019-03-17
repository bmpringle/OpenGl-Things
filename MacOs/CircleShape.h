
#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H

class CircleShape {
public:
    CircleShape(float radius, int xCenter, int yCenter);
    void setColor(int r, int g, int b);
    void drawCircle();
private:
    RegularPolygon p;
    int sidesI;
    int sideLengthI;
    int xCenterI;
    int yCenterI;
};

#endif 

