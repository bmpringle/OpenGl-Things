#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "Rect.h"
#include "WindowVars.h"
#include "RegularPolygon.h"
#include "CircleShape.h"
#include "BoundingBox2D.h"
#include <math.h>
#include <vector>

BoundingBox2D::BoundingBox2D(std::vector<float> objectVertexes)
{
    float maxX;
    float minX;  
    float maxY;   
    float minY;
    
    for(int i=0; i<(objectVertexes.size()-1)/3; ++i)
    {
        if(i==0)
        {
            maxX = std::max(objectVertexes.at(0), objectVertexes.at(3));
        }else{
            maxX = std::max(maxX, objectVertexes.at(3*(i+1)));
        }
    }
    
    for(int i=0; i<(objectVertexes.size()-1)/3; ++i)
    {
        if(i==0)
        {
            maxY = std::max(objectVertexes.at(1), objectVertexes.at(4));
        }else{
            maxY = std::max(maxX, objectVertexes.at(3*(i+2)));
        }
    }
    
    for(int i=0; i<(objectVertexes.size()-1)/3; ++i)
    {
        if(i==0)
        {
            minX = std::min(objectVertexes.at(0), objectVertexes.at(3));
        }else{
            minX = std::min(maxX, objectVertexes.at(3*(i+1)));
        }
    }
    
    for(int i=0; i<(objectVertexes.size()-1)/3; ++i)
    {
        if(i==0)
        {
            minY = std::min(objectVertexes.at(1), objectVertexes.at(4));
        }else{
            minY = std::min(maxX, objectVertexes.at(3*(i+2)));
        }
    }

    maxXI=maxX;
    maxYI=maxY;
    minXI=minX;
    minYI=minY;
    
    boundingBox.push_back(minX);
    boundingBox.push_back(minY);
    boundingBox.push_back(maxX);
    boundingBox.push_back(minY);
    boundingBox.push_back(maxX);
    boundingBox.push_back(maxY);
    boundingBox.push_back(minX);
    boundingBox.push_back(maxY);
}

std::vector<float> BoundingBox2D::returnBoundingBox()
{
    return boundingBox;
}

bool BoundingBox2D::isCollision(BoundingBox2D BoundingObjB)
{

    
    BoundingBox2D b = BoundingObjB;
    
    //Checking A collision
    
    if(minXI >= b.minXI && minXI <= b.maxXI)
    {
        if(minYI >= b.minYI && minYI <= b.maxYI)
        {
           return true; 
        }
    }
    
    if(maxXI >= b.minXI && maxXI <= b.maxXI)
    {
        if(minYI >= b.minYI && minYI <= b.maxYI)
        {
           return true; 
        }
    }
    
    if(maxXI >= b.minXI && maxXI <= b.maxXI)
    {
        if(maxYI >= b.minYI && maxYI <= b.maxYI)
        {
           return true; 
        }
    }
    
        if(minXI >= b.minXI && minXI <= b.maxXI)
    {
        if(maxYI >= b.minYI && maxYI <= b.maxYI)
        {
           return true; 
        }
    }

    //Checking B collision
    if(b.minXI >= minXI && b.minXI <= maxXI)
    {
        if(b.minYI >= minYI && b.minYI <= maxYI)
        {
           return true; 
        }
    }
    
    if(b.maxXI >= minXI && b.maxXI <= maxXI)
    {
        if(b.minYI >= minYI && b.minYI <= maxYI)
        {
           return true; 
        }
    }
    
    if(b.maxXI >= minXI && b.maxXI <= maxXI)
    {
        if(b.maxYI >= minYI && b.maxYI <= maxYI)
        {
           return true; 
        }
    }
    
        if(b.minXI >= minXI && b.minXI <= maxXI)
    {
        if(b.maxYI >= minYI && b.maxYI <= maxYI)
        {
           return true; 
        }
    }    
    return false;
}