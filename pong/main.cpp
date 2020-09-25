#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#define twicePi 2*3.14159

float ballx=0,bally=0,fpy=0,spy=0;
float ball_r=.2;
float dx=.002,dy=0.001;

static void idle(void)
{
    if(ballx+dx > 9.4){
        //printf("%f\n",spy);
       // printf("%f\n",bally);
        if((bally<=spy+1 && bally>=spy-1) )dx*=-1;
    }
    else if(ballx+dx < -9.4){

        if((bally<=fpy+1 && bally>=fpy-1))
            dx*=-1;
    }
    if(dx + ballx >10 || dx + ballx < -10){
        ballx=0;
        bally=0;
        dx*=-1;
        dy*=-1;
        //printf("running");
    }
    if(dy+bally > 10 || dy+bally < -10){
        dy*=-1;
    }
    ballx+=dx;
    bally+=dy;
    glutPostRedisplay();

}
static void key(unsigned char key, int x, int y)
{
    if(key=='w' && fpy <9)fpy++;
    if(key=='s' && fpy>-9)fpy--;
    if(key=='i' && spy <9)spy++;
    if(key=='k' && fpy >-9)spy--;

    glutPostRedisplay();
}

void drawFilledelipse(GLfloat x, GLfloat y, GLfloat xcenter,GLfloat ycenter)
{

    int triangleAmount = 20;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(
                x + ((xcenter)* cos(i * twicePi / triangleAmount)),
                y + ((ycenter)* sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}


void init(){

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-10,10,-10,10,-10,10);
}

static void display(void){
    glClear(GL_COLOR_BUFFER_BIT );
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);
        glVertex2d(-9.5,fpy+1);
        glVertex2d(-9.5,fpy-1);
        glVertex2d(-10,fpy-1);
        glVertex2d(-10,fpy+1);
        glVertex2d(10,spy+1);
        glVertex2d(10,spy-1);
        glVertex2d(9.5,spy-1);
        glVertex2d(9.5,spy+1);
    glEnd();
    glColor3f(1.0f,0.0f,0.0f);
    drawFilledelipse(ballx,bally,.2,.2);
    glFlush();
}

int main(){

    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Pong");
    init();
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();

    return EXIT_SUCCESS;
}
