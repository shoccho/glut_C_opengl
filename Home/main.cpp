
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void init()
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-10, 10, -10, 10, -10, 10);
}
static void display(void)
{
    int x, y, i, radius = 2;
    x = 4.5, y = 3;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2d(0, 8);
    glVertex2d(7, 2);
    glVertex2d(-7, 2);
    glEnd();
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2d(5, 2);
    glVertex2d(5, -5);
    glVertex2d(-5, -5);
    glVertex2d(-5, 2);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2d(2, 0);
    glVertex2d(2, -5);
    glVertex2d(-2, -5);
    glVertex2d(-2, 0);

    glEnd();

    glFlush();
}

int main()
{

    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("House");

    init();
    glutDisplayFunc(display);
    //glClearColor(1,1,1,1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
