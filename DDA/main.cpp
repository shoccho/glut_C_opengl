#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#include<bits/stdc++.h>

//glut fonts
const int font8x15=(int)GLUT_BITMAP_8_BY_13;
const int font9x15=(int)GLUT_BITMAP_9_BY_15;
const int fontTimes10=(int)GLUT_BITMAP_TIMES_ROMAN_10;
const int fontTimes24=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int fontHelvatica10=(int)GLUT_BITMAP_HELVETICA_10;
const int fontHelvatica12=(int)GLUT_BITMAP_HELVETICA_12;
const int fontHelvatica18=(int)GLUT_BITMAP_HELVETICA_18;

int orthox=700;
int orthoy=700;
int orthoz=700;

std::vector<int>xpoints;
std::vector<int>ypoints;

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

void showgrid()
{
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
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_POINTS);
    for(int i=0; i<xpoints.size(); i++)
    {
        glVertex2d(xpoints[i],ypoints[i]);
    }
    //showgrid();
    glEnd();
    glFlush();
}
int mkp(float x)
{
    if(int(x*10)%10 <5)return floor(x);
    return ceil(x);
}
void dda(double m, float sx,float sy, float ex,float ey)
{
    float x, y;
    float dx,dy;
    x= sx;
    y= sy;

    if( m <= 1)
    {
        dx = 1;
        dy = m;

    }
    else if( m > 1)
    {
        dy = 1;
        dx = 1/m;
    }
    if (sx > ex)
    {
        dx = -1*dx;
        dy = -1*dy;
    }
    //print("m={0:.2f} Dx = {1:.2f} Dy = {2:.2f} ".format(m,dx,dy))
    //print("x\ty\t\tx plot\ty plot\t\t(x, y)")

    while(1)
    {
        int px=mkp(x);
        int py=mkp(y);

        xpoints.push_back(px);
        ypoints.push_back(py);
       // print("{0}\t{1:.2f}\t\t{2}\t{3}\t\t({2}, {3})".format(x,y,px,py));
        x += dx;
        y += dy;
        if (px==ex && py==ey)break;
    }
    return;
}

int main()
{
    float sx=0,sy=0,ex=100,ey=100;
    double m =((ey-sy)/(ex-sx));
    dda(m,sx,sy,ex,ey);
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
