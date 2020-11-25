#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static GLfloat spin = 0.0;
static float translate_x = 0.0;
static float translate_y = 0.0;
int scl = 10;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    //draw center
    glPushMatrix();
    glTranslatef(translate_x, translate_y, 0);
    for (int rot = 0; rot <= 360; rot += 90)
    {
        glRotated(rot, 0, 0, 1);
        glColor3b(0, 0, 0);
        glRectf(30, 30, 40, 40);
    }
    glPopMatrix();
    glColor3f(1, 1, 1);
    glRectf(-30, -30, 30, 30);
    glColor3f(0, 0, 0);
    glRectf(-23, -23, 23, 23);
    glColor3f(1, 1, 1);
    glRectf(-12, -12, 12, 12);

    glPopMatrix();

    //flag for white or black
    bool w = false;
    //draw corners

    for (int rot = 0; rot <= 360; rot += 90)
    {
        glRotated(rot, 0, 0, 1);
        for (int pos = 50; pos <= 100; pos += scl, w = !w)
        {
            if (w)
                glColor3f(1, 1, 1);
            else
                glColor3f(0, 0, 0);

            glRectf(pos, pos, pos + scl, pos + scl);
        }
    }

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
    glClearColor(0.0980, 0.36862, 0.51372, 0.0);
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
