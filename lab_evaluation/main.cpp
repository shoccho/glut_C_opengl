#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;
static float translate_x = 0.0;
static float translate_y = 0.0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(0.0, 1.0, 0.0);
    glRectf(-70.0, 15.0, -40.0, -15.0);
    glRectf(70.0, 15.0, 40.0, -15.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-40.0, -10.0, -25, 10.0);
    glRectf(40.0, -10.0, 25, 10.0);
    glTranslatef(translate_x, translate_y, 0);

    glPopMatrix();

    glColor3f(0.0, 1.0, 0.0);
    glRectf(-10.0, -25.0, 10.0, -70.0);
    glColor3f(0.0, .9, 1);
    glRectf(-20.0, -70.0, 20.0, -100.0);

    glFlush();
}

void spinDisplay_left(void)
{
    spin = spin + 1;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void spinDisplay_right(void)
{
    spin = spin - 1;
    if (spin > 360.0)
        spin = spin - 360.0;
    glutPostRedisplay();
}

void init(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

void my_keyboard(unsigned char key, int x, int y)
{

    if (key == 'l')
    {
        spinDisplay_left();
    }
    else if (key == 'r')
    {
        spinDisplay_right();
    }
    else if (key == 's')
    {
        glutIdleFunc(NULL);
    }
}

void spe_key(int key, int x, int y)
{

    if (key == GLUT_KEY_LEFT)
        spinDisplay_left();
    else if (key == GLUT_KEY_RIGHT)
        spinDisplay_right();
}

void my_mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
    }

    else if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_right);
    }
}
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("lab evaluation");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);
    glutSpecialFunc(spe_key);
    glutMouseFunc(my_mouse);
    glutMainLoop();
    return 0;
}
