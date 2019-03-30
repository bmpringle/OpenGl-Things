#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "Rect.h"
#include "WindowVars.h"
#include "RegularPolygon.h"
#include "CircleShape.h"
#include <thread>
#include <chrono>
#include <vector>
#include "BaseObject.h"

int drawMode = 3;
int fps = 30;
WindowVars gWindowVars(0, 0);
std::vector<CircleShape> circleShapes;

void setScreenVar(int x, int y)
{
    gWindowVars.setScreenRefVar(x, y);
}

void init(int argc, char **argv)
{
    
    int w = 1920;
    int h = 1155;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(w, h);
    setScreenVar(w, h);
    glutInitWindowPosition(0,0);
    glutCreateWindow(argv[0]/*name here*/);  
}

void GLDrawing(int drawWhat)
{
    //Uses my object drawing
    switch(drawWhat)
    {
        case 1:
        {
            Rect r;
    
            r.FillRect(100, 200, 300, 400);
            r.setVertexColor(255, 35, 0, 1);
            r.setVertexColor(123, 200, 12, 2);
            r.setVertexColor(255, 20, 147, 3);
            r.setVertexColor(255, 0, 255, 4);
            r.drawRect();
        }
        break;
        
        case 2:
        {
            Rect r;
            
            r.FillRect(100, 200, 300, 400);
            r.setRectColor(180, 21, 150);
            r.drawRect();  
        }
        break;
        case 3:
        {
            RegularPolygon p(10, 500, 350, 350);     
            RegularPolygon p1(5, 50, 800, 500);
            p1.setPolygonColor(100, 253, 200);
            p.setVertexColor(163, 22, 192, 1);
            p.setVertexColor(33, 205, 254, 2);            
            p.setVertexColor(192, 133, 126, 3);
            p.setVertexColor(199, 144, 133, 4);            
            p.DrawPolygon();
            p1.DrawPolygon();
        }
        break;
        case 4:
        {
            CircleShape c(500, 1000, 300);
            c.setColor(2, 99, 255);
            c.drawCircle();
            CircleShape c1(500, 500, 300);
            c1.setColor(2, 255, 1);
            c1.drawCircle(); 
            circleShapes.push_back(c);
            circleShapes.push_back(c1);
            std::cout << c.compareWith(c1.returnVertexArray()); 
            
            
            RegularPolygon p(3, 200, 900, 600);
            RegularPolygon p1(10, 100, 100, 600);
            p.setPolygonColor(255, 255, 255);
            p1.setPolygonColor(255, 100, 0);
            p.DrawPolygon();
            p1.DrawPolygon();
        }
        
    }  
}

void display()
{
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);    
    glOrtho(0, gWindowVars.getScreenRefVarX(), 0, gWindowVars.getScreenRefVarY(), -1, 1);
    GLDrawing(drawMode);
    glFlush();
}

void reshape(int width, int height)
{   
    setScreenVar(width, height);
    GLDrawing(drawMode);
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

/*
 * Main Loop 
 */
int main(int argc, char **argv)
{
   init(argc, argv);
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
       
   return 0;
}

