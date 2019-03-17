#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "Rect.h"
#include "WindowVars.h"
#include "RegularPolygon.h"
#include "CircleShape.h"

int drawMode = 4;
WindowVars gWindowVars(0, 0);

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
            r.setVertexColor(35, 175, 230, 1);
            r.setVertexColor(125, 185, 135, 2);
            r.setVertexColor(50, 50, 50, 3);
            r.setVertexColor(150, 90, 75, 4);
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
            CircleShape c(160, 700, 700);
            c.setColor(2, 99, 255);
            c.drawCircle();
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

