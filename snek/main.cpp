#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#define twicePi 2*3.14159
#include<bits/stdc++.h>
struct point{
int x,y;
};
std::vector<struct point> snek;
int len=3;
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
struct point fruit;
int dx=0;
int dy=0;

void create_snek(){
    int x=0,y=0;
    snek.clear();
    for(int i=0;i<len;i++){
    //snek = new std::vector<struct point>;
        struct point p;
        p.x=x;
        p.y=y;
        printf("%d %d",i,y);
        snek.push_back(p);
        x-=1;
    }
}
static void idle(void)
{
    int i;

    for(int i=1;i<len && (dx!=0 || dy!=0);i++ ){
        snek[i].x=snek[i-1].x;
        snek[i].y=snek[i-1].y;
    }
    i=0;
    snek[i].x+=dx;
    if(snek[i].x>100 || snek[i].x<-100)snek[i].x*=-1;
    snek[i].y+=dy;
    if(snek[i].y>100 || snek[i].y<-100)snek[i].y*=-1;
    glutPostRedisplay();
}
static void key(unsigned char key, int x, int y)
{   if (key=='p'){
        dx=0;
        dy=0;
    }
    if(key=='d' && dx!=-1){
        dx=1;
        dy=0;
    }
    else if(key=='a' && dx!=1){
        dx=-1;
        dy=0;
    }
    else if(key=='w' && dy!=-1){
        dy=1;
        dx=0;
    }
    else if(key=='s' && dy!=1){
        dy=-1;
        dx=0;
    }
    glutPostRedisplay();
}
void init(){
    create_snek();

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-100,100,-100,100,-100,100);
}

static void display(void){
	glClear(GL_COLOR_BUFFER_BIT );
    glColor3f(1.0f,0.0f,0.0f);


    for(int i=0;i<len;i++ ){
        glBegin(GL_QUADS);
        printf("%d\n",dx);
            glVertex2d(snek[i].x+.5,snek[i].y+.5);
            glVertex2d(snek[i].x+.5,snek[i].y-.5);
            glVertex2d(snek[i].x-.5,snek[i].y-.5);
            glVertex2d(snek[i].x-.5,snek[i].y+.5);
        glEnd();
    }
        glColor3f(1.0f,0.0f,1.0f);

        glBegin(GL_QUADS);
            glVertex2d(fruit.x+.5,fruit.y+.5);
            glVertex2d(fruit.x+.5,fruit.y-.5);
            glVertex2d(fruit.x-.5,fruit.y-.5);
            glVertex2d(fruit.x-.5,fruit.y+.5);
        glEnd();


    glFlush();
}


int main(){
    fruit.x=10;
    fruit.y=10;

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Snek");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    glutMainLoop();

    return EXIT_SUCCESS;
}
