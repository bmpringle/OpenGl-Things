#include "MacOs/MacOsPlatform.h"
#include "GlObjectList.h"

void init(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 600);
    glutInitWindowPosition(50,50);
    glutCreateWindow(argv[0]/*name here*/);  
}

void GLDrawing()
{
    //Uses my object drawing
    ObjectDrawList g;
    g.addVertex3f(0.25, 0.25, 0, 1.0, 1.0, 1.0, false);
    g.addVertex3f(0.75, 0.25, 0, 1.0, 0.0, 0.0, false);
    g.addVertex3f(0.75, 0.75, 0, 1.0, 0.0, 1.0, false);
    g.addVertex3f(0.25, 0.75, 0, 0.0, 1.0, 1.0, false);  
    g.DrawObject(0, 4, GL_POLYGON);   
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);    
    glOrtho(0, 1, 0, 1, -1, 1);
    GLDrawing();
    glFlush();
}

void reshape(int w, int h)
{  
    GLDrawing();
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
