
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

//glut fonts
const int font8x15 = (int)GLUT_BITMAP_8_BY_13;
const int font9x15 = (int)GLUT_BITMAP_9_BY_15;
const int fontTimes10 = (int)GLUT_BITMAP_TIMES_ROMAN_10;
const int fontTimes24 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int fontHelvatica10 = (int)GLUT_BITMAP_HELVETICA_10;
const int fontHelvatica12 = (int)GLUT_BITMAP_HELVETICA_12;
const int fontHelvatica18 = (int)GLUT_BITMAP_HELVETICA_18;

static void idle(void)
{
    glutPostRedisplay();
}

void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
static void key(unsigned char key, int x, int y)
{
    glutPostRedisplay();
}
void init()
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-10, 10, -10, 10, -10, 10);
}
void showgrid()
{
    int ortho = 10;
    glBegin(GL_LINES);
    glColor3f(.5f, .5f, .5f);
    for (int i = -ortho; i <= ortho; i++)
    {
        glVertex2d(ortho, i);
        glVertex2d(-ortho, i);
    }
    for (int i = -ortho; i <= ortho; i++)
    {
        glVertex2d(i, ortho);
        glVertex2d(i, -ortho);
    }
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2d(-ortho, 0);
    glVertex2d(ortho, 0);

    glVertex2d(0, ortho);
    glVertex2d(0, -ortho);

    glEnd();
}
static void display(void)
{

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);

    glVertex3f(1.0f, 4.0f, 0.0f);
    glVertex3f(3.0f, 3.0f, 0.0f);
    glVertex3f(1.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, 2.0f, 0.0f);
    glVertex3f(-3.0f, 3.0f, 0.0f);
    glVertex3f(-1.0f, 4.0f, 0.0f);

    glVertex3f(0.0f, 6.0f, 0.0f);

    glEnd();

    showgrid();
    glColor3f(1.0f, 1.f, 1.0f);
    renderBitmapString(0, 0, (void *)font9x15, "(0,0)");
    renderBitmapString(1, 2, (void *)font9x15, "(1,2)");
    renderBitmapString(3, 3, (void *)font9x15, "(3,3)");
    renderBitmapString(1, 4, (void *)font9x15, "(1,4)");
    glFlush();
}

int main()
{

    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("shuriken");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    glutMainLoop();

    return EXIT_SUCCESS;
}
