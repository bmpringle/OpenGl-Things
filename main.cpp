#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"
#include "Rect.h"

int drawMode = 1;

void init(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 600);
    glutInitWindowPosition(50,50);
    glutCreateWindow(argv[0]/*name here*/);  
}

void GLDrawing(int drawWhat)
{
    //Uses my object drawing
    switch(drawWhat)
    {
        case 1:
        {
            GLObjectList c;
            Rect r;
    
            //Adding colors
            c.addColor3f(1.0, 1.0, 1.0);
            c.addColor3f(1.0, 0.0, 0.0);
            c.addColor3f(1.0, 0.0, 1.0);
            c.addColor3f(0.0, 1.0, 0.0);
    
            //Draw
            r.FillRect(0.25, 0.25, 0.5, 0.5, c);
            r.drawRect();
        }
        break;
        
        case 2:
        {
            Rect r;
    
            std::vector<float> vert1;
            std::vector<float> vert2;
            std::vector<float> vert3;
            std::vector<float> vert4;
            vert1.push_back(1.0);
            vert1.push_back(1.0);
            vert1.push_back(1.0);
            vert2.push_back(1.0);
            vert2.push_back(0.0);
            vert2.push_back(0.0);
            vert3.push_back(1.0);
            vert3.push_back(0.0);
            vert3.push_back(1.0);
            vert4.push_back(0.0);
            vert4.push_back(1.0);
            vert4.push_back(0.0);

            r.FillRect(0.25, 0.25, 0.5, 0.5, vert1, vert2, vert3, vert4);
            r.drawRect();
        }
        break;
        case 3:
        {
            Rect r;
    
            r.FillRect(0.25, 0.25, 0.5, 0.5);
            r.changeVertexColor(0.25, 0.75, 0.4, 1);
            r.drawRect();
        }
        break;
        
    }
    
    
    
    
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);    
    glOrtho(0, 1, 0, 1, -1, 1);
    GLDrawing(drawMode);
    glFlush();
}

void reshape(int w, int h)
{  
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