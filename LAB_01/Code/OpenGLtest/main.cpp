/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
//#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-3,3,-3,3,-3,3);
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
        glVertex3d(2.0,2.0,0.0);
        glVertex3d(2.0,-2.0,0.0);
        glVertex3d(-2.0,-2.0,0.0);
        glVertex3f(-2.0,2.0,0.0);
    glEnd();

    glFlush();
}

int main()
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(200,200);
    glutCreateWindow("DEMO");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
