#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<iostream>
int   x1, x2, y1, y2, dx, dy;
float ix, iy,step;


void display(void)
{
    dx = (x2-x1);
    dy = (y2-y1);
    float p=0;
    float m = dy*1.0/dx;
    if (m<0)
    {
        printf("I cannot do this !");
        return;
    }
    if (m<=1)p = 2 * (y2-y1) - (x2-x1);
    else
    {
        p = 2 * (x2-x1) - (y2-y1);
    }
    std::cout<<p<<"\n";
    float nx=x1;
    float ny=y1;
    //print("K\t (Xk, Yk)\t Pk\t (Xk+1,Yk+1)")
    int i=0;
 glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    while(1)
    {
        // std::printf("here");
        //xpoints.push_back(nx);
        //ypoints.push_back(ny);
        glVertex2f(nx,ny);
        if(nx==x2 && ny==y2) break;
        float xk,yk;
        if (m<=1)
        {
            if (p<=0 )
            {
                xk = nx+1;
                yk = ny;
            }
            else
            {
                yk = ny+1;
                xk = nx+1;
            }
        }
        else
        {
            if (p<=0 )
            {
                xk = nx;
                yk = ny+1;
            }
            else
            {
                yk = ny+1;
                xk = nx+1;
            }
        }
        //print("{0}\t ({1}, {2})\t {3}\t ({4},{5})".format(i,nx,ny,p,xk,yk))
        if (m<=1)
        {
            p = p + 2 * (y2-y1) - 2 * (x2-x1) * (yk-ny);
        }
        else
        {
            p = p + 2 * (y2-y1) - 2 * (x2-x1) * (xk-nx);
        }
        nx = xk;
        ny = yk;
        i+=1;
        if(i>100)break;
    }
    glEnd();
    glutSwapBuffers();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);   /* select clearing (background) color */
    glMatrixMode(GL_PROJECTION);        /* initialize viewing values */
    glLoadIdentity();
    glOrtho(0.0, 200.0, 0.0, 200.0, -200.0, 200.0);
}


int main(int argc, char** argv)
{
    printf("Please Enter X1 Value: ");
    scanf("%d", &x1);
    printf("Please Enter Y1 Value: ");
    scanf("%d", &y1);
    printf("Please Enter X2 Value: ");
    scanf("%d", &x2);
    printf("Please Enter Y2 Value: ");
    scanf("%d", &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (300, 300);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
