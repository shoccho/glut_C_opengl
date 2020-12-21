#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#include<stdio.h>
float posx=0;
float posy=0;
float dx=.2;
float dy=.2;
void moveobj()
{
    if(posx+dx>=50 ||posx+dx<=-50)
    {
        dx*=-1;
    }

    if(posy+dy>50 ||posy+dy<=-50)
    {
        dy*=-1;
    }
    posx+=dx;
    posy+=dy;

}
static void idle(void)
{
    moveobj();
    glutPostRedisplay();
}

void init()
{

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-50,50,-50,50,-50,50);
}
static void display(void)
{
    printf("%f %f\n",posx,posy);
    glClear(GL_COLOR_BUFFER_BIT );
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2d(posx+1,posy+1);
    glVertex2d(posx+1,posy-1);
    glVertex2d(posx-1,posy-1);
    glVertex2d(posx-1,posy+1);
    glEnd();
    glFlush();
}

static void key(unsigned char key, int x, int y)
{

    if(key== 'w')
    {
        posy++;
    }

    if(key== 'a')
    {
        posx--;
    }

    if(key== 's')
    {
        posy--;
    }
    if(key== 'd')
    {
        posx++;
    }


    glutPostRedisplay();

    glFlush();
}

int main()
{

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Moving obj");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutMainLoop();
    return EXIT_SUCCESS;
}
