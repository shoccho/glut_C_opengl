#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
#define twicePi 2*3.14159
bool moving =false;

struct point{
float x,y;
};
std::vector<struct point> snek;
int len=3;
int start_time=time(NULL);
int framecount=0;
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
float dx=0;
float dy=0;

void create_snek(){
    float x=0,y=0;
    snek.clear();
    for(int i=0;i<len;i++){
    //snek = new std::vector<struct point>;
        struct point p;
        p.x=x;
        p.y=y;
        printf("%lf %lf",i,y);
        snek.push_back(p);
        x-=1;
    }
}
static void idle(void)
{
    if(!moving) return;
    int i;
     i=0;
     float px=snek[i].x;
     float py=snek[i].y;
    snek[i].x+=dx;
    if(snek[i].x>50 || snek[i].x<-50)snek[i].x*=-1;
    snek[i].y+=dy;
    if(snek[i].y>50 || snek[i].y<-50)snek[i].y*=-1;


    for(int i=2;i<len ;i++ ){
        snek[i].x=snek[i-1].x;
        snek[i].y=snek[i-1].y;
    }

    if(snek[0].x==fruit.x && snek[0].y==fruit.y){
            len++;
            struct point p;
            p.x=fruit.x;
            p.y=fruit.y;
            snek.push_back(p);
            printf("%d\n",len);

    }
    glutPostRedisplay();
}
static void key(unsigned char key, int x, int y)
{   if (key=='p'){
        moving=!moving;
    }
    else {
        moving = true;
    }
    if(key=='d' && dx!=-.5){
        dx=.5;
        dy=0;

    }
    else if(key=='a' && dx!=.5){
        dx=-.5;
        dy=0;
    }
    else if(key=='w' && dy!=-.5){
        dy=.5;
        dx=0;
    }
    else if(key=='s' && dy!=.5){
        dy=-.5;
        dx=0;
    }
    glutPostRedisplay();
}


static void display(void){

	glClear(GL_COLOR_BUFFER_BIT );
    glColor3f(1.0f,0.0f,0.0f);


    for(int i=0;i<len;i++ ){
        glBegin(GL_QUADS);
        //printf("%d\n",dx);
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
    framecount++;
    int cur_time=time(NULL);
    if(framecount>=10){

        framecount=0;
        while(cur_time-start_time<1){

             cur_time=time(NULL);
        }
        start_time=cur_time;
    }
}
void init(){
    create_snek();

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-50,50,-50,50,-50,50);

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutKeyboardFunc(key);
}

int main(){
    fruit.x=10;
    fruit.y=10;

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Snek");

    init();

    glutMainLoop();

    return EXIT_SUCCESS;
}
