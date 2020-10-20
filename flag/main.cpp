
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define twicePi 6.28318

void drawFilledelipse(GLfloat x, GLfloat y, GLfloat xcenter, GLfloat ycenter)
{

    int triangleAmount = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + ((xcenter)*cos(i * twicePi / triangleAmount)),
            y + ((ycenter)*sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-10, 10, -10, 10, -10, 10);
}
static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2d(5, 3);
    glVertex2d(5, -3);
    glVertex2d(-5, -3);
    glVertex2d(-5, 3);
    glEnd();
    glColor3f(1.0f, 0.0f, 0.0f);
    drawFilledelipse(-1, 0, 2, 2);
    glFlush();
}
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("BD flag");

    init();
    glutDisplayFunc(display);
    //glClearColor(1,1,1,1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
