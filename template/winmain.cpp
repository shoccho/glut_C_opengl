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

int orthox=10;
int orthoy=10;
int orthoz=10;

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
    glOrtho(-orthox,orthox,-orthoy,orthoy,-orthoz,orthoz);
}
void showgrid(){
    glBegin(GL_LINES);
    glColor3f(.5f,.5f,.5f);
    for (int i=-orthoy; i<=orthoy; i++)
    {
        glVertex2d(orthox,i);
        glVertex2d(-orthox,i);

    }
    for (int i=-orthox; i<=orthox; i++)
    {
        glVertex2d(i,orthoy);
        glVertex2d(i,-orthoy);

    }
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2d(-orthox,0);
    glVertex2d(orthox,0);
    glVertex2d(0,orthoy);
    glVertex2d(0,-orthoy);
    glEnd();
}

static void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT );
    //showgrid();
    glFlush();
}

int main()
{

    glutInitWindowSize(700,700);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Template");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    glutMainLoop();

    return EXIT_SUCCESS;
}
