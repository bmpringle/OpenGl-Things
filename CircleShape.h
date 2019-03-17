/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CircleShape.h
 * Author: bmp
 *
 * Created on March 16, 2019, 3:53 PM
 */

#ifndef CIRCLESHAPE_H
#define CIRCLESHAPE_H
class CircleShape {
public:
    CircleShape(float radius, int xCenter, int yCenter);
    void setColor(int r, int g, int b);
    void drawCircle();
private:
    RegularPolygon p;
    float radiusI;
    int xCenterI;
    int yCenterI;
};


#endif /* CIRCLESHAPE_H */


