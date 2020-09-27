#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#define twicePi 2*3.14159

void drawFilledelipse(GLfloat x, GLfloat y, GLfloat xcenter,GLfloat ycenter)
{

    int triangleAmount = 20;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + ((xcenter)* cos(i * twicePi / triangleAmount)),
            y + ((ycenter)* sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}


static void idle(void)
{
    glutPostRedisplay();
}
static void key(unsigned char key, int x, int y)
{
    glutPostRedisplay();
}
void init()
{


    glOrtho(-100,100,-100,100,-100,100);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    //const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    //const double a = t*90.0;
    glPushMatrix();
    glRotated(60,0,0,0);
    int rows=100;
    int columns=100,i;
    glBegin(GL_LINES);
    /* Horizontal lines. */
    for (i=0; i<=rows; i++)
    {
        glVertex2f(0, i);
        glVertex2f(columns, i);
    }
    /* Vertical lines. */
    for (i=0; i<=columns; i++)
    {
        glVertex2f(i, 0);
        glVertex2f(i, rows);
    }
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

int main()
{

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Terrain");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();

    return EXIT_SUCCESS;
}
