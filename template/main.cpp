#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>


//glut fonts
const int font8x15=(int)GLUT_BITMAP_8_BY_13;
const int font9x15=(int)GLUT_BITMAP_9_BY_15;
const int fontTimes10=(int)GLUT_BITMAP_TIMES_ROMAN_10;
const int fontTimes24=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int fontHelvatica10=(int)GLUT_BITMAP_HELVETICA_10;
const int fontHelvatica12=(int)GLUT_BITMAP_HELVETICA_12;
const int fontHelvatica18=(int)GLUT_BITMAP_HELVETICA_18;



static void idle(void)
{
    glutPostRedisplay();
}


void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++)
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

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-10,10,-10,10,-10,10);
}

static void display(void)
{

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2d(5,2);
    glVertex2d(5,-5);
    glVertex2d(-5,-5);
    glVertex2d(-5,2);
    glEnd();
    glFlush();
}

int main()
{

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Template");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc();
    glutMainLoop();

    return EXIT_SUCCESS;
}
