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

    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glOrtho(-12,12,-12,12,-12,12);
}

static void display(void)
{

    glColor3f(1.0f,0.27f,0.0f);
      glBegin(GL_QUADS);
        glVertex3d(3.0,5.0,0.0);
        glVertex3d(5.0,2.0,0.0);
        glVertex3d(-5.0,2.0,0.0);
        glVertex3f(-3.0,5.0,0.0);
    glEnd();
    glRectf(-3,5,3,9);
    glColor3f(0,0,0);
    glBegin(GL_LINES);

        glVertex3d(-3.0,4.0,0.0);
        glVertex3d(3.0,4.0,0.0);
        glVertex3d(-3.5,3.0,0.0);
        glVertex3d(3.5,3.0,0.0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex3d(1.5,7.5,0.0);
        glVertex3d(1.5,6.5,0.0);
        glVertex3d(-2.5,6.5,0.0);
        glVertex3d(-2.5,7.5,0.0);
    glEnd();
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLES);
        glVertex3d(0,7,0.0);
        glVertex3d(2.5,8,0.0);
        glVertex3d(2.5,6,0.0);

    glEnd();
    glFlush();
}

int main()
{

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("lab class");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    glutMainLoop();

    return EXIT_SUCCESS;
}
