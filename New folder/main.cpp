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
    //  for (int i=-orthoy; i<=orthoy; i++)
    // {
    //     glVertex2d(orthox,i);
    //      glVertex2d(-orthox,i);

    //  }
    // for (int i=-orthox; i<=orthox; i++)
    // {
    //   glVertex2d(i,orthoy);
    //    glVertex2d(i,-orthoy);

    //  }
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

    glEnd();
    showgrid();
    glFlush();
}

void  Bresenham(double m,float sx,float sy, float ex,float ey)
{
    float p = 0;
    float pm=abs(m);


    if (pm<=1)p = 2 * (ey-sy) - (ex-sx);
    else
    {
        p = 2 * (ex-sx) - (ey-sy);
    }
    float nx=sx;
    float ny=sy;
    //print("K\t (Xk, Yk)\t Pk\t (Xk+1,Yk+1)")
    int i=0;

    while(1)
    {
        // std::printf("here");
        xpoints.push_back(nx);
        ypoints.push_back(ny);
        if(abs(nx-ex)<1 && abs(ny-ey)<1) break;
        float xk,yk;
        if (pm<=1)
        {
            if (p<=0 )
            {
                if(sx<ex)xk = nx+1;
                else xk = nx-1;
                yk = ny;
            }
            else
            {
                if(sy<ey)yk = ny+1;
                else yk = ny-1;
                if(sx<ex)xk = nx+1;
                else xk = nx-1;
            }
        }
        else
        {
            if (p<=0 )
            {
                xk = nx;
                if(sy<ey)
                    yk = ny+1;
                else yk=ny+1;
            }
            else
            {
                if(sy<ey)yk = ny+1;
                else yk = ny-1;
                if(sx<ex)xk = nx+1;
                else xk = nx-1;
            }
        }
        //print("{0}\t ({1}, {2})\t {3}\t ({4},{5})".format(i,nx,ny,p,xk,yk))
        if (pm<=1)
        {
            p = p + 2 * (ey-sy) - 2 * (ex-sx) * (yk-ny);
        }
        else
        {
            p = p + 2 * (ey-sy) - 2 * (ex-sx) * (xk-nx);
        }

        nx = xk;
        ny = yk;
        i+=1;
    }

}



int main()
{
    float ex=200,ey=30,sx=80,sy=320;

    double m =((ey-sy)/(ex-sx));
    printf("%lf",m);
    Bresenham(m,sx,sy,ex,ey);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Bresenham");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    glutMainLoop();

    return EXIT_SUCCESS;
}
